//
//  ofxVezerRealtime.h
//  BasicSketch
//
//  Created by Oriol Ferrer Mesià on 20/02/2018.
//
//

#pragma once
#include "ofMain.h"
#include "ofxOscSender.h"
#include "ofxOscReceiver.h"

class ofxVezerRealtime{

public:
	
	ofxVezerRealtime();
	void setup(string vezerIp, int vezerOSCinPort, int vezierFeedbackOutPort);

	void update();

	//control composition playhead
	void setPlayheadNormalized(float timelinePct, const string & composition = "current");
	void setPlayheadFrame(int frameNum, const string & composition = "current");
	void advancePlayheadOneFrame(const string & composition = "current");
	void recedePlayheadOneFrame(const string & composition = "current");

	//compositions
	void setCompositionEnabled(bool enabled, const string & composition = "current");
	void playPauseComposition(bool play, const string & composition = "current");
	void rewindComposition(const string & composition = "current");
	void setLoopComposition(bool loop, const string & composition = "current");


	//global
	void playAllCompositions();
	void rewindAllCompositions();

	//cues
	void jumpToCueAtIndex(int queueIndex, bool startPlaying, const string & composition = "current");
	void jumpToCueWithName(const string & cueName, bool startPlaying, const string & composition = "current");
	void resetCueStates(const string & composition = "current");


	//Vezér Feedback - get info from Vezér regarding the timeline & composition states
	//these need OSC feedback enabled in Vezér - using the "vezerOscOutPort" OSC output in Vezér

	ofFastEvent<float> eventPlayHeadUpdated;

	//ofFastEvent<string> eventCompositionSelected;


protected:

	ofxOscSender sender;
	ofxOscReceiver rx;
};

