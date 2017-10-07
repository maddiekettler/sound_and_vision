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
	vector<particle> particles;

	Cloud();
	void init(int partNum);
	void drawCloud();
	void update();

	ofPoint cloudCenter;
};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	Cloud cloud;
	ofxEasyFft fft;
};

