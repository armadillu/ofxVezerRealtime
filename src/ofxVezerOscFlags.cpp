//
//  ofxVezerOscFlags.cpp
//  BasicSketch
//
//  Created by Oriol Ferrer Mesià on 20/02/2018.
//
//

#include "ofxVezerOscFlags.h"


void ofxVezerOscFlags::setup(int vezerOscOutPort){
	rx.setup(vezerOscOutPort);
}

void ofxVezerOscFlags::update(){
	while(rx.hasWaitingMessages()){
		ofxOscMessage m;
		rx.getNextMessage(m);
		ofNotifyEvent(eventVezerOscFlag, m, this);
	}
}
