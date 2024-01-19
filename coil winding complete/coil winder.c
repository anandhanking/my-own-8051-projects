
#include <stdio.h> 

sbit rs=P3^6;
sbit en=P3^7;

sbit motor=P3^1;

sbit ones=P0^2;
sbit tens=P0^3;
sbit huns=P0^4;

sbit start=P0^5;
sbit stop =P0^6;
sbit reset=P0^7;

void lcd(char a,int b);                        
unsigned char msg[]="  Counter  :";
unsigned char msg2[]="Set count  :";

char ch[4];
char eh[4];

void delay();                                    
void counter();                               
int k;
int b;
int val2=0;
unsigned int val;

void main()
 {
   lcd(0x38,0);
   lcd(0x0c,0);
   lcd(0x80,0);
   TMOD=0x05;                                
   counter();
 }
void delay()
 {
   int i;
   for(i=0;i<=2000;i++);                
 } 
void counter()
 {
   TL0=0;                                  
   TR0=1;

	while(motor=0);	 
   for(k=0;k<12;k++)
     {
       lcd(msg[k],1);
     }
		 
			 lcd(0xc0,0);
		    for(k=0;k<12;k++)
     {
       lcd(msg2[k],1);
     }
		 
   while(1)
  	 {
      lcd(0x8c,0);                           
      val=TL0|TH0<<8;                 
      sprintf(ch,"%u",val);             
      for(k=0;k<5;k++)
        {
          lcd(ch[k],1);
        }
			
		 lcd(0xcc,0);
		 sprintf(eh,"%u",val2);
		 for (b=0;b<5;b++)
		 {
				lcd(eh[b],1);
		 }
		 

				
if (start==0){
			
			motor=1;	
		
}
if (stop==0){
			
			motor=0;	
		
}
if (reset==0){
	
			val=0; 
			val2=0;

}	

if (val>0 && val2==val){
			
			motor=0;
}
if (ones==0){
	val2 = val2+1;
}

if (tens==0){
	val2 = val2+10;	
 }

if (huns==0){
	val2 = val2+100;
}
}
 } 

void lcd(char a,int b)
   {
     P1=a;
     rs=b;
     en=1;
     delay();
     en=0;
     delay();
   }
  
