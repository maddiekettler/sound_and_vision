#pragma once

#include "ofMain.h"
#include "ofxEasyFft.h"

class Cloud {
	struct particle {
		ofColor color;
		ofPoint position;
		ofPoint velocity;
		ofPoint force;
	};

public:
	Cloud();
	void init(int partNum);
	void drawCloud();
	void update();

private:
	ofPoint cloudCenter;
	vector<particle> particles;
};

class ofApp : public ofBaseApp {

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
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	Cloud cloud;
	ofxEasyFft fft;
};

