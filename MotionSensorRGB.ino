    /* Arduino PIR Motion sensor with RGB led */
     
    int inputPin = 2;               // Input pin for PIR
    int pirState = LOW;             // Variable for movement detection
    int pirVal = 0;                 // Variable to read pir
    int state = 0;                  // Variable to describe RGB led color
    
    int redPin = 10;                // Led pins
    int greenPin = 9;
    int bluePin = 8;
     
    void setup() {
      pinMode(inputPin, INPUT);     // Setup pins
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(bluePin, OUTPUT);  
      Serial.begin(9600);
    }
     
    void loop(){
      pirVal = digitalRead(inputPin);  // Read Pir input value
      
      if (pirVal == HIGH)              // Motion detected
      {
        if (pirState == LOW) 
        {
          state++;
          motionDetected(state);
        }
      } 
      else 
      {
        if (pirState == HIGH)          // Motion stopped
        {
          motionEnded();
        }
      }
    }
    
void setColor(int red, int green, int blue)  // set color for RGB
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
          
  delay(300);  
}

void motionDetected(int ledState)   // Choose the color for RBG
{
  Serial.println("Motion detected!");
  Serial.print("Led state: ");
  Serial.println(ledState);  
  pirState = HIGH;        
  
  switch (ledState) {
    case 1:
      setColor(0, 255, 0); // green
      break;
    case 2:
      setColor(0, 0, 255);  // blue
      break;
    case 3:
      setColor(0, 255, 255);  // aqua
      break;
    case 4:
      setColor(255, 255, 0);  // yellow
      break;
    case 5:
      setColor(80, 0, 80);  // purple
      break;
    case 6:
      setColor(255, 0, 0);  // red
      state = 0;
      break;
    default:
      break;
  }
}

void motionEnded()    // Motion stopped
{
  setColor(0, 0, 0);  // set led off
  Serial.println("Motion ended"); 
  pirState = LOW;
}
