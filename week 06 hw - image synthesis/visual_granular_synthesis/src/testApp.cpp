#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // Thanks to Zach for the gradient example. I modified it to fit the dimensions of this project:
    // "
    img.allocate(1024, 768, OF_IMAGE_GRAYSCALE);
    // "
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    maxImages = 20; // How many images can be in the arrayList at once?
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Thanks to Zach for the gradient example. I modified it to fit the dimensions of this project:
    // "
    unsigned char * pixels = img.getPixels();
    
    
    // (note: the order of these for loops doesn't matter)
    
    for (int i = 0; i < 1024; i++){
        for (int j = 0; j < 768; j++){
            
            
            // horizontal gradient
            // this "wraps" over
            //pixels[ j * 640 + i ] = i;
            
            pixels[ j * 1024 + i ] = ofMap(i, 0, 1024, 255, 0);
            
            
            // this is funky and weird
            //pixels[ j * 640 + i ] = ofMap(i + sin(j/10.0 + ofGetElapsedTimef()) * j, 0, 640, 255, 0, true);
        }
    }
    
    img.update();
    // "
    
    
    
    
    for (int i=0; i<myImages.size(); i++) {
        myImages[i].update();
    }
    
    // Don't let the arrayList size get out of hand. Erase the earliest one if necessary.
    if (myImages.size()>maxImages) {
        myImages.erase(myImages.begin());
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    img.draw(ofGetWidth()/2,ofGetHeight()/2);
    
    for (int i=0; i<myImages.size(); i++) {
        for (int j=i+1; j<myImages.size(); j++) { // Use an additional for loop to compare different elements in myImages to each other.
            if (myImages.size() > 1) { // If there's more than 1 image onscreen:
                ofSetColor(0); // Make the lines black.
                ofLine(myImages[i].x, myImages[i].y, myImages[j].x, myImages[j].y); // Draw a line between the two images.
                ofSetColor(255); // Re-enable the full spectrum.
            }
        }
        myImages[i].draw(); // Draw the images last to make sure they appear on top of the lines.
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    myImage instance; // Create an instance of the myImage class.
    instance.setup(mouseX, mouseY); // Feed in the current mousePos to draw the image at that spot.
    myImages.push_back(instance); // Make room in the arrayList for the new object.
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}