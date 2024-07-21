import processing.serial.*;
Serial myPort;

PImage logo;
int bgcolor = 0;

void setup() {
  size(1, 1);
  surface.setResizable(true);
  colorMode(HSB, 255);
  logo = loadImage("https://brandslogos.com/wp-content/uploads/images/large/arduino-logo-1.png");
  surface.setSize(logo.width, logo.height);
  println("Available Serial Ports: "); 
  println(Serial.list());
  myPort = new Serial(this, "/dev/cu.usbmodem101", 9600);
}

void draw() {
  if (myPort.available() > 0) {
    bgcolor = myPort.read();
    println(bgcolor);
  }
  
  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}