#include"src\switch\switch_pub.h"
extern "C" int switch_task(void);
extern "C" void Led_State(int);

unsigned long current_val_ms;
unsigned long task20_ms=0;
unsigned long task500_ms=0;

#define TASK_20MS_ACTIVE 60
#define TASK_500MS_ACTIVE 500

int switch_state=0;
int led_state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT_PULLUP);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  current_val_ms=millis();
  
  //20ms task
  if((current_val_ms - task20_ms)>=TASK_20MS_ACTIVE)
  {
    task20_ms = current_val_ms;
    if(is_switch_pressed() == true)
  {
    switch_state++;
  }
  }
  
  //500ms task
  if((current_val_ms - task500_ms)>=TASK_500MS_ACTIVE)
  {
    task500_ms = current_val_ms;
    if(switch_state==1)
    {
      led_state=led_state^1;
      Led_State(led_state);
      switch_state--;
    }
   else
   {
    digitalWrite(10,LOW);
   }
  }
}
  
