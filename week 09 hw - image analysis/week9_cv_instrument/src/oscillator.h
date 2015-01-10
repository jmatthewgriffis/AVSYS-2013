//
//  oscillator.h
//  computer_vision
//
//  Created by J. Matthew Griffis on 4/9/13.
//
//

#ifndef __computer_vision__oscillator__
#define __computer_vision__oscillator__

#include <iostream>


#pragma once


#include "ofMain.h"


class oscillator {
    
public:
    
    int sampleRate;
    float frequency;
    float volume;
    float phase;
    float phaseAdder;
    
    void setup (int sampleRate);
    void setFrequency (float freq);
    void setVolume (float volume);
    
    float getSample();
    
};

#endif /* defined(__computer_vision__oscillator__) */
