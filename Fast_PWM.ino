//fast pwm
void setup() {
 pinMode(3,OUTPUT);

 TCCR2A=0x23;
 TCCR2B=0x07;
 TCNT2=0;
 OCR2B=52;
 //analogWrite(3,52);
}

void loop()
{
  // put your main code here, to run repeatedly:

}
