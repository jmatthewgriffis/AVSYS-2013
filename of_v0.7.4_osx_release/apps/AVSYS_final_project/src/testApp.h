#pragma once

#include "ofMain.h"
#include "player.h"
#include "attack.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // The platforms:
    float widePlatform, tallPlatform;
    float verticalSpacer; // Divide the screen vertically.
    
    // The player:
    player player;
    
    // The attacks:
    vector<attack> attacks;
    int numAttacks; // Set the number of attacks allowed onscreen at once.
    int whichNote; // Set the note to attack with (1-8 corresponds to C-C).
    
};
