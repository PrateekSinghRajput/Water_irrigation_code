//Prateek
//www.prateeks.in

#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);


int m;
int percentage;
int led = 5;
int map_low = 1023;
int map_high = 280;
void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT_PULLUP);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
Serial.begin(9600);
 lcd.begin(16,2);
 lcd.clear();
  lcd.setCursor(0,0); // column, row
  lcd.print("Irrigation Systm"); 
  lcd.setCursor(0,1); // column, row
  lcd.print("Pump=");
   lcd.setCursor(10,1); // column, row
  lcd.print("M= ");

}

void loop() {
 int m= analogRead(A0);
Serial.println(m);
percentage = map(m, map_low, map_high, 0, 100);
 lcd.setCursor(10,1); // column, row
  lcd.print("M= ");
  if (percentage>100)
  {
    percentage = 100;
  }
 lcd.setCursor(12,1); // column, row
  lcd.print(percentage);
  lcd.print ("%");
  lcd.print ("  ");
  delay(200);
if (m>=780) //==> increase or decrease this value (between 1023 to 280) to change
            // the water pump on/off percent value (currently set to 33%)
            // this value shoud be 10 number higher then the value below.
{
  digitalWrite(4, HIGH);
  lcd.setCursor(6,1); // column, row
  lcd.print("ON ");
  digitalWrite (led,LOW);
  
  }

else if(m<=770) //=> increase or decrease this value (between 1023 to 280) to change
                // the water pump on/off percent value (currently set to 33%)
{
  digitalWrite(4, LOW);
  lcd.setCursor(6,1); // column, row
  lcd.print("OFF");
  digitalWrite (led,HIGH);
  }
  

}
