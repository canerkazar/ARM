
#include "project.h"


int main(void)
{  
    
uint16 a=0,c=0;
uint32 slider=1,slider1=1,sum=0;

CyGlobalIntEnable; 
CapSense_Start(); 
CapSense_ScanAllWidgets(); 
CapSense_InitializeAllBaselines();
LCD_Start();
for(uint16 G=1;G<=1;G++)
{
                LCD_ClearDisplay();
                LCD_Position(0,6);
                LCD_PutChar(LCD_CUSTOM_2);
                LCD_Position(0,8);
                LCD_PutChar(LCD_CUSTOM_2);
                CyDelay(1000);
                LCD_Position(0,8);
                LCD_PutChar(LCD_CUSTOM_3);
                LCD_Position(0,6);
                LCD_PutChar(LCD_CUSTOM_3);
                CyDelay(1000);
                LCD_Position(1,6);
                LCD_PutChar(LCD_CUSTOM_5);
                LCD_Position(1,7);
                LCD_PutChar(LCD_CUSTOM_6);
                LCD_Position(1,8);
                LCD_PutChar(LCD_CUSTOM_7);
                CyDelay(1000);
                LCD_ClearDisplay();
                LCD_Position(0,0);
                LCD_PrintString("cvm :M:m:M:M:M:m:M:M:M:M:M:m:M:M:M");
                CyDelay(5000);
                LCD_ClearDisplay();
                
}
                
                
    for(;;)
    {
   c=0;  
   


            
   if(CapSense_NOT_BUSY == CapSense_IsBusy())
            {
                CapSense_ProcessAllWidgets(); /* Process all widgets */
                
                if(CapSense_IsWidgetActive(CapSense_LINEARSLIDER0_WDGT_ID))
                {
                
                        if(slider<65535 && a==0)
                    
                             {
                                 
                                 slider = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);
                                 LCD_Position(0,3);
                                 LCD_PrintNumber(slider);
                                 
                             }
                        
                        else if (slider<65535 && a==1)
        
                             {
                                 
                                 slider1 = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);  
                                 LCD_Position(0,13);
                                 LCD_PrintNumber(slider1);
                                                  
                             }
                      if(slider<100)
                            {
                                LCD_Position(0,5);
                                LCD_PrintString(" ");
                            }
                      if (slider<10)
                            {
                                LCD_Position(0,4);
                                LCD_PrintString(" ");
                            }
                      if (slider1<100)
                            {
                                LCD_Position(0,15);
                                LCD_PrintString(" ");
                            }
                      if (slider1<10)
                            {
                                LCD_Position(0,14);
                                LCD_PrintString(" ");
                            }
                      if (slider==0 || slider1==0)
                            {
                            goto Y;
                            }
                                    
                }
                
                if(CapSense_IsWidgetActive(CapSense_BUTTON1_WDGT_ID) && c==0) // + button
                    {
                    Y:  if (slider==0 || slider1==0)
                            {
                             slider=1;
                             slider1=1;   
                            }
                        c=1;  
                      
                      if (a==0)
                       {
                        slider++;
                        CyDelay(20);    
                        LCD_Position(0,3);
                        LCD_PrintNumber(slider);
                        
                       }       
                       else if (a==1)
                           {
                            slider1++;
                            CyDelay(20);
                            LCD_Position(0,13);
                            LCD_PrintNumber(slider1);
                           }
                      if(slider<100)
                            {
                                LCD_Position(0,5);
                                LCD_PrintString(" ");
                            }
                      if (slider<10)
                            {
                                LCD_Position(0,4);
                                LCD_PrintString(" ");
                            }
                      if (slider1<100)
                            {
                                LCD_Position(0,15);
                                LCD_PrintString(" ");
                            }
                      if (slider1<10)
                            {
                                LCD_Position(0,14);
                                LCD_PrintString(" ");
                            }   
                       if (slider==256 || slider1==256)
                            {
                            goto X;
                            }
                    }
                
              else if(CapSense_IsWidgetActive(CapSense_BUTTON4_WDGT_ID) && c==0)// - button
                    { 
                     X:  c=1; 
                       if (a==0)
                       {
                            slider--;
                            CyDelay(20);    
                            LCD_Position(0,3);
                            LCD_PrintNumber(slider);
                       }
                        
                       else if (a==1)
                              {
                                slider1--;
                                CyDelay(20);
                                LCD_Position(0,13);
                                LCD_PrintNumber(slider1);
                              }
                      
                      if(slider<100)
                            {
                                LCD_Position(0,5);
                                LCD_PrintString(" ");
                            }
                      if (slider<10)
                            {
                                LCD_Position(0,4);
                                LCD_PrintString(" ");
                            }
                      if (slider1<100)
                            {
                                LCD_Position(0,15);
                                LCD_PrintString(" ");
                            }
                      if (slider1<10)
                            {
                                LCD_Position(0,14);
                                LCD_PrintString(" ");
                            }
                      if (slider==0 || slider1==0)
                            {
                                
                                goto Y;      
                            }
                            
                    }
                    
               else if(CapSense_IsWidgetActive(CapSense_BUTTON2_WDGT_ID) && c==0)// right button
                    { 
                        c=1;
                        a=1;
                        LCD_Position(1,0);
                        LCD_PrintString("                                      ");
                        
                    }
                    
               else if(CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID) && c==0)// left button
                    { 
                        c=1;
                        a=0;
                        LCD_Position(1,0);
                        LCD_PrintString("                                      ");
                        
                    }
                    
                
              else if(CapSense_IsWidgetActive(CapSense_BUTTON3_WDGT_ID) && c==0) // OK button
                    
                    {
                        
                        c=1;
                        a++;
                
                        
               if(a==2)
                {
                sum=(slider1 * slider);
                LCD_Position(1,0);
                LCD_PrintString("       ");
                LCD_Position(1,0);
                LCD_PrintNumber(sum);
                
                uint16 i,j,k,m=0;
                    for(i=(sum-1);i<sum;i--)
                    {
                    k=1;
                        for(j=2;j<i;j++)
                        {
                            if (i%j==0)
                            {
                                k=0;
                                break;
                            }
                        }
                        
                    if (k==1)
                        {
                         m=i;
                         i = sum + 1;
                             
                        }
                    }
               LCD_Position(1,10);
               LCD_PrintString("        ");
               LCD_Position(1,10);
               LCD_PrintNumber(m);
                 }   
                a=1;
                
                    }
               if(a==0)
                 {
                    LCD_Position(0,0);
                    LCD_PutChar(LCD_CUSTOM_1);
                    LCD_Position(0,1);
                    LCD_PrintString(")");
                    LCD_Position(0,10);
                    LCD_PrintString("2)");
                    
                 }
                
               else if(a==1)
                {
                    LCD_Position(0,0);
                    LCD_PrintString("1)");
                    LCD_Position(0,10);
                    LCD_PutChar(LCD_CUSTOM_0);
                }
                
                CyDelay(10);
                CapSense_ScanAllWidgets(); // NEXT SCAN

}
            }
    
}
