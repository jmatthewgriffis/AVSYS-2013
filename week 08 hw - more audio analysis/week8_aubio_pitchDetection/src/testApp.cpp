#include "testApp.h"
#include "stdio.h"

/* This is Zach's first example using Aubio. I believe it was originally labeled "Week6" rather than "Week8." I've modified it. */

//--------------------------------------------------------------
void testApp::setup(){
	
	ofBackground(255,255,255);
    ofSetCircleResolution(60);
    ofSetVerticalSync(true);
	
	// 0 output channels,
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
    AA.setup();
    
	//setup of sound input
	ofSoundStreamSetup(0, 2, this, 44100, 256, 4);
	left = new float[256];
	right = new float[256];
	
	
	
	dinFont.loadFont("DIN.otf", 25);
    
    // I added all the following:
    
    paddleW = 30;
    paddleH = 100;
    paddleX = ofGetWidth()/2-paddleW/2;
    paddleY = ofGetHeight()/2-paddleH/2;
    mappedPitch = 0;
    ballX = ofGetWidth();
    ballY = ofGetHeight()/2;
    ballR = 25;
    ballV = -1;
    collided = false;
    dispMsg = false;
    msgCounter = 0;
    msgX = ofGetWidth()/2;
    msgY = ofGetHeight()/2;
    score = 0;
    
	
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (AA.pitch < 500) {
        mappedPitch = ofMap(AA.pitch, 120, 500, 768, 0);
    }
    else {
        mappedPitch = ofMap(AA.pitch, 500, 2000, 768, 0);
    }
    paddleY = mappedPitch;
    
    ballX += ballV;
    
    if (ballX-ballR < paddleX+paddleW && ballX+ballR > paddleX &&
        ballY-ballR < paddleY+paddleH && ballY+ballR > paddleY) {
        ballV *= -1;
        collided = true;
        if (dispMsg == false) {
            dispMsg = true;
        }
        score++;
    }
    
    if (ballX > ofGetWidth()+ballR || ballX < -ballR) {
        if (collided == false) {
            dispMsg = true;
            score--;
        }
        
        ballY = ofRandom(ballR, ofGetHeight()-ballR);
        if (ofRandom(2) >= 1) {
            ballX = ofGetWidth();
            if (ballV > 0) {
                ballV++;
                ballV *= -1;
            }
            else {
                ballV--;
            }
        }
        else {
            ballX = 0;
            if (ballV > 0) {
                ballV++;
            }
            else {
                ballV--;
                ballV *= -1;
            }
        }
        collided = false;
    }
    
    if (ballV > 10) {
        ballV = 10;
    }
    
    if (dispMsg == true) {
        msgCounter += 1;
    }
    
    if (msgCounter >= 30) {
        dispMsg = false;
        msgCounter = 0;
    }
    
    msgX = paddleX-25;
    msgY = paddleY-10;
    
}


//--------------------------------------------------------------
void testApp::draw(){
	
    ofBackground(0);
    
    ofRect(paddleX, paddleY, paddleW, paddleH);
    ofCircle(ballX, ballY, ballR);
    
    if (dispMsg == true) {
        if (collided == true) {
            dinFont.drawString( "NICE!", msgX, msgY);
        }
        else {
            dinFont.drawString( "FAIL.", msgX, msgY);
        }
    }
    
    dinFont.drawString( "score is : " + ofToString(score), ofGetWidth()-225, ofGetHeight()-5);
	
    /*
     // draw the left:
     ofSetHexColor(0x333333);
     ofRect(0,0,256,200);
     ofSetHexColor(0xFFFFFF);
     for (int i = 0; i < 256; i++){
     ofLine(i,100,i,100+left[i]*200);
     }
     
     ofSetHexColor(0x000000);
     */
    
    // Draw the values:
    dinFont.drawString( "pitch is : " + ofToString((int)AA.pitch), 0,ofGetHeight()-5);
    /*dinFont.drawString( "amplitude is : " + ofToString(AA.amplitude,3), 50,375);
     dinFont.drawString( "confidence is : " + ofToString(AA.confidence), 50,450);
     */
    
    cout<<"confidence is "<<AA.confidence<<"; dispMsg = "<<dispMsg<<"; msgCounter = "<<msgCounter<<endl;
	
}


//--------------------------------------------------------------
void testApp::audioReceived (float * input, int bufferSize, int nChannels){
	
	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];
		right[i] = input[i*2+1];
	}
    
	AA.processAudio(left, bufferSize);
}



//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	
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
void testApp::mouseReleased(){
	
}


