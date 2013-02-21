PFont font;
float centerW;
float centerH;
int rad;
int xPos;
int yPos;
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
  totalSlides = 4;
  rad = 150;
  centerW = width/2;
  centerH = height/2;
  inc = 0;
}

void draw() {

  background(125);
  
  // Show the screen count and arrow cues:
    fill(255);
    if (gameState > 1) {
      text("<--", 25, height-10);
    }
    if (gameState < totalSlides) {
      text("-->", width-25, height-10);
    }
    text(gameState + "/" + totalSlides, centerW, height-10);
    fill(0);

  if (gameState == 1) {
    
    fill(0);
    text("Let's learn about oscillation.", centerW, centerH);
  }
  
  if (gameState == 2) {
    
    fill(0);
    text("Oscillation is a scary term,\n\nbut it's not so bad.\n\nIt starts with a circle.", centerW, centerH-50);
  }

  if (gameState == 3) {

    inc++;
    xPos = sin(inc/60) * rad;
    yPos = cos(inc/60) * rad;

    fill(0);
    text("Watch the ball.\nThis is 'periodic' movement.", centerW, 100);

    noFill();
    ellipseMode(RADIUS);
    ellipse(centerW, centerH, rad, rad);
    pushMatrix();
    translate(centerW, centerH);
    fill(255);
    stroke(255);
    ellipse(xPos, yPos, rad/10, rad/10);
    stroke(0);
    noFill();
    popMatrix();
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

