#include "testApp.h"

/* This is an exercise we did in Humor and Code, which I've modified to use for this homework. I also copied Zach's first oscillator example, which I'm similarly modified. */

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(24);
    ofSetWindowShape(1024, 768);
    
    cam.initGrabber(320, 240);
    colorImage.allocate(320, 240);
    grayImage.allocate(320, 240);
    bgImage.allocate(320, 240);
    absDiffImage.allocate(320, 240);
    
    threshold = 55;
    
    stream.setup(this, 2, 0, 44100, 512, 4);
    soundBuffer = new float[512];
    
    
    sinWave.setup(44100);
    sinWave.setFrequency(440);
    sinWave.setVolume(0.7);
    
}

//--------------------------------------------------------------
void testApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        colorImage.setFromPixels( cam.getPixelsRef() );
        colorImage.mirror(false, true); // First is vertical, second is horizontal.
        grayImage = colorImage; // This is operator overload - the equal sign within the grayscaleimage class runs a function to convert the image type.
        absDiffImage.absDiff(bgImage, grayImage);
        absDiffImage.threshold( threshold );
        
        absDiffImage.erode();
        absDiffImage.erode();
        absDiffImage.dilate();
        absDiffImage.dilate();
        
        contourFinder.findContours(absDiffImage, 320*240*0.1, 320*240*0.8, 3, false);
        
        //sinWave.setFrequency( max(1,mouseX) );  // don't want to give a negative frequency...
        
        for(int i=0; i<contourFinder.nBlobs; i++) {
            ofCircle( contourFinder.blobs[i].centroid, 10 );
            sinWave.setFrequency(ofMap(contourFinder.blobs[i].centroid.x, 0, ofGetWidth(), 220.0, 1000.0));
        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    cam.draw(20,20);
    colorImage.draw(360, 20);
    grayImage.draw(700, 20);
    bgImage.draw(20, 290);
    absDiffImage.draw(360,290);
    contourFinder.draw(720,290);
    contourFinder.draw(360,20);
    
    ofSetColor(255, 0, 0);
    for(int i=0; i<contourFinder.nBlobs; i++) {
        ofCircle( contourFinder.blobs[i].centroid, 10 );
    }
    ofSetColor(255);
    
    ofDrawBitmapString("threshold = " + ofToString(threshold), 5, ofGetHeight()-5);
    
    /*
    ofFill();
    ofSetColor(255);
    ofRect(200,200,512, 200);
    
    ofNoFill();
    ofSetColor(0);
    ofBeginShape();
    for (int i = 0; i < 512; i++){
        ofVertex(200 + i, 300 + 100 * soundBuffer[i]);
    }
    ofEndShape();
    
    
    ofDrawBitmapStringHighlight("frequency:  " + ofToString(sinWave.frequency), ofPoint(200,50));
     */
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key==' ') {
        bgImage = grayImage;
    }
    
    if (key==OF_KEY_UP) {
        threshold+=5;
    }
    
    if (key==OF_KEY_DOWN) {
        threshold-=5;
    }
    
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
void testApp::audioOut(float * output, int bufferSize, int nChannels){
    
	for (int i = 0; i < bufferSize; i++){
        
        float sample = sinWave.getSample(); //ofRandom(-1,1);
        
        output[i*nChannels    ] = sample;
        output[i*nChannels + 1] = sample;
        
        soundBuffer[i] = sample;
	}
    
    
}
