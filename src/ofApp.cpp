#include "ofApp.h"

Cloud::Cloud() {
	cloudCenter = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
}

//init function generates the particles and puts them in the particles vector
void Cloud::init(int partNum) {
	
	ofColor color;
	ofPoint position;
	ofPoint velocity;
	ofPoint force;
	for (int i = 0; i < partNum; i++) {
		position.x = cloudCenter.x - ofRandom(-100.0, 100.0);
		position.y = cloudCenter.y - ofRandom(-200.0, 200.0);

		velocity.x = 2.0;
		velocity.y = 2.0;

		force = ofPoint(0, 0, 0);

		color.r = ofRandom(255.0);
		color.g = ofRandom(255.0);
		color.b = ofRandom(100.0);

		particle p;
		p.color = color;
		p.position = position;
		p.velocity = velocity;
		p.force = force;
		particles.push_back(p);
	}
}


void Cloud::drawCloud() {
	for (int i = 0; i < particles.size(); i++) {
		ofSetColor(particles[i].color);
		ofDrawRectangle(particles[i].position, 10, 10);
	}
}

void Cloud::update() {
	float drag = ofRandom(0.95, 0.999);
	//particle attract code largely based on code written in particleExample in math example for openframeworks
	// with some edits to work for my project
	for (int i = 0; i < particles.size(); i++) {
		
		particles[i].force = cloudCenter - particles[i].position;
		//scale vector down so you just have direction of the force
		particles[i].force.normalize();

		particles[i].velocity *= drag;
		particles[i].velocity += particles[i].force * 0.6;

		particles[i].position += particles[i].velocity;
	}
}
//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(ofColor::black);
	cloud.init(500);

	fft.setup(1024);
<<<<<<< HEAD
=======

	songButton.addListener(this, &ofApp::songPressed);
	song2Button.addListener(this, &ofApp::song2Pressed);

	gui.setup();
	gui.add(songButton.setup("Sound and Vision"));
	gui.add(song2Button.setup("Sound and Color"));

	song.load("soundandvision.mp3");
	song2.load("soundandcolor.mp3");
>>>>>>> Implemented OfxGui, users can choose between two songs (located in bin/data)
}

//--------------------------------------------------------------
void ofApp::update() {
	fft.update();
	// if sound is playing, make particles repel
	float soundVal = fft.getBins()[20];
<<<<<<< HEAD
	if (soundVal > 0.5) {
=======
	if (soundVal > 0.8) {
>>>>>>> Implemented OfxGui, users can choose between two songs (located in bin/data)
		float drag = ofRandom(0.95, 0.999);
		//particle repel code largely based on code written in particleExample in math example for openframeworks
		// with some edits to work for my project
		for (int i = 0; i < cloud.particles.size(); i++) {
			//conditionals used to keep particles in the bounds of the window
			if (cloud.particles[i].position.x > ofGetWidth()) {
				cloud.particles[i].position.x = ofGetWidth() - 50;
				//cloud.particles[i].velocity *= -1.0;
			} else if (cloud.particles[i].position.y > ofGetHeight()) {
				cloud.particles[i].position.y = ofGetHeight() - 50;
				//cloud.particles[i].velocity *= -1.0;
			} else if (cloud.particles[i].position.x < 0) {
				cloud.particles[i].position.x = 50;
			} else if (cloud.particles[i].position.y < 0) {
				cloud.particles[i].position.y = 50;
			}
			cloud.particles[i].force = cloud.cloudCenter - cloud.particles[i].position;
			//scale vector down so you just have direction of the force
			cloud.particles[i].force.normalize();  
			//apply drag
			cloud.particles[i].velocity *= drag;
			//for particles to repel, force must be negative
			cloud.particles[i].velocity += -cloud.particles[i].force * 0.6; 

			cloud.particles[i].position += cloud.particles[i].velocity;
		}
	// no sound is playing, call cloud.update()
	} else {
		cloud.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
<<<<<<< HEAD
	cloud.drawCloud();
=======
	gui.draw();
	cloud.drawCloud();
}

void ofApp::songPressed() {
	song2.stop();
	if (!song.isPlaying()) {
		song.play();
	}
}

void ofApp::song2Pressed() {
	song.stop();
	if (!song2.isPlaying()) {
		song2.play();
	}
>>>>>>> Implemented OfxGui, users can choose between two songs (located in bin/data)
}