#include "GUI.h"
#include "math.h"

int a,b;

const GUI_POINT aPoints[] = {
{ 272, 0},
{ 272, 272},
{ 0, 272},
{ 130, 180}
};


void MainTask(void) { 
  
  GUI_SetBkColor(GUI_WHITE);
  GUI_Clear();
  
  GUI_SetDrawMode(GUI_DM_NORMAL);
  GUI_SetColor(GUI_BLACK);
  GUI_SetPenSize(3);
  
  GUI_SetColor(GUI_GREEN);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,51,63);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,51,63);
  GUI_DrawArc(130,180,95,95,51,63);
  GUI_DrawLine(205,87,189,107);
  GUI_DrawLine(184,74,173,96);
  
  GUI_SetColor(GUI_GREEN);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,69,81);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,69,81);
  GUI_DrawArc(130,180,95,95,69,81);
  GUI_DrawLine(173,68,164,92);
  GUI_DrawLine(148,62,144,87);
  
  GUI_SetColor(GUI_GREEN);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,87,99);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,87,99);
  GUI_DrawArc(130,180,95,95,87,99);
  GUI_DrawLine(136,61,134,86);
  GUI_DrawLine(111,62,115,87);
  
  GUI_SetColor(GUI_YELLOW);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,105,117);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,105,117);
  GUI_DrawArc(130,180,95,95,105,117);
  GUI_DrawLine(99,65,105,89);
  GUI_DrawLine(75,74,86,96);
  
  GUI_SetColor(GUI_YELLOW);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,123,135);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,123,135);
  GUI_DrawArc(130,180,95,95,123,135);
  GUI_DrawLine(64,80,78,101);
  GUI_DrawLine(45,96,62,113);
  
  GUI_SetColor(GUI_ORANGE);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,141,153);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,141,153);
  GUI_DrawArc(130,180,95,95,141,153);
  GUI_DrawLine(36,105,56,121);
  GUI_DrawLine(23,126,45,137);
  
  GUI_SetColor(GUI_ORANGE);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,159,171);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,159,171);
  GUI_DrawArc(130,180,95,95,159,171);
  GUI_DrawLine(18,137,42,146);
  GUI_DrawLine(12,162,37,166);
  
  GUI_SetColor(GUI_ORANGE);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,177,189);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,177,189);
  GUI_DrawArc(130,180,95,95,177,189);
  GUI_DrawLine(11,174,36,176);
  GUI_DrawLine(12,199,37,195);
  
  GUI_SetColor(GUI_RED);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,195,207);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,195,207);
  GUI_DrawArc(130,180,95,95,195,207);
  GUI_DrawLine(14,212,38,205);
  GUI_DrawLine(24,234,46,223);
  
  GUI_SetColor(GUI_RED);
  for(a=96;a<119;a=a+1){
    GUI_DrawArc(130,180,a,a,213,225);
   }
  GUI_SetColor(GUI_BLACK);
  GUI_DrawArc(130,180,120,120,213,225);
  GUI_DrawArc(130,180,95,95,213,225);
  GUI_DrawLine(29,246,50,232);
  GUI_DrawLine(46,264,63,247);
  
  GUI_SetFont(&GUI_Font10_1);
  GUI_DispStringAt("Torque 1:", 325, 150);
  GUI_DispStringAt("Torque 2:", 325, 160);
  GUI_DispStringAt("Brake 1:", 325, 170);
  GUI_DispStringAt("Brake 2:", 325, 180);
  GUI_DispStringAt("Dir 1:", 325, 190);
  GUI_DispStringAt("Dir 2:", 325, 200);
  GUI_DispStringAt("Susp 1:", 325, 210);
  GUI_DispStringAt("Susp 2:", 325, 220);
  
  GUI_SetColor(GUI_BLACK);
  
  GUI_DrawLine(315,0,315,280);
  
  GUI_SetFont(&GUI_Font16B_1);
  GUI_DispStringAt("VPack:", 330, 20);
  GUI_DispStringAt("VCell max:", 330, 35);
  GUI_DispStringAt("VCell min:", 330, 50);
  GUI_DispStringAt("TCell max:", 330, 65);
  GUI_DispStringAt("TCell min:", 330, 80);
  
  GUI_SetFont(&GUI_Font32B_1);
  GUI_DispStringAt("SOC", 110, 150);
  GUI_DispStringAt("READY", 90, 230);
  
  //Barra RPM
  GUI_DrawLine(20,15,240,15);
  GUI_DrawLine(20,40,240,40);
  GUI_DrawLine(20,15,20,40);
  GUI_DrawLine(240,15,240,40);
  GUI_SetFont(&GUI_Font20B_1);
  GUI_DispStringAt("RPM", 250, 20);
  
  //Barra GAS
  GUI_DrawLine(230,60,255,60);
  GUI_DrawLine(230,60,230,210);
  GUI_DrawLine(230,210,255,210);
  GUI_DrawLine(255,60,255,210);
  
  //Barra FRE
  GUI_DrawLine(270,60,295,60);
  GUI_DrawLine(270,60,270,210);
  GUI_DrawLine(270,210,295,210);
  GUI_DrawLine(295,60,295,210);
  
  /*
  for(a=0;a<=8;a=a+1){
    for(b=0;b<=14;b=b+1){
      GUI_DrawPixel(300+a,220+b);
    }
  }*/
  /*
  GUI_DrawPixel(302,220);
  GUI_DrawPixel(303,220);
  GUI_DrawPixel(304,220);
  GUI_DrawPixel(305,220);
  GUI_DrawPixel(306,220);
  
  GUI_DrawPixel(301,221);
  GUI_DrawPixel(302,221);
  GUI_DrawPixel(303,221);
  GUI_DrawPixel(304,221);
  GUI_DrawPixel(305,221);
  GUI_DrawPixel(306,221);
  
  GUI_DrawPixel(300,222);
  GUI_DrawPixel(301,222);
  GUI_DrawPixel(302,222);
  
  GUI_DrawPixel(300,223);
  GUI_DrawPixel(301,223);
  
  GUI_DrawPixel(300,224);
  GUI_DrawPixel(301,224);
  
  GUI_DrawPixel(300,225);
  GUI_DrawPixel(301,225);
  GUI_DrawPixel(302,225);*/
}