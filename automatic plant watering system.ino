
#define pump1 3

const int sensor_pin = A0;
const int water_l =A1;

void pump();


void setup() 
{
pinMode(pump1 ,OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float moisture_percentage;
int sensor_analog;
int water_analog;
float water_level;
sensor_analog = analogRead(sensor_pin);
water_analog = analogRead(water_l);
moisture_percentage = ( 100 - ( (sensor_analog/1023.00)* 100 ) );
if(moisture_percentage < 50)
{
Serial.print("pumping water");
pump();
delay(5000);
sensor_analog= analogRead(sensor_pin);
moisture_percentage = ( 100 - ( (sensor_analog/1023.00)* 100 ) );
  
}
else if(moisture_percentage < 50)
{
Serial.print("Pumping water");
pump();
delay(1000);
sensor_analog= analogRead(sensor_pin);
moisture_percentage = ( 100 - ( (sensor_analog/1023.00)* 100 ) );
}
else
{  
}
water_level = ( 100 - ( (water_analog/1023.00)* 100 ) );
Serial.print("Water Level:=");
Serial.print(water_level);
Serial.print("%\n\n");
Serial.print("Moisture percentage =");
Serial.print(moisture_percentage);
Serial.print("%\n\n");
if(water_level < 20)
{
  Serial.print("Tank level LOW");
}
delay(1000);

}
void pump()
{
  digitalWrite(pump1,HIGH);
  delay(15000);
  digitalWrite(pump1,LOW);
  }




