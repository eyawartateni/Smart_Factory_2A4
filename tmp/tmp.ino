#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(13);
DallasTemperature sensors(&oneWire);

int led = 12; // pin 12
int buzzer = 11;
char data;


void setup()
{
  sensors.begin();
  Serial.begin(9600);
}

void loop() 
{
  sensors.requestTemperatures();
  double tempC = sensors.getTempCByIndex(0);
  Serial.print("Temp C: ");
  Serial.print(tempC);
  Serial.print(" Temp F: ");
  Serial.println(DallasTemperature::toFahrenheit(tempC)); // Converts tempC to Fahrenheit
  if(tempC>16.25)
  {
    digitalWrite(led, HIGH);
    tone(buzzer,500);
    delay(500);
  }
  else
  {
    digitalWrite(led, LOW);
    noTone(buzzer);
  }

  if(Serial.available())
  {
    data=Serial.read();
    if(data=='0')
   {
    digitalWrite(led,LOW);
    noTone(buzzer);
    Serial.write('0');
    delay(10000);
   }

  
  }
  delay(1000);
}
