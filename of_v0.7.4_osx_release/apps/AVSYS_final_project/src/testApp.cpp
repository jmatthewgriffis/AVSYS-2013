#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // Housekeeping:
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    // The platforms:
    widePlatform = ofGetWidth();
    tallPlatform = 10;
    verticalSpacer = (ofGetHeight()-(tallPlatform*5))/6;
    
    // The enemies:
    myEnemy.setup();
    enemies.push_back(myEnemy);
    
    // The player:
    player.setup(tallPlatform, verticalSpacer);
    
    // The attacks:
    numAttacks = 5;
    whichNote = 1;
    
    ofSetColor(0); // Make everything black, for now.
    
}

//--------------------------------------------------------------
bool bShouldIErase(attack & a){
    
    // Zach showed me how to use this method to remove an element from a vector. We create a boolean function, i.e. one that will return a boolean (so we don't use 'void'). We feed it a class and pass a reference label that we make up (in this case 'a') so we can refer to the applicable object. Then we check for a certain condition -- in this case whether the object has moved too far offscreen to the right -- and if so we return a boolean value of 'true.' Otherwise it's 'false.'
    
    if (a.destroyMe) return true;
    else return false;
    
}

//--------------------------------------------------------------
bool bShouldIErase2(enemy & a){
    
    if (a.destroyMe) return true;
    else return false;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < attacks.size(); i++) {
        if (attacks[i].xPos > ofGetWidth() + attacks[i].handToPower) {
            attacks[i].note.stop(); // Quit playing the attack's note (this may not be necessary, but just in case).
            attacks[i].destroyMe = true;
        }
    }
    
    for (int i = 0; i < attacks.size(); i++) {
        for (int j = 0; j < enemies.size(); j++) {
            if (attacks[i].xPos > enemies[j].xPos+enemies[j].wide) {
                attacks[i].note.stop();
                enemies[j].note.stop();
                attacks[i].destroyMe = true;
                enemies[j].destroyMe = true;
            }
        }
    }
    
    
    player.update();
    
    whichNote = player.whichNote;
    
    // Regulate the frequency of attacks:
    player.allowAttack = true; // Default mode allows attack.
    if (attacks.size() != 0) { // If there is at least one attack onscreen...
        if (attacks.size() >= numAttacks) player.allowAttack = false; // ...don't allow more than the max number of onscreen attacks.
        for (int i=0; i<attacks.size(); i++) {
            // If any attack is too close to the player, prevent another attack:
            //if (attacks[i].xPos < attacks[i].attackSpacerPerfect) { // Equal spacing.
            if (attacks[i].xPos < attacks[i].attackSpacerMinimum) player.allowAttack = false; // Minimal spacing (more responsive).
        }
    }
    
    // If the player presses the attack button and an attack is allowed, create an attack object and set it up, set the attack's status to "held," and store it in the attack vector (don't allow attack if menu is open):
    if (player.moveRIGHT && player.allowAttack && !player.moveLEFT) {
        attack attack;
        attack.setup(player.xPosPlayer, player.yPosPlayer, player.widePlayer, 50, numAttacks, whichNote);
        attack.checkMoveRIGHT = true;
        attacks.push_back(attack);
    }
    
    for (int i=0; i<attacks.size(); i++) {
        // If the player is not holding the attack button, change the attacks' status to "released":
        if (!player.moveRIGHT) attacks[i].checkMoveRIGHT = false;
        attacks[i].update(player.xPosPlayer, player.yPosPlayer, player.moveRIGHT);
    }
    
    // Collision between attack and enemy:
    for (int i = 0; i < attacks.size(); i++) {
        for (int j = 0; j < enemies.size(); j++) {
            attacks[i].note.setVolume(0.3f); // Default w/o collision.
            enemies[j].note.setVolume(0.3f); // Default w/o collision.
            if (attacks[i].xPos+attacks[i].wide > enemies[j].xPos && attacks[i].xPos < enemies[j].xPos+enemies[j].wide) {
                attacks[i].note.setVolume(1.0f);
                enemies[j].note.setVolume(1.0f);
            }
        }
    }
    
    for (int i = 0; i < enemies.size(); i++) enemies[i].update();
    
    // Following up the boolean function we created above, this oF function sorts the vector according to the values of the booleans and then removes any with a 'true' value:
    ofRemove(attacks,bShouldIErase);
    ofRemove(enemies,bShouldIErase2);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Draw the platforms:
    ofSetColor(0);
    for (int i = 0; i < 5; i++) ofRect(0, verticalSpacer+tallPlatform*i+verticalSpacer*i, widePlatform, tallPlatform);
    
    for (int i = 0; i < enemies.size(); i++) enemies[i].draw();
    
    player.draw();
    
    for (int i=0; i<attacks.size(); i++) attacks[i].draw();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // Enable movement on keyPress:
    switch (key) {
        case 'w':
        case 'W':
        case OF_KEY_UP:
            player.moveUP = true;
            break;
            
        case 'a':
        case 'A':
        case 'j':
        case 'J':
        case OF_KEY_LEFT:
            if (!player.moveRIGHT) player.moveLEFT = true;
            break;
            
        case 's':
        case 'S':
        case OF_KEY_DOWN:
            player.moveDOWN = true;
            break;
            
        case 'd':
        case 'D':
        case 'k':
        case 'K':
        case OF_KEY_RIGHT:
            if (!player.moveLEFT) player.moveRIGHT = true;
            break;
            
        case 'r':
        case 'R':
            // Clear out the vector:
            for (int i=0; i<attacks.size(); i++) attacks.erase(attacks.begin(), attacks.end());
            setup();
            break;
            
            // Debug - change the note:
            /*case '-':
             if (whichNote > 1) whichNote--;
             break;
             
             case '=':
             if (whichNote < 8) whichNote++;
             break;*/
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    // Disable movement on keyRelease:
    switch (key) {
        case 'w':
        case 'W':
        case OF_KEY_UP:
            player.moveUP = false;
            player.allowChangeNote = true;
            break;
            
        case 'a':
        case 'A':
        case 'j':
        case 'J':
        case OF_KEY_LEFT:
            player.moveLEFT = false;
            break;
            
        case 's':
        case 'S':
        case OF_KEY_DOWN:
            player.moveDOWN = false;
            player.allowChangeNote = true;
            break;
            
        case 'd':
        case 'D':
        case 'k':
        case 'K':
        case OF_KEY_RIGHT:
            player.moveRIGHT = false;
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