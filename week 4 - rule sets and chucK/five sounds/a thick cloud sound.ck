// This sounds like what I imagine for when you're stuck in a cloud - slightly oppresive, cut off
// from the outside world, maybe some electrical interference. Very sci-fi. The low tone really
// sells it. I picked random frequencies to find what sounded appropriate.

// (adapted from my harmonious tone)

int counter;
int delay;
15 => delay;

//connect sine oscillator to dac:
//SinOsc oscC => dac;
SinOsc oscE => dac;
SinOsc oscG => dac;
//SinOsc oscAs => dac;
//SinOsc oscCu => dac;

// thanks to this page: http://www.intmath.com/trigonometric-graphs/music.php
//60.0 => oscC.freq; // ? (I was using this then realized it's inaudible.)
277.18 => oscE.freq; // ?
190.34 => oscG.freq; // ?
//349.23 => oscAs.freq; // Actually this is F
//265.25 => oscCu.freq; // C up (above middle C)


while( true ) {
    counter ++;
    //<<<counter>>>; // Prints the value of the counter.
    100::ms => now;
    

   // Delay the arrival of each note in the chord by manipulating the gain based on the counter:
  /* 
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
   */
    
}