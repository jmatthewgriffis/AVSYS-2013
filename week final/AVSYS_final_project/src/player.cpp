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
    arrowWide = 15;
    arrowTall = arrowWide/2;
    arrowSpacer = 5;
    widePlayer = 50;
    tallPlayer = widePlayer;
    awayFromSurface = 15;
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
    whichNote = 1;
    allowChangeNote = true;
    
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
    else { // If the player is using the menu:
        if (moveUP && allowChangeNote) {
            whichNote++;
            allowChangeNote = false;
        }
        if (moveDOWN && allowChangeNote){
            whichNote--;
            allowChangeNote = false;
        }
    }
    
    if (whichNote > 8) whichNote = 1;
    if (whichNote < 1) whichNote = 8;
    
    //cout<<whichNote<<endl;
    
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
    float topOfMenu = ofGetHeight()/2 - (fontSize*8+menuSpacer*8)/2;
    
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
        
        // Draw the highlight box:
        ofSetColor(255,0,0);
        float y;
        for (int i = 1; i < 9; i++) if (whichNote == i) y = ofGetHeight()/2 + (fontSize*8+menuSpacer*8)/2 - (fontSize+menuSpacer) * i;
        
        ofRect(x-fontSize/2, y, fontSize*2, fontSize+menuSpacer);
        
        // Draw the notes:
        ofSetColor(255);
        font.drawString("C", x, topOfMenu + menuSpacer*0.5 + fontSize);
        font.drawString("B", x, topOfMenu + menuSpacer*1.5 + fontSize*2);
        font.drawString("A", x, topOfMenu + menuSpacer*2.5 + fontSize*3);
        font.drawString("G", x, topOfMenu + menuSpacer*3.5 + fontSize*4);
        font.drawString("F", x, topOfMenu + menuSpacer*4.5 + fontSize*5);
        font.drawString("E", x, topOfMenu + menuSpacer*5.5 + fontSize*6);
        font.drawString("D", x, topOfMenu + menuSpacer*6.5 + fontSize*7);
        font.drawString("C", x, topOfMenu + menuSpacer*7.5 + fontSize*8);
        
    }
    
    // End note menu.
    
    // The cue arrows surrounding the player to indicate controls. Change the color based on how the arrows are being used:
    ofSetColor(0);
    // Top:
    if (yPosPlayer > verticalSpacer || moveLEFT) {
        if (moveUP) ofSetColor(255);
        if (!moveUP && moveLEFT) ofSetColor(255,0,0);
        if (moveUP && moveLEFT) ofSetColor(255);
        ofTriangle(xPosPlayer+widePlayer/2-arrowWide/2, yPosPlayer-arrowSpacer, xPosPlayer+widePlayer/2+arrowWide/2, yPosPlayer-arrowSpacer, xPosPlayer+widePlayer/2, yPosPlayer-arrowSpacer-arrowTall);
    }
    ofSetColor(0);
    if (yPosPlayer < ofGetHeight() - verticalSpacer || moveLEFT) {
        // Bottom:
        if (moveDOWN) ofSetColor(255);
        if (!moveDOWN && moveLEFT) ofSetColor(255,0,0);
        if (moveDOWN && moveLEFT) ofSetColor(255);
        ofTriangle(xPosPlayer+widePlayer/2-arrowWide/2, yPosPlayer+tallPlayer+arrowSpacer, xPosPlayer+widePlayer/2+arrowWide/2, yPosPlayer+tallPlayer+arrowSpacer, xPosPlayer+widePlayer/2, yPosPlayer+tallPlayer+arrowSpacer+arrowTall);
    }
    ofSetColor(0);
    // Left:
    if (!moveRIGHT) {
        if (moveLEFT) ofSetColor(255);
        ofTriangle(xPosPlayer-arrowSpacer, yPosPlayer+tallPlayer/2-arrowWide/2, xPosPlayer-arrowSpacer, yPosPlayer+tallPlayer/2+arrowWide/2, xPosPlayer-arrowSpacer-arrowTall, yPosPlayer+tallPlayer/2);
    }
    ofSetColor(0);
    // Right:
    if (!moveLEFT) {
        if (moveRIGHT) ofSetColor(255);
        ofTriangle(xPosPlayer+widePlayer+arrowSpacer, yPosPlayer+tallPlayer/2-arrowWide/2, xPosPlayer+widePlayer+arrowSpacer, yPosPlayer+tallPlayer/2+arrowWide/2, xPosPlayer+widePlayer+arrowSpacer+arrowTall, yPosPlayer+tallPlayer/2);
    }
    
    
    // The player:
    ofSetColor(0);
    ofRect(xPosPlayer, yPosPlayer, widePlayer, tallPlayer);
    
}