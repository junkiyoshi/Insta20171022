#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofSetCircleResolution(64);
	ofNoFill();

	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	float radius = 5;
	for (int i = 0; i < 30; i++) {
		float noise_value_x = ofNoise((ofGetFrameNum() - i) * 0.025);
		float noise_value_y = ofNoise((ofGetFrameNum() - i + 30) * 0.025);
		float x = 300 * noise_value_x - 150;
		float y = 300 * noise_value_y - 150;

		ofColor line_color;
		line_color.setHsb((ofGetFrameNum() - i + 5) % 255, 255, 255);
		ofSetColor(line_color);
		ofCircle(ofVec3f(x, y, i * 2), radius);

		radius += i;
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}