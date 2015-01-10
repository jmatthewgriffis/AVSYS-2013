#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // This is Zach's example, which I modified.

	
	//squirrel.loadImage("squirrel.png");
	//squirrel.setImageType(OF_IMAGE_COLOR);
    
    zelda.loadImage("zelda.jpg"); // Thanks to http://romhustler.net/img/screenshots/gamecube/ingame/5126d1c56e94b.jpg
	zelda.setImageType(OF_IMAGE_COLOR);
    
    radX = 5;
    radY = 5;
	
	ofBackground(0,0,0);
    
    ofSetCircleResolution(100);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (mouseX <= (ofGetWidth()/2)) {
        radX = ofMap(mouseX, 0, ofGetWidth()/2, 50, 1);
    }
    else {
        radX = ofMap(mouseX, ofGetWidth()/2, ofGetWidth(), 1, 50);
    }
    
    if (mouseY <= (ofGetHeight()/2)) {
        radY = ofMap(mouseY, 0, ofGetHeight()/2, 50, 1);
    }
    else {
        radY = ofMap(mouseY, ofGetHeight()/2, ofGetHeight(), 1, 50);
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    //ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetColor(255);
    ofDrawBitmapString("These damn binoculars.", ofGetWidth()/2-100, 100);
	
	ofSetColor(0,0,0); // This tints the original image black, hiding it.
	zelda.draw(ofGetWidth()/2,ofGetHeight()/2);
	
	
	unsigned char * pixels = zelda.getPixels();
	
	for (int i = 0; i < zelda.width; i+=MAX(1,8)){
		for (int j = 0; j < zelda.height; j+=MAX(1,8)){
			
			int red = pixels[ (j * zelda.width + i) * 3];
			int green = pixels[ (j * zelda.width + i) * 3 + 1];
			int blue = pixels[ (j * zelda.width + i) * 3 + 2];
			
            xPos = 175 + i;
            yPos = 135 + j;
            
			ofSetColor(red,green,blue);
			ofEllipse(xPos, yPos, radX, radY);
		}
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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

