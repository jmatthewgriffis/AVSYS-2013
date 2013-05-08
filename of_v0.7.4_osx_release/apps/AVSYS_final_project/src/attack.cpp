//
//  attack.cpp
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 4/30/13.
//
//

#include "attack.h"

//--------------------------------------------------------------
void attack::setup(float xPosPlayer, float yPosPlayer, float _widePlayer, float attackWide, int _numAttacks){
    
    numAttacks = _numAttacks;
    attackSpacer = 10;
    wide = attackWide;
    tall = wide;
    widePlayer = _widePlayer;
    xPos = xPosPlayer + widePlayer + attackSpacer;
    // Through the power of math we calculate how far apart the attacks need to be to be evenly distributed across the screen at max capacity and to generate an uninterrupted attack flow:
    attackMargin = (xPos*2) + (((ofGetWidth()-xPos) / numAttacks) - wide);
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
    
}

//--------------------------------------------------------------
void attack::draw(){
    
    ofSetColor(255);
    ofRect(xPos, yPos, wide, tall);
    ofSetColor(0);
    
}