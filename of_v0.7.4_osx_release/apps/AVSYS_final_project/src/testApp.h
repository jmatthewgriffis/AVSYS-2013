#pragma once

#include "ofMain.h"
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
    float widePlatform;
    float tallPlatform;
    float verticalSpacer; // Divide the screen vertically.
    
    // The player:
    float widePlayer;
    float tallPlayer;
    float xPosPlayer;
    float yPosPlayer;
    float awayFromSurface; // Keep the player slightly off the edges.
    bool moveUP;
    bool moveDOWN;
    bool moveLEFT; // This will not actually move but rather select.
    bool moveRIGHT; // This will not actually move but rather shoot.
    bool allowMove; // Prevent persistent movement.
    float delayMoveCounter; // Limit movement frequency.
    float delayMoveTill; // Set the movement frequency.
    
    attack myAttack;
    
};
