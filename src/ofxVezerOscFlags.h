//
//  ofxVezerOscFlags.h
//  BasicSketch
//
//  Created by Oriol Ferrer Mesià on 20/02/2018.
//
//

#pragma once
#include "ofMain.h"
#include "ofxOscReceiver.h"

class ofxVezerOscFlags{

public:

	void setup(int vezerOscOutPort);
	void update();

	ofEvent<ofxOscMessage> eventVezerOscFlag;

protected:

	ofxOscReceiver rx;
};

