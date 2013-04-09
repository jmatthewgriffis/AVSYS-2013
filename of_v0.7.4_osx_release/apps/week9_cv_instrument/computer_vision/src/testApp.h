#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "oscillator.h"

/* This is an exercise we did in Humor and Code, which I've modified to use for this homework. I also copied Zach's first oscillator example, which I'm similarly modified. */

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
    
    ofVideoGrabber cam;
    
    ofxCvColorImage colorImage;
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage bgImage;
    ofxCvGrayscaleImage absDiffImage;
    ofxCvContourFinder contourFinder;
    
    int threshold;
    
    void audioOut(float * input, int bufferSize, int nChannels);
    
    ofSoundStream stream;
    
    float * soundBuffer;
    
    oscillator sinWave;
    
};
