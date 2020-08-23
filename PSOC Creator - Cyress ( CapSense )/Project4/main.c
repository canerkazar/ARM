#define ok(); LCD_PutChar(LCD_CUSTOM_0);
#define spc(); LCD_PrintString(" ");
#include "project.h"



int main(void)
{   
uint16 slider = 0,dim = 0,dim1=0,dim2=0,dim3=0;
uint16 column = 0,row = 1,X=0,i,j;
uint8 data;
CyGlobalIntEnable; 
CapSense_Start(); 
CapSense_ScanAllWidgets(); 
CapSense_InitializeAllBaselines();
LCD_Start();
UART_Start();


    for(;;)
    {   
        
        data = UART_UartGetChar();
    if(data == 49)
    {
    led_1_Write(1);
    led_2_Write(0);
    led_3_Write(0);
    led_4_Write(0);
    UART_UartPutString("Led 1 On");
    }
    if(data == 50)
    {
    led_1_Write(0);
    led_2_Write(1);
    led_3_Write(0);
    led_4_Write(0);
    UART_UartPutString("Led 2 On");
    }
    if(data == 51)
    {
    led_1_Write(0);
    led_2_Write(0);
    led_3_Write(1);
    led_4_Write(0);
    UART_UartPutString("Led 3 On");
    }
    if(data == 52)
    {
    led_1_Write(0);
    led_2_Write(0);
    led_3_Write(0);
    led_4_Write(1);
    UART_UartPutString("Led 4 On");
    }
if(CapSense_NOT_BUSY == CapSense_IsBusy())
         {
                CapSense_ProcessAllWidgets(); 
                
            
            LCD_Position(0,0);
            LCD_PrintString("L1:");
            LCD_Position(0,4);
            LCD_PrintNumber(dim/10);
            //0,7
            LCD_Position(0,8);
            LCD_PrintString("L2:");
            LCD_Position(0,12);
            LCD_PrintNumber(dim1/10);
            //0,14
            LCD_Position(1,0);
            LCD_PrintString("L3:");
            LCD_Position(1,4);
            LCD_PrintNumber(dim2/10);
            //1,7
            LCD_Position(1,8);
            LCD_PrintString("L4:");
            LCD_Position(1,12);
            LCD_PrintNumber(dim3/10);
            //1,14
            
        if(dim<1000){LCD_Position(0,6); LCD_PrintString(" ");}
        if(dim<100){LCD_Position(0,5); LCD_PrintString(" ");}
        if(dim1<1000){LCD_Position(0,14); LCD_PrintString(" ");}
        if(dim1<100){LCD_Position(0,13); LCD_PrintString(" ");}              
        if(dim2<1000){LCD_Position(1,6); LCD_PrintString(" ");}
        if(dim2<100){LCD_Position(1,5); LCD_PrintString(" ");}
        if(dim3<1000){LCD_Position(1,14); LCD_PrintString(" ");}
        if(dim3<100){LCD_Position(1,13); LCD_PrintString(" ");}                      
        
        for(i=0;i<=dim;i++)
            {   
            led_1_Write(1);
                for (j=0;j<=1;j++)
                    {
                        led_1_Write(0);
                    }
            }
        for(i=0;i<=dim1;i++)
            {
            led_2_Write(1);
                for (j=0;j<=1;j++)
                    {
                        led_2_Write(0);
                    }
            }
        for(i=0;i<=dim2;i++)
            {
            led_3_Write(1);
                for (j=0;j<=1;j++)
                    {
                        led_3_Write(0); 
                    }
            }    
         for(i=0;i<=dim3;i++)
            {
            led_4_Write(1);
                for (j=0;j<=1;j++)
                    {
                        led_4_Write(0); 
                    }
            }         
       
   if(CapSense_IsWidgetActive(CapSense_LINEARSLIDER0_WDGT_ID))
         {
            slider = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);
           if(slider<65535 && X==1)
                 {
                    dim=slider*10;
                    UART_UartPutChar(slider);
                 }
           if(slider<65535 && X==2)
                 {
                    dim1=slider*10;
                    UART_UartPutChar(dim1);
                 }
           if(slider<65535 && X==3)
                 {
                    dim2=slider*10;
                    UART_UartPutChar(dim2);
                 }
           if(slider<65535 && X==4)
                 {
                    dim3=slider*10;
                    UART_UartPutChar(dim3);
                 }
         }
   
   if(CapSense_IsWidgetActive(CapSense_BUTTON1_WDGT_ID)) // + button
         {
            if (row==1 && column==0)
            {
            LCD_Position(0,7);
            ok();
            LCD_Position(1,7);
            spc();
            row=0;
            column=0;
            X=1;
            }
            else if (row==1 && column==1)
            {
            LCD_Position(0,15);
            ok();
            LCD_Position(1,15);
            spc();
            row=0;
            column=1;
            X=2;
            }
         }
                
   else if(CapSense_IsWidgetActive(CapSense_BUTTON4_WDGT_ID))// - button
         { 
          if (row==0 && column==0)
            {
            LCD_Position(0,7);
            spc();
            LCD_Position(1,7);
            ok();
            row=1;
            column=0;
            X=3;
            }
            else if (row==0 && column==1)
            {
            LCD_Position(0,15);
            spc();
            LCD_Position(1,15);
            ok();
            row=1;
            column=1;
            X=4;
            }
        }
                    
   else if(CapSense_IsWidgetActive(CapSense_BUTTON2_WDGT_ID))// right button
         { 
            if (row==0 && column==0)
            {
            LCD_Position(0,15);
            ok();
            LCD_Position(0,7);
            spc();
            row=0;
            column=1;
            X=2;
            }
              else if (row ==1 && column==0)
            {
            LCD_Position(1,15);
            ok();
            LCD_Position(1,7);
            spc();
            row=1;
            column=1;
            X=4;
            }  
         }
                    
   else if(CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID))// left button
        { 
              if (row==0 && column==1)
            {
            LCD_Position(0,15);
            spc();
            LCD_Position(0,7);
            ok();
            row=0;
            column=0;
            X=1;
            }
              else if(row==1 && column==1)
            {
            LCD_Position(1,15);
            spc();
            LCD_Position(1,7);
            ok();
            row=1;
            column=0;
            X=3;
            }
        }
               
   else if(CapSense_IsWidgetActive(CapSense_BUTTON3_WDGT_ID)) // OK button
        {
                       
        }
                CapSense_ScanAllWidgets();    
    
   
        }
            }
    
}
