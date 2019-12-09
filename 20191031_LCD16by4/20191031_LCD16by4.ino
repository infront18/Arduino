#include <openGLCD.h>
#include <openGLCD_Buildinfo.h>
#include <openGLCD_Config.h>
#include <fonts/Arial_bold_14.h>


void setup() {
  GLCD.Init();
  GLCD.SelectFont(System5x7);
  GLCD.print("Hello world!");
}

void loop() {

}
