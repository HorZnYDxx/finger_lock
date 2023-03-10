

void setup() {
  // put your setup code here, to run once:


Serial.begin(115200);

Fi.Clear();
E.Clear();

pinMode(3,INPUT_PULLUP);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);


lock();

EEPROM_readAnything(0,Y_key);

plotKey();

X_target=X_start;

//Read_from_EEPROM

}





void loop() 
{

X_now = analogRead(2);
Y_now = analogRead(3);
Serial.println(X_now);  

  if(digitalRead(Record_pin)==LOW)   //check record pin
    {
     Record_key();     //Read value and save to EEPROM
    }

record_error();

check_start_end();
    
}


