#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // Housekeeping:
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    // The platforms:
    widePlatform = ofGetWidth();
    tallPlatform = 10;
    verticalSpacer = ofGetHeight()/6;
    
    // The player:
    widePlayer = 50;
    tallPlayer = widePlayer;
    awayFromSurface = 10;
    xPosPlayer = awayFromSurface;
    yPosPlayer = ofGetHeight()-tallPlayer-awayFromSurface;
    moveUP = false;
    moveDOWN = false;
    moveLEFT = false;
    moveRIGHT = false;
    allowMove = true;
    delayMoveCounter = 0;
    delayMoveTill = 30;
    
    ofSetColor(0); // Make everything black, for now.
    
    myAttack.setup(xPosPlayer, 50);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Move the player under certain conditions and limit frequency:
    if (moveUP == true && allowMove == true && (yPosPlayer > verticalSpacer)) {
        yPosPlayer -= verticalSpacer;
        allowMove = false;
    }
    
    if (moveDOWN == true && allowMove == true && (yPosPlayer < ofGetHeight() - verticalSpacer)) {
        yPosPlayer += verticalSpacer;
        allowMove = false;
    }
    
    // Control player movement frequency:
    if (allowMove == false) delayMoveCounter++;
    
    /* Reset movement if the frequency limit has been reached but also if the player lets go of all movement keys. That way if the player holds a momvement button the pace is constrained but if the player rapidly presses the button he or she can move more quickly: */
    if ((delayMoveCounter >= delayMoveTill) || (moveUP == false && moveDOWN == false)) {
        allowMove = true;
        delayMoveCounter = 0;
    }
    
    myAttack.update(yPosPlayer, moveRIGHT);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Draw the platforms:
    ofRect(0, verticalSpacer, widePlatform, tallPlatform);
    ofRect(0, verticalSpacer*2, widePlatform, tallPlatform);
    ofRect(0, verticalSpacer*3, widePlatform, tallPlatform);
    ofRect(0, verticalSpacer*4, widePlatform, tallPlatform);
    ofRect(0, verticalSpacer*5, widePlatform, tallPlatform);
    
    // Draw the player:
    ofRect(xPosPlayer, yPosPlayer, widePlayer, tallPlayer);
    
    myAttack.draw();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // Enable movement on keyPress:
    switch (key) {
        case 'w':
        case 'W':
        case OF_KEY_UP:
            moveUP = true;
            break;
            
        case 'a':
        case 'A':
        case OF_KEY_LEFT:
            moveLEFT = true;
            break;
            
        case 's':
        case 'S':
        case OF_KEY_DOWN:
            moveDOWN = true;
            break;
            
        case 'd':
        case 'D':
        case OF_KEY_RIGHT:
            moveRIGHT = true;
            break;
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    // Disable movement on keyRelease:
    switch (key) {
        case 'w':
        case 'W':
        case OF_KEY_UP:
            moveUP = false;
            break;
            
        case 'a':
        case 'A':
        case OF_KEY_LEFT:
            moveLEFT = false;
            break;
            
        case 's':
        case 'S':
        case OF_KEY_DOWN:
            moveDOWN = false;
            break;
            
        case 'd':
        case 'D':
        case OF_KEY_RIGHT:
            moveRIGHT = false;
            break;
    }
    
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