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
    allowAttack = true;
    numAttacks = 5;
    whichNote = 1;
    
    ofSetColor(0); // Make everything black, for now.
    
    // From Zach's oscillator example (see class):
    stream.setup(this, 2, 0, 44100, 512, 4);
    soundBuffer = new float[512];
    //...
    sinWave.setup(44100);
    sinWave.setFrequency(440);
    sinWave.setVolume(0.7);
    //...
    sinWave2.setup(44100);
    sinWave2.setFrequency(440);
    sinWave2.setVolume(0.7);
    
    oscillators[0] = sinWave;
    oscillators[1] = sinWave2;
    
}

//--------------------------------------------------------------
bool bShouldIErase(attack & a){
    
    // Zach showed me how to use this method to remove an element from a vector. We create a boolean function, i.e. one that will return a boolean (so we don't use 'void'). We feed it a class and pass a reference label that we make up (in this case 'a') so we can refer to the applicable object. Then we check for a certain condition -- in this case whether the object has moved too far offscreen to the right -- and if so we return a boolean value of 'true.' Otherwise it's 'false.'
    
    if (a.xPos > ofGetWidth() + a.handToPower) {
        a.note.stop();
        return true;
    }
    else return false;
    
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
    
    allowAttack = true; // Default mode allows attack.
    if (attacks.size() != 0) { // If there is at least one attack onscreen...
        if (attacks.size() >= numAttacks) allowAttack = false; // ...don't allow more than the max number of onscreen attacks.
        for (int i=0; i<attacks.size(); i++) {
            // If any attack is too close to the player, prevent another attack:
            //if (attacks[i].xPos < attacks[i].attackSpacerPerfect) { // Equal spacing.
            if (attacks[i].xPos < attacks[i].attackSpacerMinimum) allowAttack = false; // Minimal spacing (more responsive).
        }
    }
    
    // If the player presses the attack button and an attack is allowed, create an attack object and set it up, set the attack's status to "held," and store it in the attack vector:
    if (moveRIGHT && allowAttack) {
        attack attack;
        attack.setup(this, xPosPlayer, yPosPlayer, widePlayer, 50, numAttacks, whichNote);
        attack.checkMoveRIGHT = true;
        attacks.push_back(attack);
    }
    
    for (int i=0; i<attacks.size(); i++) {
        // If the player is not holding the attack button, change the attacks' status to "released":
        if (!moveRIGHT) attacks[i].checkMoveRIGHT = false;
        attacks[i].update(xPosPlayer, yPosPlayer, moveRIGHT);
    }
    
    // Following up the boolean function we created above, this oF function sorts the vector according to the values of the booleans and then removes any with a 'true' value:
    ofRemove(attacks,bShouldIErase);
    
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
    
    //myAttack.draw();
    for (int i=0; i<attacks.size(); i++) attacks[i].draw();
    
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
        case 'j':
        case 'J':
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
        case 'k':
        case 'K':
        case OF_KEY_RIGHT:
            moveRIGHT = true;
            break;
            
            // Debug - change the note:
            case '-':
            if (whichNote > 1) whichNote--;
            break;
            
            case '=':
            if (whichNote < 8) whichNote++;
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
        case 'j':
        case 'J':
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
        case 'k':
        case 'K':
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



// From Zach's oscillator example (see class):
//--------------------------------------------------------------
void testApp::audioOut(float * output, int bufferSize, int nChannels){
    
    /*for (int j = 0; j < 1; j++) {
        
        oscillator oscillator = oscillators[j];
        
        for (int i = 0; i < bufferSize; i++){
            
            float sample = oscillator.getSample(); //ofRandom(-1,1);
            
            output[i*nChannels    ] = sample;
            output[i*nChannels + 1] = sample;
            
            soundBuffer[i] = sample;
        }
    }*/
}