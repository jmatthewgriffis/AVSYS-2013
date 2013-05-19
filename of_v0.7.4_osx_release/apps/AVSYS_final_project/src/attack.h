//
//  attack.h
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 4/30/13.
//
//

#ifndef __AVSYS_final_project__attack__
#define __AVSYS_final_project__attack__

// This file contains all the OF code. Make sure to "include" it:
#include "ofMain.h"

class attack {
    
public:
    
    void setup(float xPosPlayer, float yPosPlayer, float _widePlayer, float attackWide, int _numAttacks, int _whichNote);
    void update(float xPosPlayer, float yPosPlayer, bool moveRIGHT);
    void draw();
    
    float xPos, yPos, wide, tall, xVel, widePlayer;
    int numAttacks, whichNote;
    float handToPower; // Default space between player and attack.
    float attackSpacerPerfect; // Attacks are perfectly spaced.
    float attackSpacerMinimum; // Attacks are minimally spaced.
    bool iTossThePower; // Does the player toss the power?
    bool checkMoveRIGHT; // Is the player pressing Attack?
    
    ofSoundPlayer note;
    
};


#endif /* defined(__AVSYS_final_project__attack__) */
