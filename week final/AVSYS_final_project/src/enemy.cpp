//
//  enemy.cpp
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 5/19/13.
//
//

#include "enemy.h"

void enemy::setup() {
    
    whichNote = 1;
    
    wide = 150;
    tall = wide/3;
    xPos = ofGetWidth()-wide-15;
    yPosDefault = ofGetHeight()-tall-15;
    yPosModifier = (ofGetHeight()-(10*5))/6 + 10;
    yPos = yPosDefault - yPosModifier*3;
    // -= verticalSpacer + tallPlatform
    xVel = 0;
    
    destroyMe = false;
    
    // Set the note:
    if (whichNote == 1) note.loadSound("notes/middleC.mp3");
    else if (whichNote == 2) note.loadSound("notes/d.mp3");
    else if (whichNote == 3) note.loadSound("notes/e.mp3");
    else if (whichNote == 4) note.loadSound("notes/f.mp3");
    else if (whichNote == 5) note.loadSound("notes/g.mp3");
    else if (whichNote == 6) note.loadSound("notes/a.mp3");
    else if (whichNote == 7) note.loadSound("notes/b.mp3");
    else if (whichNote == 8) note.loadSound("notes/highC.mp3");
    note.setVolume(0.3f);
    note.setLoop(true);
    note.play();
    
}

void enemy::update() {
    
    xPos -= xVel;
    
}

void enemy::draw() {
    
    ofSetColor(0,0,255);
    ofRect(xPos, yPos, wide, tall);
    ofSetColor(0);
    
}