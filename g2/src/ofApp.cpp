#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(225,225,225);
	ofSetVerticalSync(true);

	images.assign(3, ofImage());
	images[0].load("1.png");
	images[1].load("2.png");
	images[2].load("3.png");
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (isAuto) {
		y_pos += 1.5;
	}
	// images
	float ratio = images[0].getHeight()/images[0].getWidth();
	float height = ofGetWindowWidth() * ratio;
	//cout << y_pos << endl;
	float pos1 = y_pos - height;
	float pos2 = y_pos;
	float pos3 = y_pos + height;
	if (y_pos < -1 * height) {
		pos1 = y_pos + 2*height;
	}
	if (y_pos < -2 * height) {
		pos2 = y_pos +  3 * height;
	}
	if (y_pos < -3 * height) {
		y_pos = 0;
	}
	if (y_pos > 1 * height) {
		pos3 = y_pos - 2 * height;
	}
	if (y_pos > 2 * height) {
		pos2 = y_pos - 3 * height;
	}
	if (y_pos > 3 * height) {
		y_pos = 0;
	}


	images[0].draw(0, pos1, ofGetWindowWidth(), height);
	images[1].draw(0, pos2, ofGetWindowWidth(), height);
	images[2].draw(0, pos3, ofGetWindowWidth(), height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if( key=='a'){
		isAuto = true;
	}
	if (key == 'b') {
		isAuto = false;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	y_pos += 2*(y - y_before);
	y_before = y;

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	y_before = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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


