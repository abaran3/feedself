#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofGraphics.h"
#include <fstream>


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		//float updatePos(float posCurrent, float speed); //was using this to move a sphere, but got rid of it in the meantime

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

		ofxAssimpModelLoader torusModel;
		vector<string> data;
		unsigned long long startMillis;
		unsigned long long currentMillis;
		int interval;
		int data_index;
		ofEasyCam cam;

		ofTrueTypeFont font;

		int xrot;
		float yrot;
		int zrot;

};
