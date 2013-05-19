//
//  attack.cpp
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 4/30/13.
//
//

#include "attack.h"

//--------------------------------------------------------------
void attack::setup(float xPosPlayer, float yPosPlayer, float _widePlayer, float attackWide, int _numAttacks, int _whichNote){
    
    numAttacks = _numAttacks;
    whichNote = _whichNote;
    handToPower = 15;
    wide = attackWide;
    tall = wide;
    widePlayer = _widePlayer;
    xPos = xPosPlayer + widePlayer + handToPower;
    // Through the power of math we calculate how far apart the attacks need to be to be evenly distributed across the screen at max capacity and to generate an uninterrupted attack flow:
    attackSpacerPerfect = (xPos*2) + (((ofGetWidth()-xPos) / numAttacks) - wide);
    // Also provide a minimum spacing so attacking is more responsive but still not overlapping (choose one of these methods):
    attackSpacerMinimum = xPos + wide + handToPower;
    yPos = yPosPlayer;
    xVel = 5;
    iTossThePower = checkMoveRIGHT = false;
    
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

//--------------------------------------------------------------
void attack::update(float xPosPlayer, float yPosPlayer, bool moveRIGHT){
    
    //checkMoveRIGHT = moveRIGHT;
    
    // Cue firing the attack if the player presses Attack:
    //if (checkMoveRIGHT == true) iTossThePower = true;
    
    // If the attack hasn't been fired, mirror the player's yPos:
    if (checkMoveRIGHT) yPos = yPosPlayer;
    else xPos += xVel; // Otherwise it has been fired so move it horizontally.
    
}

//--------------------------------------------------------------
void attack::draw(){
    
    ofSetColor(255);
    ofRect(xPos, yPos, wide, tall);
    ofSetColor(0);
    
}