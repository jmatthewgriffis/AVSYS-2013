// I present to you: Alien Spaceship

// This is adapted from my harmonious tone and has the same issue of the entire chord playing
// briefly before the delay kicks in. Hopefully there's an easy way to address that; I will ask.

int counter;
int delay;
15 => delay;

//connect sine oscillator to dac:
SinOsc oscC => dac;
SinOsc oscE => dac;
SinOsc oscG => dac;
SinOsc oscAs => dac;
SinOsc oscCu => dac;

// thanks to this page: http://www.intmath.com/trigonometric-graphs/music.php
261.63 => oscC.freq; // (middle) C
277.18 => oscE.freq; // Actually this is C#
329.63 => oscG.freq; // Actually this is E
349.23 => oscAs.freq; // Actually this is F
265.25 => oscCu.freq; // C up (above middle C)


while( true ) {
    counter ++;
    //<<<counter>>>; // Prints the value of the counter.
    100::ms => now;
    

   // Delay the arrival of each note in the chord by manipulating the gain based on the counter:
   
   if (counter < delay) {
       0 => oscE.gain;
   }
   else {
       1 => oscE.gain;
   }
   
   if (counter < delay*2) {
       0 => oscG.gain;
   }
   else {
       1 => oscG.gain;
   }
   
   if (counter < delay*3) {
       0 => oscAs.gain;
   }
   else {
       1 => oscAs.gain;
   }
   
   if (counter < delay*5) {
       0 => oscCu.gain;
   }
   else {
       1 => oscCu.gain;
   }
   
    
}