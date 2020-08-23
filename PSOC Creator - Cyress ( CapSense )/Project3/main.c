
#include "project.h"

int main(void)
{   
uint32 slider=0,a=3;

CyGlobalIntEnable; 
CapSense_Start(); 
CapSense_ScanAllWidgets(); 
CapSense_InitializeAllBaselines();
LCD_Start();
PWM1_Start();
PWM2_Start();
    for(;;)
    {
        
    LCD_Position(0,0);   
    LCD_PrintString("Led 1");
    LCD_Position(0,10);
    LCD_PrintString("Led 2");
    
        
   
   if(CapSense_NOT_BUSY == CapSense_IsBusy())
            {
                CapSense_ProcessAllWidgets(); /* Process all widgets */
                slider = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);  
                
                    
                if(CapSense_IsWidgetActive(CapSense_BUTTON2_WDGT_ID))// right button
                    { 
                     LCD_Position(0,5);   
                     LCD_PrintString(" ");
                     LCD_Position(0,15);
                     LCD_PrintString("*");
                     a=0;
                     CyDelay(10);
                    }
                    
                if(CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID))// left button
                    { 
                     LCD_Position(0,5);   
                     LCD_PrintString("*");
                     LCD_Position(0,15);
                     LCD_PrintString(" ");
                     a=1;
                     CyDelay(10);
                    
                    }
                    
                if(slider<65535 && a==1)
                {
                PWM1_WriteCompare(slider*100);
                CyDelay(50);
                }
                
                else if(slider<65535 && a==0)
                {
                PWM2_WriteCompare(slider*100);
                CyDelay(50);
                }
                else if (a==3)
                {
                led_1_Write(0);
                led_3_Write(0);
                }
               
                
                CyDelay(10);
                CapSense_ScanAllWidgets(); // NEXT SCAN

}
            }
    
}
