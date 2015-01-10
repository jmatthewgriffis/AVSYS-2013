// This sounds like what I imagine for when you're stuck in a cloud - slightly oppresive, cut off
// from the outside world, maybe some electrical interference. Very sci-fi. The low tone really
// sells it. I picked random frequencies to find what sounded appropriate.

// (adapted from my harmonious tone)

int counter;
int delay;
15 => delay;

//connect sine oscillator to dac:
SinOsc osc1 => dac;
SinOsc osc2 => dac;

277.18 => osc1.freq; // ?
190.34 => osc2.freq; // ?

while( true ) {
    counter ++;
    //<<<counter>>>; // Prints the value of the counter.
    100::ms => now;
}