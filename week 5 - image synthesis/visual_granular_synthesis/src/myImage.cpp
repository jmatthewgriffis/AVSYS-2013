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
    
    displayWhich = int(ofRandom(9.5)); // Pick a random int from 0 through 9.
    imageReducer = 4.5; // Shrink the images (higher = smaller).
    timeDelay = 0; // This is a counter to delay movement.
    xVel = 3;
    yVel = 2;
    
    // Use the random number to determine which picture is drawn:
    if (displayWhich == 0) {
        myPic.loadImage("pics/img1.jpg");
        // Img src: http://cdn.arstechnica.net/wp-content/uploads/2012/10/06_Place_20773_1_Mis.jpg
        w = 300; // These are the image's original dimensions.
        h = 201;
    }
    else if (displayWhich == 1) {
        myPic.loadImage("pics/img2.jpg");
        // Img src: http://static3.businessinsider.com/image/50e08aa6eab8eacb2e00001b-900/a-blue-marble-image-released-in-january-was-touted-by-nasa-as-the-most-amazing-high-definition-image-of-earth-blue-marble-2012-a-composite-image-of-several-swaths-of-earth-was-an-update-to-the-original-blue-marble-image-from-1972-according-to-flickr-the-western-hemisphere-blue-marble-2012-picked-up-31-million-views-between-jan-25-and-feb-2-making-it-one-of-the-all-time-most-viewed-images-on-the-site-after-only-one-week.jpg
        w = 225;
        h = 225;
    }
    else if (displayWhich == 2) {
        myPic.loadImage("pics/img3.jpg");
        // Img src: http://www.desktopwallpaperhd.net/wallpapers/14/b/beaches-summer-beautiful-beach-wallpaper-sunset-images-142299.jpg
        w = 480;
        h = 270;
    }
    else if (displayWhich == 3) {
        myPic.loadImage("pics/img4.jpg");
        // Img src: http://blog.gettyimages.com/wp-content/uploads/2013/01/Siberian-Tiger-Running-Through-Snow-Tom-Brakefield-Getty-Images-200353826-001.jpg
        w = 429;
        h = 287;
    }
    else if (displayWhich == 4) {
        myPic.loadImage("pics/img5.jpg");
        // Img src: http://ds9.ssl.berkeley.edu/imageviewer/images/images2/latest_eit_284_full.jpg
        w = 225;
        h = 225;
    }
    else if (displayWhich == 5) {
        myPic.loadImage("pics/img6.jpg");
        // Img src: http://www.slate.com/content/dam/slate/blogs/bad_astronomy/2012/12/best_of_2012_photos/SDO_arch.jpg.CROP.article920-large.jpg
        w = 460;
        h = 259;
    }
    else if (displayWhich == 6) {
        myPic.loadImage("pics/img7.jpg");
        // Img src: http://images.nationalgeographic.com/wpf/media-live/photos/000/637/cache/best-science-images-2012-human-mind_63737_600x450.jpg
        w = 450;
        h = 450;
    }
    else if (displayWhich == 7) {
        myPic.loadImage("pics/img8.jpg");
        // Img src: http://wallpapersget.com/wallpapers/2012/02/landscape-beautiful-wallpaper-beach-images-tropical-1080x1920.jpg
        w = 480;
        h = 270;
    }
    else if (displayWhich == 8) {
        myPic.loadImage("pics/img9.jpg");
        // Img src: http://www.designboom.com/weblog/images/images_2/rodrigo/09_september_2012/18_570mpCamera/570_01.jpg
        w = 409;
        h = 272;
    }
    else if (displayWhich == 9) {
        myPic.loadImage("pics/img10.png");
        // Img src: http://cdn.theatlantic.com/static/mt/assets/science/Screen%20Shot%202012-08-29%20at%201.45.48%20PM.png
        w = 308;
        h = 294;
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