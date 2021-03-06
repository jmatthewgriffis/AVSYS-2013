#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "midiToFreqConverter.h"
#include "sinOscillator.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
	
		//void resetSequencer(); //resets the sequencer
	
		//void setBPM(int targetBPM); // sets the BPM for the system
	
		void audioRequested(float * input, int bufferSize, int nChannels); 

		//bool notes[32][24]; //grid of positions for notes in our sequencer
	
		sinOscillator notePlayer[4]; //a sin oscillator for every note. this is important in case multiple notes play at the same time

		midiToFreqConverter midi; //to get the note value
	
		//int sequencerPosition; // where the sequencer is in its playthrough
		//int bpmInt; // the beats per minute as an integer
		//float bpm; // the bpm as a float representing the number of seconds between each beat
		//float noteLength; // length of time each note will play
		
		//float lastNoteStartTime; // the time in seconds that the last note started playing, used for knowing when to stop the notes and when to move to the next note

		//bool setVal; // what value do we use when we drag, are we turning on or off notes?
};

#endif
