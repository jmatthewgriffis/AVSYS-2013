//
//  player.cpp
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 5/18/13.
//
//

#include "player.h"

void player::setup(float _verticalSpacer) {
    
    verticalSpacer = _verticalSpacer;
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
    
}

void player::update() {
    
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
    
}

void player::draw() {
    
    ofRect(xPosPlayer, yPosPlayer, widePlayer, tallPlayer);
    
}