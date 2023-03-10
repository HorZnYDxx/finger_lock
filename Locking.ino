
void lock()
{
color(HIGH,HIGH,LOW);
}

void unlock()
{
color(LOW,HIGH,LOW);
  delay(200);
color(HIGH,HIGH,LOW);
}

void mismatch()
{
color(HIGH,LOW,LOW);
  delay(200);
color(HIGH,HIGH,LOW);
}




void color( byte r ,byte g, byte b)
{

  digitalWrite(R ,r);
  digitalWrite(G ,g);
  digitalWrite(B ,b);

}

