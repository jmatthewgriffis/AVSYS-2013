//
//  player.h
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 5/18/13.
//
//

#ifndef __AVSYS_final_project__player__
#define __AVSYS_final_project__player__

#include "ofMain.h"

class player {
    
public:
  
    void setup(float _verticalSpacer);
    void update();
    void draw();
    
    // The player:
    float widePlayer, tallPlayer, xPosPlayer, yPosPlayer, verticalSpacer;
    float awayFromSurface; // Keep the player slightly off the edges.
    bool moveUP, moveDOWN;
    bool moveLEFT; // This will not actually move but rather select.
    bool moveRIGHT; // This will not actually move but rather shoot.
    bool allowMove; // Prevent persistent movement.
    float delayMoveCounter; // Limit movement frequency.
    float delayMoveTill; // Set the movement frequency.
    bool allowAttack; // Prevent overlapping attacks and limit frequency.
    
};

#endif /* defined(__AVSYS_final_project__player__) */
