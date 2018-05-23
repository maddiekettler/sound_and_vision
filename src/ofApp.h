#pragma once

#include "ofMain.h"
#include "ofxEasyFft.h"
#include "ofxGui.h"

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

	void songPressed();
	void song2Pressed();

	Cloud cloud;
	ofxEasyFft fft;

	ofSoundPlayer song;
	ofSoundPlayer song2;

	ofxPanel gui;
	ofxButton songButton;
	ofxButton song2Button;
};

