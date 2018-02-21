//
//  ofxVezerRemoteControl.cpp
//  BasicSketch
//
//  Created by Oriol Ferrer Mesià on 20/02/2018.
//
//

#include "ofxVezerRemoteControl.h"

ofxVezerRemoteControl::ofxVezerRemoteControl(){

}

void ofxVezerRemoteControl::setup(string vezerIp, int vezerOscInPort, int vezierFeedbackOutPort){
	sender.setup(vezerIp, vezerOscInPort);
	rx.setup(vezierFeedbackOutPort);
}

void ofxVezerRemoteControl::update(){

	while(rx.hasWaitingMessages()){
		ofxOscMessage m;
		rx.getNextMessage(m);
		if(m.getAddress() == "/vezer/current/playhead"){
			float time = m.getArgAsFloat(0);
			ofNotifyEvent(eventPlayHeadUpdated, time, this);
		}else{
			//ofLogNotice() << "Unknown msg from Vezér: \"" << m.getAddress() << "\"";
		}
	}

	ofxOscMessage m;
	m.setAddress("/vezer/currentcompinfo");
	sender.sendMessage(m);
}

//control playhead
void ofxVezerRemoteControl::setPlayheadNormalized(float timelinePct, const string & composition){
	ofxOscMessage m;
	m.setAddress("/vezer/" + composition + "/playhead");
	m.addFloatArg(timelinePct);
	sender.sendMessage(m);
}

void ofxVezerRemoteControl::setPlayheadFrame(int frameNum, const string & composition){
	ofxOscMessage m;
	m.setAddress("/vezer/" + composition + "/jumptoframe");
	m.addIntArg(frameNum);
	sender.sendMessage(m);
}

void ofxVezerRemoteControl::advancePlayheadOneFrame(const string & composition){
	ofxOscMessage m;
	m.setAddress("/vezer/" + composition + "/nextframe");
	sender.sendMessage(m);
}

void ofxVezerRemoteControl::recedePlayheadOneFrame(const string & composition){
	ofxOscMessage m;
	m.setAddress("/vezer/" + composition + "/prevframe");
	sender.sendMessage(m);
}


//compositions
void ofxVezerRemoteControl::setCompositionEnabled(bool enabled, const string & composition){
	ofxOscMessage m;
	m.setAddress("/vezer/" + composition + "/enable");
	m.addIntArg(enabled ? 1 : 0);
	sender.sendMessage(m);
}

void ofxVezerRemoteControl::playPauseComposition(bool play, const string & composition){
	ofxOscMessage m;
	m.setAddress("/vezer/" + composition + "/play");
	m.addIntArg(play ? 1 : 0);
	sender.sendMessage(m);
}

void ofxVezerRemoteControl::rewindComposition(const string & composition){
	ofxOscMessage m;
	m.setAddress("/vezer/" + composition + "/rewind");
	sender.sendMessage(m);
}

void ofxVezerRemoteControl::setLoopComposition(bool loop, const string & composition){
	ofxOscMessage m;
	m.setAddress("/vezer/" + composition + "/loop");
	sender.sendMessage(m);
}

//global
void ofxVezerRemoteControl::playAllCompositions(){
	ofxOscMessage m;
	m.setAddress("/vezer/playall");
	sender.sendMessage(m);
}

void ofxVezerRemoteControl::rewindAllCompositions(){
	ofxOscMessage m;
	m.setAddress("/vezer/rewindall");
	sender.sendMessage(m);
}


//cues
void ofxVezerRemoteControl::jumpToCueAtIndex(int queueIndex, bool startPlaying, const string & composition){
	ofxOscMessage m;
	if(startPlaying == false){
		m.setAddress("/vezer/" + composition + "/jumptocueatindex");
	}else{
		m.setAddress("/vezer/" + composition + "/playcueatindex");
	}
	m.addIntArg(queueIndex);
	sender.sendMessage(m);
}

void ofxVezerRemoteControl::jumpToCueWithName(const string & cueName, bool startPlaying, const string & composition){
	ofxOscMessage m;
	if(startPlaying == false){
		m.setAddress("/vezer/" + composition + "/jumptocuewithname");
	}else{
		m.setAddress("/vezer/" + composition + "/playcuewithname");
	}
	m.addStringArg(cueName);
	sender.sendMessage(m);
}

void ofxVezerRemoteControl::resetCueStates(const string & composition){
	ofxOscMessage m;
	m.setAddress("/vezer/" + composition + "/resetcuestates");
	sender.sendMessage(m);
}
