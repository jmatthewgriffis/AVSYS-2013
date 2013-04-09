// This is Zach's example from GitHub, which I've modified (mostly through the
// oF project that goes with this):

SinOsc osc; // => dac; // Creates an oscillator object. We don't send it to the sound card yet.
JCRev r; // I'm not sure what this does. I'm guessing it is a receiver of some kind.
r => dac; // Send that to the sound card.
.03 => r.mix; // No clue here.
// set the Osc?s frequency to 60.0 hz


// create our OSC receiver
OscRecv recv;
// use port 9999
9999 => recv.port;
// start listening (launch thread)
recv.listen();

// create an address in the receiver, store in new variable
recv.event( "/playtone, f" ) @=> OscEvent oe; // Yeah I don't know about this either.

// infinite event loop
while ( true )
{
    // wait for event to arrive
    oe => now;
    
    // grab the next message from the queue. 
    while ( oe.nextMsg() != 0 )
    { 
        float temp;
        // getFloat fetches the expected float (as indicated by "f")
        oe.getFloat() => temp;
        // set play pointer to beginning
        temp => osc.freq;
        osc => r;
        100::ms => now;
        osc =< r;
    }
}
