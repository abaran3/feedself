#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	cam.setDistance(700); //use the ofeasycam function so that we can manipulate the viewing of the torus
	for (int i = 0; i < num_objects; i++) {
		ofxAssimpModelLoader temp;
		temp.loadModel("torus.stl");
		torusModel.push_back(temp);
	}
	//torusModel.loadModel("torus.stl");
	//initial rotation in x, y and z axes
	ofBackground(0);

	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
	ofClear(0, 0, 0, 255);
	shader.load("frag");
	spotlight.setDiffuseColor(ofFloatColor(.9, 0.0, 0.0));
	spotlight.setSpecularColor(ofFloatColor(0.8f, 0.5f, 0.5f));
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
	
	//font.load("helvetica.ttf", 18); //or any other font?
	font.load("timesnew.ttf", 25);
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

	ofBackground(ofColor::white);
	for (int i = 0; i < num_objects; i++) {
		//torusModel[i].setPosition(xrot, yrot, zrot);
		torusModel[i].setRotation(0, xrot+float(i)/ num_objects *360.0, 1, 0, 0);
		torusModel[i].setRotation(1, yrot+float(i) / num_objects *360.0, 0, 1, 0);
		torusModel[i].setRotation(2, zrot + float(i) / num_objects *360.0, 0, 0, 1);
		torusModel[i].setScale(20.0*float(i)/ num_objects, 20.0*float(i) / num_objects, 20.0*float(i) / num_objects);
	}

	//torusModel.setRotation(0, xrot, 1, 0, 0);
	//torusModel.setRotation(1, yrot, 0, 1, 0);
	//torusModel.setRotation(2, zrot, 0, 0, 1);
	//torusModel.setScale(0.6, 0.6, 0.6);

	
	fbo.begin();
	ofClear(0);
	glEnable(GL_DEPTH_TEST);
	ofFill();
	cam.begin();
	spotlight.enable();
	ofSetColor(ofColor::white);	
	//torusmodel.setposition(ofgetwidth() / 2, ofgetheight() /3, 0); //use this if we're not using easy cam to position the torus
	for (int i = 0; i < num_objects; i++) {
		torusModel[i].drawWireframe();
	}
	spotlight.disable();
	cam.end();
	font.drawString(data[data_index], 100, ofGetHeight() - 100);
	fbo.end();

	
	shader.begin();
	shader.setUniform1f("itt", float(currentMillis) / 1000.0);
	shader.setUniform1f("blurAmnt", float(currentMillis)/1000.0);

	shader.setUniformTexture("tex0", fbo.getTextureReference(), 1);
	ofSetColor(255, 255, 255, 255);
	fbo.draw(0,0);
	//fbo.draw(-ofGetWidth()/2.0, -ofGetHeight()/2.0);
	shader.end();

	
	//display text one line at a time
	ofPoint point;
	point.x = 0;
	point.y = 500;

	ofTranslate(point);
	font.drawString(data[data_index], 0, 0);
	// used this before but changing the fontsize was a pain
	//ofDrawBitmapString(data[data_index], 100, ofGetHeight() - 100);

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

