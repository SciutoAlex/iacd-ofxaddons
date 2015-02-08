#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackgroundHex(0xfdefc2);
    ofSetLogLevel(OF_LOG_NOTICE);
    
    box2d.init();
    box2d.setGravity(0, 5);
    box2d.setFPS(30.0);
    box2d.registerGrabbing();
    box2d.createBounds();

    
    w = ofGetWidth();
    h = ofGetHeight();
    fbo.allocate( w, h,  OF_IMAGE_COLOR_ALPHA );
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float random = ofRandom(1,10);
    float x = ofRandom(1,1000);
    float y = 20;
    
    if(random < 5) {
        float r = ofRandom(4, 20);
        circles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(200,1,200);
        circles.back().get()->setup(box2d.getWorld(), x, y, r);
    } else if (random > 7) {
        float w = ofRandom(4, 30);
        float h = ofRandom(4, 30);
        boxes.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
        boxes.back().get()->setPhysics(200,1,200);
        boxes.back().get()->setup(box2d.getWorld(), x+10, y, w, h);
    } else {
        float w = ofRandom(100, 180);
        float h = ofRandom(4, 20);
        rects.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
        rects.back().get()->setPhysics(200,1,200);
        rects.back().get()->setup(box2d.getWorld(), x+10, y, w, h);
    }
    

    
    box2d.drawGround();
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    
    ofClear(255,255,255, 255);
  
    for(int i=0; i<circles.size(); i++) {
        
        ofSetColor(50,50,50);
        ofFill();
        circles[i].get()->draw();
    }
    
    for(int i=0; i<boxes.size(); i++) {
        
        ofSetHexColor(0xccccccc);
        ofFill();
        boxes[i].get()->draw();
    }
    for(int i=0; i<rects.size(); i++) {
        
        ofSetHexColor(0x888888);
        ofFill();
        rects[i].get()->draw();
    }
    
    ofSetColor(255,255,255);
    ofFill();
    grabImage.grabScreen(0,0,w,h);
    fbo.end();
    
    dither.dither_atkinson(grabImage, ditherImage);
    
    ditherImage.draw(ofPoint(0,0));
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
