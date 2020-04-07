int redPin= 12;
int greenPin = 27;
int bluePin = 33;

int redPin2= 15;
int greenPin2 = 32;
int bluePin2 = 14;

int pressedButton = A0;
int counter = 0; //keeps count of the presses
 
void setup() {
    // initialize serial communication at 9600 bits per second:
   
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  pinMode(pressedButton, INPUT);


  }
void loop() {
  int buttonState = digitalRead(pressedButton);
  Serial.println(buttonState);
  delay(30);

  Serial.println(counter);
  delay(30);

  //starting the code / counting upon presses
  if(buttonState == HIGH){
    counter++;
    delay(100);
   }

   else if(counter == 1){
    //This will blink white for both RGB LEDS untill pushed again
    Serial.println("This should turn the LEDS WHITE"); //debug message
    RGB_1(255, 255, 255); // White
    delay(200);
    RGB_2(255, 255, 255); // White
    delay(200);
    
    }

   //resetting counter back to zero to reset 
   else{
    counter = 0;
    RGB_1(255, 255, 255); // White
    RGB_2(255,255 ,255); // Yellow
    delay(10000);
    digitalWrite(redPin, HIGH);//Red
    digitalWrite(greenPin2, HIGH); // Green
    digitalWrite(redPin, LOW);//Red
    digitalWrite(greenPin2, LOW); // Green
    delay(5000);
    RGB_1(255,255 ,0); // Yellow
    RGB_2(255,255 ,0); // Yellow
    delay(5000);
    digitalWrite(redPin2, HIGH);//Red
    digitalWrite(greenPin, HIGH); // Green
    delay(5000);
    RGB_1(255,255 ,0); // Yellow
    RGB_2(255,255 ,0); // Yellow
 

    }
   
}

// These functions set the colors for yellow
void RGB_1(int redValue, int greenValue, int blueValue)
 {
  digitalWrite(redPin, redValue);
  digitalWrite(greenPin, greenValue);
  digitalWrite(bluePin, blueValue);

}
void RGB_2(int redValue, int greenValue, int blueValue)
 {
  digitalWrite(redPin2, redValue);
  digitalWrite(greenPin2, greenValue);
  digitalWrite(bluePin2, blueValue);

}
