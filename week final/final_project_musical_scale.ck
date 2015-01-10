//connect sine oscillator to dac:
//go through a full octave in C. use a "base" note one octave down to add richness:
//SinOsc oscCmiddle => dac;
//SinOsc oscCmiddleBase => dac;
//SinOsc oscD => dac;
//SinOsc oscDbase => dac;
//SinOsc oscE => dac;
//SinOsc oscEbase => dac;
//SinOsc oscF => dac;
//SinOsc oscFbase => dac;
//SinOsc oscG => dac;
//SinOsc oscGbase => dac;
//SinOsc oscA => dac;
//SinOsc oscAbase => dac;
//SinOsc oscB => dac;
//SinOsc oscBbase => dac;
//SinOsc oscChigh => dac;
//SinOsc oscChighBase => dac;

// set the Oscs' frequency to create musical notes for a scale in the key of C.
// thanks to this page: http://www.phy.mtu.edu/~suits/notefreqs.html
//261.63 => oscCmiddle.freq;
//261.63/2 => oscCmiddleBase.freq;
//293.66 => oscD.freq;
//293.66/2 => oscDbase.freq;
//329.63 => oscE.freq;
//329.63/2 => oscEbase.freq;
//349.23 => oscF.freq;
//349.23/2 => oscFbase.freq;
//392.00 => oscG.freq;
//392.00/2 => oscGbase.freq;
//440.00 => oscA.freq;
//440.00/2 => oscAbase.freq;
//493.88 => oscB.freq;
//493.88/2 => oscBbase.freq;
//523.25 => oscChigh.freq;
//523.25/2 => oscChighBase.freq;


while( true ) {
    
    // play the sound constantly by adding time:    
    100::ms => now;
    
}