//
//  enemy.h
//  AVSYS_final_project
//
//  Created by J. Matthew Griffis on 5/19/13.
//
//

#ifndef __AVSYS_final_project__enemy__
#define __AVSYS_final_project__enemy__

#include "ofMain.h"

class enemy {
    
public:
    
    void setup();
    void update();
    void draw();
    
    float xPos, yPos, wide, tall, xVel;
    int whichNote;
    bool destroyMe;
    
    ofSoundPlayer note;
    
};

#endif /* defined(__AVSYS_final_project__enemy__) */
