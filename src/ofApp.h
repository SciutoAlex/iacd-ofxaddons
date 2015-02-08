#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxDither.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int w;
        int h;
    
        ofImage     grabImage;
        ofImage     ditherImage;
        ofFbo       fbo;
        ofxBox2d                            box2d;			  //	the box2d world
        vector    <ofPtr<ofxBox2dCircle> >	circles;		  //	default box2d circles
        vector	  <ofPtr<ofxBox2dRect> >	boxes;			  //	defalut box2d rects
        vector	  <ofPtr<ofxBox2dRect> >	rects;			  //	defalut box2d rects
    
        ofxDither	dither;
		
};
