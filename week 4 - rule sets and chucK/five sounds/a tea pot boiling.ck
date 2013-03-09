/* I'm not entirely happy with this one - it turns out making organic sounds is much harder (I 
guess that's no surprise). Initially I was going to aim for a bubbling sound, and then I realized
that's already a separate assignment, and it might be more interesting to make the sound kettles
make when they boil to let you know they're boiling. So I set a starting point and an upper limit 
for the frequency and the program adds to it until it reaches the max. */

// EDIT: Zach suggested using additional octaves for a richer tone.

// (adapted from my harmonious tone)

int counter;
int delay;
15 => delay;
int whistleMin;
1400 => whistleMin;
int whistleMax;
1760 => whistleMax;
int inc;
10 => inc;

//connect sine oscillator to dac:
SinOsc osc => dac;

while( true ) {
    counter ++;
    <<<whistleMin>>>; // Prints the value of the variable.
    
    whistleMin => osc.freq; // ?
    
    if (whistleMin < whistleMax) {
        whistleMin + inc => whistleMin;
    }
    100::ms => now;    
}