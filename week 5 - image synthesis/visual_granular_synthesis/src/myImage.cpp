//
//  image.cpp
//  visual_granular_synthesis
//
//  Created by J. Matthew Griffis on 3/9/13.
//
//

#include "myImage.h"

//--------------------------------------------------------------

void myImage::setup(float _x, float _y) {
    
    displayWhich = int(ofRandom(2.5)); // Pick a random int from 0 through 2.
    
    imageReducer = 4.5;
    
    timeDelay = 0;
    
    // Use the random number to determine which picture is drawn:
    if (displayWhich == 0) {
        myPic.loadImage("pics/img1.jpg");
        w = 300; // These are the image's original dimensions.
        h = 201;
    }
    else if (displayWhich == 1) {
        myPic.loadImage("pics/img2.jpg");
        w = 225;
        h = 225;
    }
    else if (displayWhich == 2) {
        myPic.loadImage("pics/img3.jpg");
        w = 480;
        h = 270;
    }
    
    x = _x;
    y = _y;
    
}

void myImage::update() {
    
    timeDelay++;
    
    if (timeDelay >= 120) {
        x += 3;
        y -= 2;
    }
    
}

void myImage::draw() {
    
    myPic.draw(x, y, w/imageReducer, h/imageReducer); // Easily reduce the image size with the variable.
    
}