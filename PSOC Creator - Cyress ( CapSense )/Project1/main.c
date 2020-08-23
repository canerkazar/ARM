
#include "project.h"
uint16 plus=0,ADC,a;

int main(void)
{   
CyGlobalIntEnable; 
CapSense_Start(); 
CapSense_ScanAllWidgets(); 
CapSense_InitializeAllBaselines();
LCD_Start();

LCD_Position(1,0);
LCD_PutChar(LCD_CUSTOM_0);
LCD_Position(1,1);
LCD_PutChar(LCD_CUSTOM_0);
LCD_Position(1,2);
LCD_PutChar(LCD_CUSTOM_0);
LCD_Position(1,4);
LCD_PutChar(LCD_CUSTOM_0);

    for(;;)
    {
   a=0;     
   if(CapSense_NOT_BUSY == CapSense_IsBusy())
            {
                CapSense_ProcessAllWidgets(); /* Process all widgets */
                ADC = CapSense_AdcReadResult_mVolts(CapSense_AdcCHANNEL_0);
                LCD_Position(0,9);
                LCD_PrintNumber(ADC);
                LCD_Position(0,13);
                LCD_PrintString(" mV");
            
                
                if(CapSense_IsWidgetActive(CapSense_BUTTON1_WDGT_ID) && a==0) // + button
                    {
                        
                        plus++;
                        LCD_Position(0,0);
                        LCD_PrintString("Led");    
                        LCD_Position(0,4);
                        LCD_PrintDecUint16(plus);
                        CyDelay(30);
                        a=1;
                        // CODE HERE
                    }
                
                if(CapSense_IsWidgetActive(CapSense_BUTTON4_WDGT_ID) && a==0)// - button
                    { 
                        plus--;
                        LCD_Position(0,0);
                        LCD_PrintString("Led");    
                        LCD_Position(0,4);
                        LCD_PrintDecUint16(plus);
                        CyDelay(30);
                        a=1;
                        // CODE HERE
                    }
                    
                if(CapSense_IsWidgetActive(CapSense_BUTTON3_WDGT_ID) && a==0) // OK button
                    {
                        
                        
                        if (plus == 1)
                        {
                        led_1_Write(!led_1_Read());
                        a=1;
                        }
                        else if (plus == 2)
                        {
                        led_2_Write(!led_2_Read());
                        a=1;
                        }
                        else if (plus == 3)
                        {
                        led_3_Write(!led_3_Read());
                        a=1;
                        }
                        else if (plus == 4)
                        {
                        led_4_Write(!led_4_Read());
                        a=1;
                        }
                        
                       CyDelay(30);
                        
                         
                         // CODE HERE
                    }
                          
                
                 if(plus>4)
                 {
                  plus=1;
                  LCD_Position(0,0);
                  LCD_PrintString("Led");    
                  LCD_Position(0,4);
                  LCD_PrintDecUint16(plus);
                  CyDelay(5);
                 }
                
                
                 if (plus<1)
                 {
                  plus=4;
                  LCD_Position(0,0);
                  LCD_PrintString("Led"); 
                  LCD_Position(0,4);
                  LCD_PrintDecUint16(plus);
                  CyDelay(5);
                 }
                
                CyDelay(30);
                CapSense_ScanAllWidgets(); // NEXT SCAN

}
            }
    
}
