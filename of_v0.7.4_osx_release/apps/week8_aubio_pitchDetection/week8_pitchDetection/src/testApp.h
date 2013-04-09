#ifndef _TEST_APP
#define _TEST_APP



#include "ofMain.h"
#include "aubioAnalyzer.h"

/* This is Zach's first example using Aubio. I believe it was originally labeled "Week6" rather than "Week8." I've modified it. */

class testApp : public ofSimpleApp{
	
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased();
    void audioReceived		(float * input, int bufferSize, int nChannels);
    
    
    float * left;
    float * right;
	
    aubioAnalyzer AA;
	
    ofTrueTypeFont dinFont;
    
    // I added all the following:
    
    float paddleX;
    float paddleY;
    int paddleW;
    int paddleH;
    float mappedPitch;
    
    float ballX;
    float ballY;
    int ballR;
    int ballV;
    
    bool collided;
    bool dispMsg;
    
    float msgX;
    float msgY;
    
    int msgCounter;
    int score;
	
	
};

#endif	

