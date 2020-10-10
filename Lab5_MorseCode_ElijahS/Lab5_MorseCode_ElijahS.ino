//Elijah Story
//NMD211 Lab5
//10-9-2020

//Morse Code
//blinks morse code for a sentance set in the code.
//The serial port is used to make it easier to usderstand what is happening.


//global variables
int pinIn = 13;         //use pin 13

//I kept the timings from lab because the math for the real thing looked too complicated
int dot = 300;          //how long a dot is in millsec
int dash = 1200;        //how long a dash is in millsec
int dotDashWait = 100;       //how long a space between dot and dashes is in millsec
int letterWait = 300;       //how long a space between letters is in millsec
int wordWait = 2000;      //how long a space between words is in millsec

//this is where I store what each letter is in morse code
String alphabet[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                     "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                     "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                     "-.--", "--.."};
                     
//this is the sentence that will be displayed.
//it can be replaced, but it should be all lowercase and not characters other than SPACE and letters
String sentence = "i hope this works";
String code;//this will hold the morse code for current letter

void setup() {
  Serial.begin(9600);        //sets up the serial monitor
  pinMode(pinIn, OUTPUT);    //set pin 13 to put out current
}

void loop() {
  for (int i = 0; i < sentence.length(); i++) {//loops for each character in sentence
    if (sentence[i] != ' ') { //if curr character not space
      temp = alphabet[(int)sentence[i] - 97]; //uses ascii to find index for the code

      //just prints
      Serial.println(sentence[i]);
      Serial.println(temp);

      for (int k = 0; k < temp.length(); k++) { //loops for length of code
        if (temp[k] == '.') { //if dot, call makeDot()
          makeDot();
          delay(dotDashWait);
        } else {            //if dash, call makeDash()
          makeDash();
          delay(dotDashWait);
        }
      }
      delay(letterWait);  //adds delay after the letter
    } else {
      delay(wordWait);  //this gose back to if curr index is SPACE. it adds delay between words
    }
  }
}

//blinks for a dot
void makeDot() {
  digitalWrite(pinIn, HIGH);    //dot on and off
  delay(dot);
  digitalWrite(pinIn, LOW);
}

//blinks for a dash
void makeDash() {
  digitalWrite(pinIn, HIGH);    //dash on and off
  delay(dash);
  digitalWrite(pinIn, LOW);
}
