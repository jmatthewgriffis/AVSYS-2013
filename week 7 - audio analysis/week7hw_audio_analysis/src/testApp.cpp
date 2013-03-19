#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    soundStream.setup(this, 0, 1, 44100, 256, 4);
    
    sumOfSquares = 0; // Use these to calculate the pitch.
    rootMeanSquare = 0; // Use these to calculate the pitch.
    counter = 0; // This counts how often the amplitude crosses zero (roughly).
    counter2 = 0; // This helps change the color.
    pitch = 0;
    ofSetRectMode(OF_RECTMODE_CENTER);
    rectX = ofGetWidth()/2;
    rectY = ofGetHeight()/2;
    rectW = 100;
    rectH = 100;
    widthChangeTimer = 0; // This controls how frequently the width changes.
    getCrazy = false; // Use this to change mode.
    rectC = 255; // Rect color.
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofBackground(0);
    
    if (getCrazy == true) {
        
        widthChangeTimer ++;
        
        if (widthChangeTimer >= 5) {
            rectW = pitch/4; // Change the width based on the pitch.
            if (pitch >= 1000) {
                rectH = pitch/10; // Change the height based on the pitch.
            }
            widthChangeTimer = 0;
        }
    }
    else {
        rectC = 255;
        rectW = 100;
        rectH = 100;
    }
    
    if (counter2 >= 255) {
        counter2 = 0;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(rectC);
    ofRect(rectX, rectY, rectW, rectH);
    ofSetColor(255); // Set the color back to normal for everything else.
    
    if (getCrazy == false) {
        
        ofDrawBitmapString("Click to get crazy.", 10, ofGetHeight()-20);
    }
    else {
        
        ofDrawBitmapString("Click to get sane.", 10, ofGetHeight()-20);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    getCrazy = !getCrazy;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
    
    // Here we calculate the amplitude (volume) and frequency (pitch):
    sumOfSquares = 0;
    counter = 0;
    
    for (int i = 0; i < bufferSize; i++){
        //cout << input[i] << endl;
        sumOfSquares += powf(input[i], 2); // Add all the squares of the audio data.
        
        if (getCrazy == true) {
            if (widthChangeTimer >= 3) {
                if (pitch < 1000) {
                rectC = (ofMap(input[i]*(0.5)+0.5, 1, 2, 0, 255),255,counter2); // Change the color of the rect based on audio data.
                }
            }
        }
    }
    
    rootMeanSquare = sqrt(sumOfSquares / bufferSize); // This is the magnitude of one sample. I think.
    //cout << rootMeanSquare << endl;
    
    for (int i = 1; i < bufferSize; i++) {
        if ( (input[i] < 0 && input[i-1] > 0) || (input[i] > 0 && input[i-1] < 0)) {
            counter ++; // If the amplitude (volume) crosses zero, add one to the counter.
            counter2 ++; // Ditto.
        }
    }
    pitch = (counter * (44100/bufferSize))/2; // Multiply the number of amplitude zero crossings per sample by the number of samples per second and divide by two since the complete wave crosses zero twice to get...the frequency (pitch)!
    
    for (int i = 0; i < bufferSize; i++){
        cout << "volume (amplitude) = " << input[i] << " | pitch (frequency) = "<< pitch << endl;
    }
}