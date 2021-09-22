volatile byte rx_byte;
unsigned long var_u1;
unsigned int var2_uint;
void serial_transmit_bytes(unsigned char * val_addr,unsigned int len)
{
  for(int i=0;i<len;i++)
  {
    UDR0 = *val_addr;
    val_addr++;
    while(!(UCSR0A & (1<<5)));
  }
}
void setup() {
  // put your setup code here, to run once
  // 8bit data format
  UBRR0H = 0x00;
  UBRR0L = 103;

  UCSR0B =(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
   UCSR0C =(1<<UCSZ00)|(1<<UCSZ01);
   var_u1  |=((unsigned long)'A'<< 24);
    var_u1 |=((unsigned long)'B'<< 16);
     var2_uint  |=((unsigned long)'C'<< 8);
      var2_uint |=((unsigned long)'D');
  }

void loop() {
  // put your main code here, to run repeatedly:
   if(rx_byte =='1')
   {
    rx_byte = 0;
    serial_transmit_bytes((unsigned char *)&var_u1,4);
    
    
   }
}
ISR(USART_RX_vect)
{
  rx_byte = UDR0;
  UDR0 = rx_byte;
}
