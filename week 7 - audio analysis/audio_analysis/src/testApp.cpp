#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    soundStream.setup(this, 0, 1, 44100, 256, 4);
    
    sumOfSquares = 0;
    rootMeanSquare = 0;
    counter = 0;
    pitch = 0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

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
    
    sumOfSquares = 0;
    counter = 0;
    
    for (int i = 0; i < bufferSize; i++){
        //cout << input[i] << endl;
        sumOfSquares += powf(input[i], 2);
    }
    
    rootMeanSquare = sqrt(sumOfSquares / bufferSize);
    //cout << rootMeanSquare << endl;
    
    for (int i = 1; i < bufferSize; i++) {
            if ( (input[i] < 0 && input[i-1] > 0) || (input[i] > 0 && input[i-1] < 0)) {
                counter ++;
            }
    }
    pitch = (counter * (44100/bufferSize))/2;
    cout << pitch << endl;
}