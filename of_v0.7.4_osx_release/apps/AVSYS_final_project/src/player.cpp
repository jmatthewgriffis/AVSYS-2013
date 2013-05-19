//
//  player.cpp
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 5/18/13.
//
//

#include "player.h"

void player::setup(float _tallPlatform, float _verticalSpacer) {
    
    fontSize = 24;
    font.loadFont("fonts/helvetica.otf", fontSize);
    tallPlatform = _tallPlatform;
    verticalSpacer = _verticalSpacer;
    menuSpacer = (verticalSpacer-fontSize*2)/3;
    widePlayer = 50;
    tallPlayer = widePlayer;
    awayFromSurface = 10;
    xPosPlayer = 80+awayFromSurface;
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
    
    if (!moveLEFT) { // Prevent movement when accessing the menu.
        
        if (moveUP == true && allowMove == true && (yPosPlayer > verticalSpacer)) {
            yPosPlayer -= verticalSpacer + tallPlatform;
            allowMove = false;
        }
        
        if (moveDOWN == true && allowMove == true && (yPosPlayer < ofGetHeight() - verticalSpacer)) {
            yPosPlayer += verticalSpacer + tallPlatform;
            allowMove = false;
        }
        
    } // End if (!moveLeft)
    
    // Control player movement frequency:
    if (allowMove == false) delayMoveCounter++;
    
    /* Reset movement if the frequency limit has been reached but also if the player lets go of all movement keys. That way if the player holds a momvement button the pace is constrained but if the player rapidly presses the button he or she can move more quickly: */
    if ((delayMoveCounter >= delayMoveTill) || (moveUP == false && moveDOWN == false)) {
        allowMove = true;
        delayMoveCounter = 0;
    }
    
}

void player::draw() {
    
    // The note menu:
    
    float x = xPosPlayer/2-fontSize/2;
    float bottomOfPlat = verticalSpacer + tallPlatform;
    //float topOfPlat = verticalSpacer*2 - menuSpacer;
    
    if (moveLEFT) {
        
        // Draw the menu background:
        ofSetRectMode(OF_RECTMODE_CENTER);
        // Outer, hollow rect:
        ofSetColor(255);
        ofNoFill();
        ofRect(x+fontSize/2, ofGetHeight()/2, fontSize*2+1, fontSize*8+menuSpacer*8+1);
        ofFill();
        // Inner, solid rect:
        ofSetColor(200);
        ofRect(x+fontSize/2, ofGetHeight()/2, fontSize*2, fontSize*8+menuSpacer*8);
        ofSetRectMode(OF_RECTMODE_CORNER);
        
        // Draw the notes:
        ofSetColor(255);
        font.drawString("C", x, bottomOfPlat + menuSpacer + fontSize);
        font.drawString("B", x, bottomOfPlat + menuSpacer*2 + fontSize*2);
        font.drawString("A", x, bottomOfPlat*2 + menuSpacer + fontSize);
        font.drawString("G", x, bottomOfPlat*2 + menuSpacer*2 + fontSize*2);
        font.drawString("F", x, bottomOfPlat*3 + menuSpacer + fontSize);
        font.drawString("E", x, bottomOfPlat*3 + menuSpacer*2 + fontSize*2);
        font.drawString("D", x, bottomOfPlat*4 + menuSpacer + fontSize);
        font.drawString("C", x, bottomOfPlat*4 + menuSpacer*2 + fontSize*2);
        
    }
    
    // The player:
    ofSetColor(0);
    ofRect(xPosPlayer, yPosPlayer, widePlayer, tallPlayer);
    
}