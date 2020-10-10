//Elijah Story
//NMD211 Lab5
//10-9-2020

//Just blinks an LED

//To run, upload code

int pinIn = 13;         //use pin 13
int timeOn = 500;       //time in millsec
int timeOff = 1500;     //time in millsec

void setup() {
  pinMode(pinIn, OUTPUT);    //set pin 13 to put out current
}

void loop() {
  //turn LED on
  digitalWrite(pinIn, HIGH);  //write to pin pinIn with full power
  //wait
  delay(timeOn);  //wait based on timeOn
  //turn LED off
  digitalWrite(pinIn, LOW);   //write to pin pinIn with no power
  //wait
  delay(timeOff);  //wait based on timeOff
}
