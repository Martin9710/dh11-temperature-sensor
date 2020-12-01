// Include libraries
#include <dht.h>
#include <LiquidCrystal.h>

// The setup routine runs once when you press reset:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;
#define DHT11_PIN 7

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  lcd.begin(16, 2);
}

// the loop routine runs over and over again forever:
void loop(){
  int chk = DHT.read11(DHT11_PIN); // Fills var chk with value from DHT.
  lcd.setCursor(0,0); //Begins at start of line on LCD
  lcd.print("Temp: "); // Prints Temp:
  lcd.print(DHT.temperature); //Prints the value of DHT.temperature
  lcd.print((char)223); //Prints the char °
  lcd.print("C"); //Prints C
  lcd.setCursor(0,1); //Begin a new line on LCD
  lcd.print("Humidity: "); //Prints Humidity:
  lcd.print(DHT.humidity);//Prints the value of DHT.humidity
  lcd.print("%");//Prints %
  delay(1000); // Waits for one second (ms)

  if (DHT.temperature < 25) { //Checks if value of temp is less than 25
    digitalWrite(13, HIGH); // Turns on Green LED light
    delay(1000); // Waits for one sec
    digitalWrite(13, LOW); //Turn down the Green LED Light
    delay(1000); // Waits for one sec
  }
  else { //Checks if value of temp is above 25
    digitalWrite(14, HIGH); // Turns on Red LED light
    delay(1000); // Waits for one sec
    digitalWrite(14, LOW); // Turns down Red LED light
    delay(1000); // Waits for one sec  
  }
 delay(1000); // Update sensor reading each second (ms)
}

