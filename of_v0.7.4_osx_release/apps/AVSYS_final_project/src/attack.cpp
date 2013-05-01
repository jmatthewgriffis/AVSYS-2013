//
//  attack.cpp
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 4/30/13.
//
//

#include "attack.h"

//--------------------------------------------------------------
void attack::setup(float xPosPlayer, float yPosPlayer, float attackWide){
    
    attackSpacer = 10;
    wide = attackWide;
    tall = wide;
    xPos = xPosPlayer + wide + attackSpacer;
    yPos = yPosPlayer;
    xVel = 5;
    iTossThePower = false;
    
}

//--------------------------------------------------------------
void attack::update(float xPosPlayer, float yPosPlayer, bool moveRIGHT){
    
    checkMoveRIGHT = moveRIGHT;
    
    // Cue firing the attack if the player presses Attack:
    if (checkMoveRIGHT == true) iTossThePower = true;
    
    // If the attack hasn't been fired, mirror the player's yPos:
    if (iTossThePower == false) yPos = yPosPlayer;
    else xPos += xVel; // Otherwise it has been fired so move it horizontally.
    
    // If the attack moves offscreen, reset it:
    if (xPos > ofGetWidth() + wide) setup(xPosPlayer, yPosPlayer, wide);
    
}

//--------------------------------------------------------------
void attack::draw(){
    
    ofSetColor(255);
    ofRect(xPos, yPos, wide, tall);
    ofSetColor(0);
    
}