#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofGLWindowSettings glWindowSettings;
	glWindowSettings.setGLVersion(2, 1);
	ofCreateWindow(glWindowSettings);
	ofRunApp(new ofApp());
}
