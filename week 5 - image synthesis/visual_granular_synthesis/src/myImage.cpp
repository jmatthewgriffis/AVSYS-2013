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
    
    myPic.loadImage("pics/img1.jpg");
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    
}

void myImage::update() {
    
    myPic.update();
    
}

void myImage::draw() {
    
    myPic.draw(x, y, w, h);
    
}