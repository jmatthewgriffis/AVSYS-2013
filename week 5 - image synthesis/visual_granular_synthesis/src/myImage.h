//
//  image.h
//  visual_granular_synthesis
//
//  Created by J. Matthew Griffis on 3/9/13.
//
//

#ifndef visual_granular_synthesis_image_h
#define visual_granular_synthesis_image_h

#include "ofMain.h"

//--------------------------------------------------------------

class myImage {
    
public: // This is important. Set this to public to allow access to the code
    // from outside the class. Set it to private to only allow access within
    // the class.
    
    void setup(float x, float y, float w, float h);
    void update();
    void draw();
    
    float x;
    float y;
    float w;
    float h;
    
    ofImage myPic;
    
};


#endif
