//
//  attack.cpp
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 4/30/13.
//
//

#include "attack.h"

//--------------------------------------------------------------
void attack::setup(float xPosPlayer, float attackWide){
    
    attackSpacer = 10;
    wide = attackWide;
    tall = wide;
    xPos = xPosPlayer + wide + attackSpacer;
    yPos = 0;
    xVel = 5;
    iTossThePower = false;
    
}

//--------------------------------------------------------------
void attack::update(float yPosPlayer, bool moveRIGHT){
    
    checkMoveRIGHT = moveRIGHT;
    
    if (checkMoveRIGHT == true) iTossThePower = true;
    
    if (iTossThePower == false) yPos = yPosPlayer;
    else xPos += xVel;
    
    cout<<moveRIGHT<<" "<<iTossThePower<<endl;
    
}

//--------------------------------------------------------------
void attack::draw(){
    
    ofSetColor(255);
    ofRect(xPos, yPos, wide, tall);
    ofSetColor(0);
    
}