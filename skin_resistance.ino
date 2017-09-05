// updated by wangxiguang 
// Date : 2017.8.29
// For Skin resistance value and GSR measure 
// apply with Arduino UNO module and 2M resistance

int ledPin = 13;
int button = 8;
int Num = 0;

//Time
int sec = 0;
int minuti = 0;
int hour = 0;

//GRS
float Res_people = 0;
float Voltage_adc = 0;

int grsSensor = A0;
int gsrVal = 0;

void setup()
{
  //init seriale
  Serial.begin(57600);
  digitalWrite(button,HIGH);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  
  Serial.print("GSRval");
  Serial.print(" ");
  Serial.print("Res_people(KΩ)");
  Serial.print(" ");
  Serial.print("Num :");
  Serial.println("");
}
 
void loop()
{  


  //long int sum;
  //1 sec delay
 if(millis()%20==0)
 {
  digitalWrite(ledPin,HIGH);
  //Value GSR

  gsrVal = analogRead (grsSensor);  
  Voltage_adc =(gsrVal / 1024.0) * 5.0;
  Res_people = (Voltage_adc * 2000.0) / ( 5.0 - Voltage_adc) ;

  
  
  if(LOW == digitalRead(button))
  {
    delay(1000);
    
    if(HIGH == digitalRead(button))
    {
    Num++;
    }  
    }
    
  //upload to serial

  Serial.print(" ");
  Serial.print(gsrVal);
  Serial.print(" ");
  
  Serial.print(" ");  
  Serial.print(Res_people);
  Serial.print(" ");
 
  Serial.print(" ");
  Serial.print(Num);
  Serial.println();
    }  

}



