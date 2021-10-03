// C++ code
// Code to display input from potentiometer on 7 seg display

// assigning a name for analog input pin
const int analogPin = A0;

//assigning pin numbers to output pins
const int pin1 = 10;
const int pin2 = 11;
const int pin3 = 12;
const int pin4 = 13;
const int pin5 = 6;
const int pin6 = 7;
const int pin7 = 8;
const int pin8 = 9;

//initializing varaiables to zero
int potentiometer = 0;
int outputValue = 0;
int tensPlace = 0;
int onesPlace = 0;
  
void setup()
    {
        pinMode(analogPin, INPUT);	//setting up input pin
  
        pinMode(pin1, OUTPUT);		//setting up output pins
        pinMode(pin2, OUTPUT);
        pinMode(pin3, OUTPUT);
        pinMode(pin4, OUTPUT);
        pinMode(pin5, OUTPUT);
        pinMode(pin6, OUTPUT);
        pinMode(pin7, OUTPUT);
        pinMode(pin8, OUTPUT);
  
        Serial.begin(9600);			// setting up to watch the output on serial monitor
    }

//function number one to display the number in unit place
void display1(int onesPlace)
    {
        digitalWrite(pin1, bitRead(onesPlace,0));
        digitalWrite(pin2, bitRead(onesPlace,1));
        digitalWrite(pin3, bitRead(onesPlace,2));
        digitalWrite(pin4, bitRead(onesPlace,3));
    }

//function number two to display the number in ten's place
void display2(int tensPlace)
    {
        digitalWrite(pin5, bitRead(tensPlace,0));
        digitalWrite(pin6, bitRead(tensPlace,1));
        digitalWrite(pin7, bitRead(tensPlace,2));
        digitalWrite(pin8, bitRead(tensPlace,3));
    }
  

void loop()
    {
        // Assigning value from potentiometer to a variable
        potentiometer = analogRead(analogPin);
  
        // Mapping the input to a value from 0 to 99
        outputValue = map(potentiometer,0,1023,0,99);
  
         // Assigning the variable in one's place to a variable
         // By taking remainder after dividing by ten
        onesPlace = outputValue%10;
  
        // Assigning the variable in ten's place to a variable
        // By taking integer quotient after dividing by ten
        tensPlace = outputValue/10;
  
        //Calling functions to display the output
        display1(onesPlace);
        display2(tensPlace);
  
        // To display the output in serial monitor
        // Not necessary for the program
        // Easier to debug
        Serial.print("sensor value   ");
        Serial.print(potentiometer);
        Serial.print(" output ");
        Serial.print(outputValue);
        Serial.print("    Tensplace   ");
        Serial.print(tensPlace);
        Serial.print(" ones Place ");
        Serial.print(onesPlace);
        Serial.print(" \n ");
  
       // A small delay of 1 millisecond between loops
        delay(100);

    }