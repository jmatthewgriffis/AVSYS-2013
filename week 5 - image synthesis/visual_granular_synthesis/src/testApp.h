#pragma once

#include "ofMain.h"
#include "myImage.h"

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
    
    // Thanks to Zach for the gradient example. I modified it to fit the dimensions of this project:
    // "
    ofImage img;
    // "
    
    vector<myImage> myImages; // ArrayList of myImage-class objects.
    
    int maxImages;
    
};
