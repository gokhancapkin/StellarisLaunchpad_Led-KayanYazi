#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "Lcd.h"
#include "inc/lm4f120h5qr.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
char *strrev(char **str)
{

	 int lengthStr = strlen(str);
	            int i = 0;
	            int tempChr = 0;

	            for( i= 0; i < lengthStr/2; ++i)
	            {
	                        tempChr = str[i];
	                        str[i] = str[lengthStr - i - 1];
	                        str[lengthStr - i - 1] = tempChr;
	            }

	            return str;

}
void init_port_D() {
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD;
	delay = SYSCTL_RCGC2_R;
	GPIO_PORTD_DIR_R |= 0x0F;
	GPIO_PORTD_AFSEL_R &= ~0x0F;
	GPIO_PORTD_DEN_R |= 0x0F;
}
void init_port_A() {
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA;
	delay = SYSCTL_RCGC2_R;
	GPIO_PORTA_DIR_R |= 0x0F;
	GPIO_PORTA_AFSEL_R &= ~0x0F;
	GPIO_PORTA_DEN_R |= 0x0F;
}


#define BIT_SET(PORT, PIN) do { \
	PORT |= 1<<PIN; \
} while (0)

#define BIT_RESET(PORT, PIN) do { \
	PORT &= ~(1<<PIN); \
} while (0)


#define PORTD (GPIO_PORTD_DATA_R)
#define PORTA (GPIO_PORTA_DATA_R)
int main(void) {

        SysCtlClockSet(
                        SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
                        | SYSCTL_OSC_MAIN);
        Lcd_init();
        init_port_D();
        init_port_A();
        while (1) {
        	int random,tempr=5;
        	random=rand()%4;
        	if(tempr==random){
        		tempr=random;
        		continue;
        	}
        	else{
        	volatile unsigned long delay;

        				if(random==0){
        				BIT_SET(PORTD,2);
        	        	BIT_RESET(PORTD, 3);
        	        	BIT_RESET(PORTA, 2);
        	        	BIT_RESET(PORTA, 3);
        	        	Lcd_Goto(1,1);
        	        	Lcd_Puts("kocaeli uni");
        	        	for(delay=0;delay<4000000;delay++);
        	        	Lcd_Goto(2,1);
        	        	Lcd_Puts("Gokhan Capkin");
        	        	for(delay=0;delay<6000000;delay++);
        				}//beyaz
        				if(random==1){
        	        	BIT_RESET(PORTD, 2);
        	        	BIT_SET(PORTD, 3);
        	        	BIT_RESET(PORTA, 2);
        	        	BIT_RESET(PORTA, 3);
        	        	Lcd_Goto(1,1);
        	        	Lcd_Puts("Gokhan Capkin");
        	        	for(delay=0;delay<4000000;delay++);
        	        	Lcd_Goto(2,1);
        	        	Lcd_Puts("kocaeli uni");
        	        	for(delay=0;delay<6000000;delay++);
        	        	Lcd_Temizle();

        				}//yeşil
        				if(random==2){
        	        	BIT_RESET(PORTD, 2);
        	        	BIT_RESET(PORTD, 3);
        	        	BIT_SET(PORTA, 2);
        	        	BIT_RESET(PORTA, 3);
        	        	for(int y=1;y<=16;y++){
        	        	        Lcd_Goto(1,y);
        	        	        Lcd_Puts("kocaeli uni");
        	        	        for(delay=0;delay<400000;delay++);
        	        	        Lcd_Temizle();
        	        	        }
        	        	for(int y=1;y<=16;y++){
        	        	        Lcd_Goto(2,y);
        	        	        Lcd_Puts("Gokhan Capkin");
        	        	        for(delay=0;delay<600000;delay++);
        	        	        Lcd_Temizle();
        	        	        }
        	        	for(delay=0;delay<5000000;delay++);
        	        	//
        				}
        				if(random==3){
        	        	//mavi
        	        	BIT_RESET(PORTD, 2);
        	        	BIT_RESET(PORTD, 3);
        	        	BIT_RESET(PORTA, 2);
        	        	BIT_SET(PORTA, 3);
        	        	for(int y=6;y>=1;y--){

        	        	      Lcd_Goto(1,y);
        	        	      char *ch="kocaeli uni";
        	        	      char *gecici;
							  char *temp;

        	        	      Lcd_Puts("kocaeli uni");
        	        	      for(delay=0;delay<400000;delay++);
        	        	      Lcd_Temizle();
        	        	      if(y==1)
        	        	      {
        	        	    	  for(int i=0;i<11;i++)
        	        	    	          {
        	        	    		  	  	  strncpy(gecici,strrev(*ch),11-i);
        	        	    		  	  	  temp=strrev(*gecici);
        	        	    		  	  	  Lcd_Goto(1,1);
        	        	    		  	  	  Lcd_Puts(temp);
        	        	        	        }
        	        	      }
        	        	      }
        	        	for(int y=3;y>=0;y--){

        	        	        	  Lcd_Goto(2,y);
        	        	        	  char *ch="Gokhan Capkin";
        	        	        	  char *gecici;
									  char *temp;

        	        	        	  Lcd_Puts("Gokhan Capkin");
        	        	        	  for(delay=0;delay<600000;delay++);
        	        	        	  Lcd_Temizle();
        	        	        	  if(y==0)
        	        	        	  {
        	        	        	        for(int i=0;i<11;i++)
        	        	        	        {
        	        	        	        	 strncpy(gecici,strrev(*ch),11-i);
        	        	        	        	 temp=strrev(*gecici);
        	        	        	        	 Lcd_Goto(2,1);
        	        	        	        	 Lcd_Puts(temp);
        	        	        	        }
        	        	        	   }
        	        		}
        				}
        	        	Lcd_Temizle();
        	        	tempr=random;
        }
        }
}



        	{
        		while(hesapla == true)
        		{
        			if(RPD2==true || RPD3 == true || RPC4==true || RPA3==true ||RPE3==true)
        			{
        				sayac = 0;
        				break;
        			}
        			else{
        				sayac ++;
        				if(sayac == 3000000)
        					break;
        			}
        		}
        	}
        	if(sayac == 3000000)
        		break;
