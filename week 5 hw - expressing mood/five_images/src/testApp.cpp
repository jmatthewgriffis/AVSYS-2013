#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    /* Here are the five image assignments:
    
    -something that looks inorganic
    
    -something that looks organic
    
    -a unique drawing tool (make a drawing into pixels)
    
    -something that shows or plays with osciallation
    
    -something that has a message (hidden or visible)
     
    I will include them all in this file.
    
    This is adapted from Zach's week3_imageFunky example.
    
    */
     
    img.allocate(640, 480, OF_IMAGE_GRAYSCALE);
    //imgColor.allocate(640, 480, OF_IMAGE_COLOR);
    
    
    timer = 1;
    
    ofHideCursor();
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    unsigned char * pixels = img.getPixels();
    //unsigned char * pixels2 = imgColor.getPixels();

    
    int reverse = 1;
    timer += reverse;
    
    if (timer >= 10000000 || timer <= 0) {
        reverse *= -1;
    }
    
    // (note: the order of these for loops doesn't matter)
    
    for (int i = 0; i < 640; i++){
        for (int j = 0; j < 480; j++){
            
            // the formula for adressing the 1d pixel via 2d is:
            // pos = y * w + x
            // so for us that's
            // pos = j * 640 + i
            
            float dist = ofDist(mouseX, mouseY, i, j);      // calculate the distance between two 2d points (pythogrean)
            
            // These are Zach's examples:
            
            // "
            
            //pixels[ j * 640 + i ] = ofMap(sin(dist), -1, 1, 0, 255);
            //pixels[ j * 640 + i ] = ofMap(sin(dist/10.0), -1, 1, 0, 255);
            
            //pixels[ j * 640 + i ] = ofMap(sin(dist/10.0 + j/10.0), -1, 1, 0, 255);      // no idea!
            
            
            //pixels[ j * 640 + i ] = i * j / MAX(1,mouseX);      // also, no idea!
            
            // "
            
            
            
            
            
            
            // Let's modify them.
            
            pixels[ j * 640 + i ] = ofMap(sin(i/dist + j/dist), -1, 1, 0, 255); // Gazing into the lifeless abyss.
            
            //pixels[ j * 640 + i ] = ofMap(sin(dist*i/timer), -1, 1, 0, 255); // Something is growing and spreading, pulsing with life.
            
            //pixels[ j * 640 + i ] = ofMap(tan(i/dist + j/dist), -1, 1, 0, 255); // A rift in time and space - makes a lovely picture!
            
            //pixels[ j * 640 + i ] = ofMap(tan(dist*i/100.0 + j/10.0), -1, 1, 0, 255); // Primordial muck on a tangent.
            
            //pixels[ j * 640 + i ] = ofMap(sin(cos(tan(i+j/100*i-tan(dist)))), -1, 1, 0, 255); // Static nearly obscures a coded message.
            
            
            
            //pixels2[ j * 640 + i ] = ofMap(tan(dist*i/100.0 + j/10.0), -1, 1, 0, 255); // This attempt to work with color didn't work. Disregard.
            
        }
    }
    
    img.update();
    //imgColor.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    img.draw(0,0);
    //imgColor.draw(0,0);

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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}