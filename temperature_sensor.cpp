#include <dht.h>
// the setup routine runs once when you press reset:
dht DHT;
#define DHT11_PIN 7

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int chk = DHT.read11(DHT11_PIN);
  // Convert the analog volt so its temperature equivalent:
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature); //Display temp value
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity); //Display humidity value
  delay(1000); // Update sensor reading each second (ms)
  
  if (chk < 30) {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
  else {
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    delay(1000);    
  }
 delay(1000); // Update sensor reading each second (ms)
}

