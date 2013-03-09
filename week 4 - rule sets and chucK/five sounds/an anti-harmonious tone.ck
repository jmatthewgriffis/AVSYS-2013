// I present to you: Alien Spaceship

// This is adapted from my harmonious tone and has the same issue of the entire chord playing
// briefly before the delay kicks in. Hopefully there's an easy way to address that; I will ask.

// (Copied over the harmonious tone example:)
// EDIT: I posted the question to the AVSYS group and Bernardo figured
// out it was because I was leading with the time statement. By moving
// that to after all the if statements, I resolved the issue. Thanks B!

int counter;
int delay;
15 => delay;

//connect sine oscillator to dac:
SinOsc oscC => dac;
SinOsc oscCs => dac;
SinOsc oscE => dac;
SinOsc oscF => dac;
SinOsc oscCu => dac;

// thanks to this page: http://www.intmath.com/trigonometric-graphs/music.php
261.63 => oscC.freq; // (middle) C
277.18 => oscCs.freq; // C#
329.63 => oscE.freq; // E
349.23 => oscF.freq; // F
265.25 => oscCu.freq; // C up (above middle C)


while( true ) {
    counter ++;
    //<<<counter>>>; // Prints the value of the counter.

    // Delay the arrival of each note in the chord by manipulating the gain based on the counter:
   
    if (counter < delay) {
        0 => oscCs.gain;
    }
    else {
        1 => oscCs.gain;
    }
    
    if (counter < delay*2) {
        0 => oscE.gain;
    }
    else {
        1 => oscE.gain;
    }
    
    if (counter < delay*3) {
        0 => oscF.gain;
    }
    else {
        1 => oscF.gain;
    }
    
    if (counter < delay*5) {
        0 => oscCu.gain;
    }
    else {
        1 => oscCu.gain;
    }
   
    100::ms => now;
    
}