#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // This is Zach's GitHub example. I've tweaked and repurposed it (also in the chucK code).
    
    // Set a port to send data to. High numbers are good:
    sender.setup("localhost", 9999);
    
    // Prevent screen tearing:
    ofSetVerticalSync(true);
    
    bouncingBallPos.set(ofGetWidth()/2,ofGetHeight()/2);
    bouncingBallVel.set(ofRandom(-10,10), ofRandom(-10,10));
    
    nextTone = 0;
    counter = 1;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Move the ball:
    bouncingBallPos += bouncingBallVel;
    
    // Set the frequency of the tone we send to OSC (which will be played through chucK):
    // The original correlates the position to pitch but I'm going to do harmony instead:
    if (counter == 1) {
        nextTone = 261.63; // (middle) C
    }
    else if (counter == 2) {
        nextTone = 329.63; // E
    }
    else if (counter == 3) {
        nextTone = 392.00; // G
    }
    else if (counter == 4) {
        nextTone = 466.16; // A#
    }
    else if (counter == 5) {
        nextTone = 523.25; // C up (above middle C)
    }
    else if (counter > 5) {
        counter = 0;
    }
    
    // Make the ball bounce off the edges of the screen and send a message through OSC. I've set it so every time it hits a wall, it increases the counter and plays the next note up of a jazz chord (C-Major 7th I think). When it plays the highest note, the next bounce resets the counter and plays no note, and then the next bounce starts over:
    
    if (bouncingBallPos.x < 0){ // Left edge.
        bouncingBallPos.x = 0;
        bouncingBallVel.x *= -1;
        ofxOscMessage message;
        message.setAddress("/playtone");
        //float tone = ofMap(bouncingBallPos.y, 0, ofGetHeight(), 400, 60);
        if (counter != 0) {
            float tone = nextTone;
            message.addFloatArg( tone );
            
            sender.sendMessage(message);
        }
        counter ++;
    }
    
    if (bouncingBallPos.x > ofGetWidth()){ // Right edge.
        bouncingBallPos.x = ofGetWidth();
        bouncingBallVel.x *= -1;
        ofxOscMessage message;
        message.setAddress("/playtone");
        //float tone = ofMap(bouncingBallPos.y, 0, ofGetHeight(), 400, 60);
        if (counter != 0) {
            float tone = nextTone;
            message.addFloatArg( tone );
            
            sender.sendMessage(message);
        }
        counter ++;
    }
    
    if (bouncingBallPos.y < 0){ // Top edge.
        bouncingBallPos.y = 0;
        bouncingBallVel.y *= -1;
        ofxOscMessage message;
        message.setAddress("/playtone");
        //float tone = ofMap(bouncingBallPos.y, 0, ofGetHeight(), 400, 60);
        if (counter != 0) {
            float tone = nextTone;
            message.addFloatArg( tone );
            
            sender.sendMessage(message);
        }
        counter ++;
    }
    
    if (bouncingBallPos.y > ofGetHeight()){ // Bottom edge.
        bouncingBallPos.y = ofGetHeight();
        bouncingBallVel.y *= -1;
        ofxOscMessage message;
        message.setAddress("/playtone");
        //float tone = ofMap(bouncingBallPos.y, 0, ofGetHeight(), 400, 60);
        if (counter != 0) {
            float tone = nextTone;
            message.addFloatArg( tone );
            
            sender.sendMessage(message);
        }
        counter ++;
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofCircle(bouncingBallPos.x, bouncingBallPos.y, 50);
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