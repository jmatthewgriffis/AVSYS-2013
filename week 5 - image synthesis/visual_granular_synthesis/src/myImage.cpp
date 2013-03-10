//
//  image.cpp
//  visual_granular_synthesis
//
//  Created by J. Matthew Griffis on 3/9/13.
//
//

#include "myImage.h"

//--------------------------------------------------------------

void myImage::setup(float _x, float _y, float _w, float _h) {
    
    displayWhich = int(ofRandom(2.5));
    
    if (displayWhich == 0) {
        myPic.loadImage("pics/img1.jpg");
    }
    else if (displayWhich == 1) {
        myPic.loadImage("pics/img2.jpg");
    }
    else if (displayWhich == 2) {
        myPic.loadImage("pics/img3.jpg");
    }
    
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    
}

void myImage::update() {
    
}

void myImage::draw() {
    
    myPic.draw(x, y, w, h);
    
}