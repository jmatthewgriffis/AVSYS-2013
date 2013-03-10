#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i=0; i<myImages.size(); i++) {
        myImages[i].update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i=0; i<myImages.size(); i++) {
        myImages[i].draw();
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
    
    myImage instance;
    instance.setup(mouseX, mouseY, 300,300);
    myImages.push_back(instance);
    
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