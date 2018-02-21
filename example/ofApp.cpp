#include "ofApp.h"


void ofApp::setup(){

	//setup to rx vezer OSC timeline flags
	ofAddListener(vezerFlags.eventVezerOscFlag, this, &ofApp::onVezerOscFlag);
	vezerFlags.setup(8000);

	//setup to be able to control vezér and rx feedback from it
	ofAddListener(vezer.eventPlayHeadUpdated, this, &ofApp::onVezerPlayheadChanged);
	vezer.setup("127.0.0.1", 1234, 8100);

}

void ofApp::onVezerOscFlag(ofxOscMessage & eventMsg){
	ofLogNotice() << ofGetFrameNum() << " - onVezerOscFlag: \"" << eventMsg.getAddress() << "\"";
}

void ofApp::onVezerPlayheadChanged(float & pct){

	ofLogNotice() << "playhead " << pct;
}

void ofApp::update(){

	float dt = 1./60.;
	vezer.update();
}


void ofApp::draw(){

}


void ofApp::keyPressed(int key){

	if(key == '1'){
		vezer.setPlayheadNormalized(ofRandom(1));
	}

	if(key == '2'){
		vezer.jumpToCueWithName("myCue1", true);
	}

	if(key == '3'){
		vezer.jumpToCueWithName("myCue2", true);
	}

}


void ofApp::keyReleased(int key){

}


void ofApp::mouseMoved(int x, int y ){

}


void ofApp::mouseDragged(int x, int y, int button){

}


void ofApp::mousePressed(int x, int y, int button){

}


void ofApp::mouseReleased(int x, int y, int button){

}


void ofApp::windowResized(int w, int h){

}


void ofApp::gotMessage(ofMessage msg){

}


void ofApp::dragEvent(ofDragInfo dragInfo){
	
}

