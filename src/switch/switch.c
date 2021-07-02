#include<Arduino.h>
#include "switch_pub.h"
int is_switch_pressed(void)
{
    int switch_pressed = false;
    if(digitalRead(7) == LOW)
    { 
       switch_pressed = true;
    }
else
    {
       switch_pressed = false;
    }
    return switch_pressed;
}