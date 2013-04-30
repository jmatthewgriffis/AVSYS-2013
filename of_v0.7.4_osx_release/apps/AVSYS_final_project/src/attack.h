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
    
    void setup(float xPosPlayer, float attackWide);
    void update(float yPosPlayer, bool moveRIGHT);
    void draw();
    
    float xPos, yPos, wide, tall, xVel, attackSpacer;
    bool iTossThePower; // Does the player toss the power?
    bool checkMoveRIGHT;
    
    
};


#endif /* defined(__AVSYS_final_project__attack__) */
