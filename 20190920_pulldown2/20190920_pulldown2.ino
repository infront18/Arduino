#include "pitches.h"

int speakerPin=8; 
int buttonPins[]={2,4,7};
int notes[]={NOTE_C4, NOTE_D4, NOTE_E4};

void setup() 
{
  for(int i=0; i<3; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() 
{
  for(int i=0; i<3; i++)
  {
    if(digitalRead(buttonPins[i]) == LOW)
     {
       tone(speakerPin, notes[i], 500);
     }
  }
}
