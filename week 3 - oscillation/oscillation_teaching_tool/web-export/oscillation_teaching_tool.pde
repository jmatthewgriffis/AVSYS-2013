PFont font;
float W;
float H;
int rad;
float xPos;
float xPos2;
float yPos;
int inc;
int gameState;
int totalSlides;

void setup() {

  size(600, 600);
  frameRate(60);
  smooth();
  noFill();

  strokeWeight(5);
  textAlign(CENTER);
  font = loadFont("font.vlw");
  textFont(font, 24);

  gameState = 1;
  totalSlides = 20;
  rad = 150;
  W = width/2;
  H = height/2;
  inc = 0;
  xPos2= 0;
}

void draw() {

  background(125);

  inc++;
  if (inc > 360*60) {
    inc = 0;
  }
  xPos = sin(inc/60) * rad;
  yPos = cos(inc/60) * rad;
  xPos2++;
  if (xPos2 > width) {
    xPos2 = 0;
  }

  // Show the screen count and arrow cues:
  fill(255);
  if (gameState > 1) {
    text("<--", 25, height-10);
  }
  if (gameState < totalSlides) {
    text("-->", width-25, height-10);
  }
  text(gameState + "/" + totalSlides, W, height-10);
  fill(0);

  if (gameState == 1) {

    fill(0);
    text("Let's learn about oscillation.", W, H);
  }

  if (gameState == 2) {

    fill(0);
    text("Oscillation is a scary term,\n\nbut it's not so bad.\n\nIt starts with a circle.", W, H-50);
  }

  if (gameState == 3) {

    fill(0);
    text("Watch the ball.\nIt has 'periodic' movement.\nVery important for oscillation.", W, 50);
    text("Periodic movement recurs endlessly, and always takes\nthe same amount of time to complete (the 'period').", W, height-100);

    noFill();
    ellipseMode(RADIUS);
    ellipse(W, H, rad, rad);
    pushMatrix();
    translate(W, H);
    fill(255);
    stroke(255);
    ellipse(xPos, yPos, rad/10, rad/10);
    stroke(0);
    noFill();
    popMatrix();
  }

  if (gameState == 4) {

    text("Now imagine you are looking at that circle from the side.\n\nWhat does the ball's movement look like?", W, H-25);
  }

  if (gameState == 5) {

    text("Something like this, perhaps?", W, 100);
    text("I'm just kidding ya. That's exactly what it looks like.", W, height-75);

    line(W, H-rad, W, H+rad);
    pushMatrix();
    translate(W, H);
    fill(255);
    stroke(255);
    ellipse(0, yPos, rad/10, rad/10);
    stroke(0);
    noFill();
    popMatrix();
  }
  
  if (gameState == 6) {
    
    text("'I was told there'd be oscillation,' you assert.\n\nHold yer horses.\n\nWe're getting there.", W, H-50);
  }
  
  if (gameState == 7) {
    
    text("Now...imagine tracking that ball through time.\n\n\nHuh? ", W, H-50);
  }
  
  if (gameState == 8) {
    
    text("Well, we'll look at the circle from the side again,\nbut set the ball free from the circle's tyrannical bounds.\n\n\nWhat?", W, H-75);
  }
  
  if (gameState == 9) {
    
    text("Sigh.", W, H);
  }
  
  if (gameState == 10) {

    text("OK, remember this? Yeah you do.", W, 100);
    text("The ball traces a vertical path periodically,\nbut it stays in one place horizontally\nbecause the side view of the circle has no x-axis.", W, height-100);

    line(W, H-rad, W, H+rad);
    pushMatrix();
    translate(W, H);
    fill(255);
    stroke(255);
    ellipse(0, yPos, rad/10, rad/10);
    stroke(0);
    noFill();
    popMatrix();
  }
  
  if (gameState == 11) {

    text("What if we let the x-axis represent something other\nthan spatial position? Something like...time?\n\n\nThe ball bounces from from top to bottom to top,\nbut it can only move one direction in time.", W, H-75);
  }
  
  if (gameState == 12) {

    text("Track the ball's periodic vertical movement\nwhile tracing its passage through time and you get this:", W, 50);
    text("Position", W, H-rad-7);
    text("Time", W-235, H+7);
    text("(The ball may appear to repeat its horizontal course,\nbut don't be fooled.\nYour screen cannot contain the mysteries of time.)", W, height-100);
    
    line(W, H-rad, W, H+rad);
    line(100, H, width-100, H);
    pushMatrix();
    translate(0, H);
    fill(255);
    stroke(255);
    ellipse(xPos2, yPos, rad/10, rad/10);
    stroke(0);
    noFill();
    popMatrix();
  }
  
  if (gameState == 13) {

    text("OSCILLATION.", W, H);
  }
}

void keyPressed() {

  if (keyCode == LEFT) {
    if (gameState > 1) {
      gameState--;
    }
  }

  if (keyCode == RIGHT) {
    if (gameState < totalSlides) {
      gameState++;
    }
  }
}


