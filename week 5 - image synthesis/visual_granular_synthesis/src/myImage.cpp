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
    imageReducer = 4.5; // Shrink the images (higher = smaller).
    timeDelay = 0; // This is a counter to delay movement.
    xVel = 3;
    yVel = 2;
    
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
    
    if (timeDelay < 120) {
        timeDelay++; // Add to the counter.
    }
    else { // If sufficient time has passed, modify the pos:
        x += xVel;
        y += yVel;
    }
    
    // Prevent the images from going offscreen by reversing direction:
    if (x <= 0 || x >= ofGetWidth()) {
        xVel *= -1;
    }
    if (y <= 0 || y >= ofGetHeight()) {
        yVel *= -1;
    }
    
    moveWhen = int(ofRandom(250)); // Pick a random int from 0 through 5 and reverse direction on certain numbers:
    if (moveWhen == 3) {
        xVel *= -1;
    }
    if (moveWhen == 42) {
        yVel *= -1;
    }
    
}

void myImage::draw() {
    
    myPic.draw(x, y, w/imageReducer, h/imageReducer); // Easily reduce the image size with the variable.
    
}