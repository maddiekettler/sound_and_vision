#include "ofApp.h"

Cloud::Cloud() {
	cloudCenter = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
}

void Cloud::init(int partNum) {
	
	ofColor color;
	ofPoint position;
	ofPoint velocity;
	ofPoint force;
	for (int i = 0; i < partNum; i++) {
		position.x = cloudCenter.x - ofRandom(-100.0, 100.0);
		position.y = cloudCenter.y - ofRandom(-200.0, 200.0);

		velocity.x = ofRandom(-2.0, 2.0);
		velocity.y = ofRandom(-2.0, 2.0);

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
		ofDrawCircle(particles[i].position.x, particles[i].position.y, 10);
	}
}

void Cloud::update() {
	
	for (int i = 0; i < particles.size(); i++) {

		if ((particles[i].position.x > cloudCenter.x + 180.0) || (particles[i].position.y > cloudCenter.x - 250.0)) {
			particles[i].velocity.x = -particles[i].velocity.x;
			particles[i].velocity.y = -particles[i].velocity.y;
		}
		else if ((particles[i].position.x > cloudCenter.x - 180.0) || (particles[i].position.y > cloudCenter.x - 250.0)) {
			particles[i].velocity.x = -particles[i].velocity.x;
			particles[i].velocity.y = -particles[i].velocity.y;
		}

		ofPoint positionPrev = particles[i].position;
		particles[i].force = cloudCenter - positionPrev;
		particles[i].force = particles[i].force.normalize(); //gets direction of the force
		particles[i].velocity = particles[i].force;
		particles[i].position.x += particles[i].velocity.x;
		particles[i].position.y += particles[i].velocity.y;
	}
}
//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(ofColor::black);
	cloud.init(15);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	cloud.drawCloud();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
	
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) { 

}


