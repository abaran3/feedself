#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	cam.setDistance(700); //use the ofeasycam function so that we can manipulate the viewing of the torus

	torusModel.loadModel("torus.stl");
	//initial rotation in x, y and z axes
	xrot = 90;
	yrot = 0;
	zrot = 45;
	
	//load text file
	ifstream fin;
	fin.open(ofToDataPath("paper2.txt").c_str());
	while (!fin.eof())
	{
		string str; //string for storage  
		getline(fin, str); //get a line from the file, put it in the string  
		data.push_back(str); //push the string onto a vector of strings  
	}
	
	startMillis = ofGetElapsedTimeMillis();
	interval = 4000;
	data_index = 0;	
}

//--------------------------------------------------------------
void ofApp::update(){
	//update torus rotation
	xrot = (xrot + 1) % 360;
	yrot = sin(yrot) *360;
	zrot = (zrot - 1) % 360;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);
	
	cam.begin();
	ofSetColor(ofColor::white);
	//torusModel.setPosition(ofGetWidth() / 2, ofGetHeight() /3, 0); //use this if we're not using easy cam to position the torus
	torusModel.setRotation(0, xrot, 1, 0, 0);
	torusModel.setRotation(1, yrot, 0, 1, 0);
	torusModel.setRotation(2, zrot, 0, 0, 1);
	torusModel.setScale(0.6, 0.6, 0.6);
	torusModel.drawWireframe();
	cam.end();

	//display text one line at a time
	ofDrawBitmapString(data[data_index], 100, ofGetHeight() - 100);

	//(thought i could maybe use this to make the font bigger, but didnt get too far with it yet 
	//need to include the right header files/ library, it seems to be used in openGL)
	//for (int i = 0; data[data_index][i] != '\0'; i++) {
	//	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, data[data_index][i]);
	//}
	
	//update index to display next text line after interval has elapsed
	currentMillis = ofGetElapsedTimeMillis();
	if ((currentMillis - startMillis) > interval) {
		interval = ofRandom(1000, 6000);
		startMillis = ofGetElapsedTimeMillis();
		if (data_index < data.size()) {
			data_index++;
		}
		else {
			data_index = 0;
		}
	}

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

// was using this with a sphere before, not really necessary anymore
//float ofApp::updatePos(float posCurrent, float speed){
//	float newPos;
//	if ((posCurrent > (0 + 2 * radius)) && (posCurrent < (ofGetWidth() - 2 * radius))) {
//		newPos = posCurrent + speed;
//	}
//	else {
//		speed *= -1;
//		newPos = posCurrent + speed;
//	}
//	return newPos;
//}

