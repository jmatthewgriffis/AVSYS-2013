// I did this harmony assignment first, and immediately got a crash course / reminder in the
// subtleties of chucK and miniAudicle. I created the four oscillators and sent their data to the
// dac, then set their frequencies below, as you can see. I was commenting out the different
// frequency settings to test the different pitches, and it was the strangest thing - when I
// uncommented all four frequency settings, the chord sounded correct. But if I commented
// out even one of them, I heard an A tone beneath the other notes. I couldn't figure out why - 
// was this over/under tones? Well, I finally remembered it was because it's not setting the
// frequency that turns an oscilllator on or off - it's sending its data to the dac. If you don't set
// the freqency it just defaults to...an A tone. That explains that.

// After finishing this I notice that the whole chord plays right at the start before being cut off
// so the normal progression occurs. I am guessing this is due to the full contents of the while
// loop (which adjusts the gain) not coming into effect right away. I'd like to fix it but I don't
// know how.

int counter;
int delay;
15 => delay;

//connect sine oscillator to dac:
SinOsc oscC => dac;
SinOsc oscE => dac;
SinOsc oscG => dac;
SinOsc oscAs => dac;
SinOsc oscCu => dac;

// set the Oscs' frequency to create musical notes for a simple jazz chord in C;
// thanks to this page: http://www.intmath.com/trigonometric-graphs/music.php
261.63 => oscC.freq; // (middle) C
329.63 => oscE.freq; // E
392.00 => oscG.freq; // G
466.16 => oscAs.freq; // A#
523.25 => oscCu.freq; // C up (above middle C)


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