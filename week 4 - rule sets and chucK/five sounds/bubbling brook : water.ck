/*  */

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
SinOsc oscC => dac;
//SinOsc oscE => dac;
//SinOsc oscG => dac;
//SinOsc oscAs => dac;
//SinOsc oscCu => dac;

// thanks to this page: http://www.intmath.com/trigonometric-graphs/music.php
170 => oscC.freq;
//1100 => oscE.freq; // ?
//190.34 => oscG.freq; // ?
//349.23 => oscAs.freq; // Actually this is F
//265.25 => oscCu.freq; // C up (above middle C)

while( true ) {
    counter ++;
    //<<<whistleMin>>>; // Prints the value of the variable.
    
    /*whistleMin => oscC.freq; // ?
    
    if (whistleMin < whistleMax) {
        whistleMin + inc => whistleMin;
    }*/
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