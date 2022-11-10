#include <DS3231.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


DS3231  rtc(SDA, SCL);

int buzzer = 7;
int LED = 6;

Time t;

const int OnHour = 23;
const int OnMin = 22;
const int OffHour = 23;
const int OffMin = 23;

LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  Serial.begin(9600);
 
  rtc.begin();
 
  rtc.setDOW(FRIDAY);     
  rtc.setTime(23, 21, 50);     
  rtc.setDate(04, 11, 2022);   

  lcd.init();                       
  lcd.init();
  
  lcd.backlight();
     
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW); 
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW); 


}

void loop()
{
  t = rtc.getTime();
  
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
 
  Serial.println(rtc.getTimeStr());
  lcd.print(rtc.getTimeStr());
 
  delay (1000);
  lcd.clear();
  
  if(t.hour == OnHour && t.min == OnMin ){
    digitalWrite(buzzer,HIGH);
    Serial.println("BUZZER ON");
    digitalWrite(LED,HIGH);
    Serial.println("LIGHT ON"); 
    lcd.println("medicine!"); 
    }
    
   else if(t.hour == OffHour && t.min == OffMin){
      digitalWrite(buzzer,LOW);
      Serial.println("BUZZER OFF");
      digitalWrite(LED,LOW);
      Serial.println("LIGHT OFF");
    }
    
 
}


 
