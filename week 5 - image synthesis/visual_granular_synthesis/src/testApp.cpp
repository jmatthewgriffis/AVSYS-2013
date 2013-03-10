#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    img1.loadImage("pics/img1.jpg");
    img2.loadImage("pics/img2.jpg");
    img3.loadImage("pics/img3.jpg");
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    displayWhich = int(ofRandom(2.1));
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    img1.update();
    img2.update();
    img3.update();
    
    instance.setup(mouseX, mouseY, 300,300);
    instance.update(mouseX, mouseY);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    /*
    if (displayWhich == 0) {
    img1.draw(ofGetWidth()/2, ofGetHeight()/2, 300, 300);
    }
    else if (displayWhich == 1) {
        img2.draw(ofGetWidth()/2, ofGetHeight()/2, 300, 300);
    }
    else if (displayWhich == 2) {
        img3.draw(ofGetWidth()/2, ofGetHeight()/2, 300, 300);
    }
     */

    for (int i=0; i<myImages.size(); i++) {
        //myImages[i].draw(myImages[i].x, myImages[i].y);
    }
    
    instance.draw();
    
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
    
    myImage instance;
    //instance.setup(mouseX, mouseY, 300,300);
    //instance.draw();
    //instance.update();
    /*instance.x = mouseX;
    instance.y = mouseY;*/
    myImages.push_back(instance);
    
    //displayWhich = int(ofRandom(2.1));
    
    ofVec3f temp; // Instance of the ofVec3f object (a vector).
    temp.x = x; // x, y and z are the names of the variables within
    // the vector; however, they don't have to be the conventional
    // x, y and z.
    temp.y = y;
    
    pts.push_back(temp);

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