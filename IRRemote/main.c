#include <REGX52.H>

unsigned long int bitMask=0,newKey=0;
unsigned char tVal;
unsigned char ticks=0;
char pulseCnt=0;
                                                                                                                                                                                                                                                                                                                                                                                               
sbit LED1   = P2^0;
sbit LED2   = P2^1;
sbit LED3   = P2^2;
sbit LED4   = P2^3;
sbit LED5   = P2^4;
sbit LED6   = P2^5;
sbit LED7   = P2^6;
sbit LED8   = P2^7;
sbit LED9   = P0^6;
sbit LED0   = P0^7;

/*
sbit IN1   = P0^0;
sbit IN2   = P0^1;
sbit IN3   = P0^2;
sbit IN4   = P0^3;
*/

int ledf1 = 0;
int ledf2 = 0;
int ledf3 = 0;
int ledf4 = 0;
int ledf5 = 0;
int ledf6 = 0;
int ledf7 = 0;
int ledf8 = 0;
int ledf9 = 0;
int ledf0 = 0;

//Pin NAME      SCV Code    		mp3 code    

#define POWER    	0xE31CFF00 		     //0x1FE48B7     
#define REPEAT 						   0x1FE10EF
#define MODE						   0x1FE58A7       
#define MUTE	    0xE916FF00  		//0x1FE7887
#define USD	    					   0x1FE906F
#define PREV		0xFD02FF00  		//0x1FE40BF
#define NEXT		0xFC03FF00  		//0x1FEC03F
#define EQ							   0x1FE20DF
#define VOL_M		0xF10EFF00  		//0x1FEA05F
#define VOL_P		0xE51AFF00  		//0x1FE609F
#define PLAY						   0x1FE807F
#define ZERO		0xED12FF00			//0x1FEE01F
#define ONE			0xF609FF00  		//0x1FE50AF     
#define TWO	        0xE21DFF00  		//0x1FED827     
#define THREE		0xE01FFF00  		//0x1FEF807     
#define FOUR		0xF20DFF00  		//0x1FE30CF
#define FIVE		0xE619FF00  		//0x1FEB04F
#define SIX			0xE41BFF00  		//0x1FE708F
#define SEVEN		0xEE11FF00  		//0x1FE00FF
#define EIGHT		0xEA15FF00  		//0x1FEF00F
#define NINE		0xE817FF00  		//0x1FE9867



void delay(unsigned int y){
    unsigned int i,j;
for(i=0;i<y;i++){
    for(j=0;j<1275;j++){}
}
}

void timer0_ISR() interrupt 1
{
    if(ticks<50){
        ticks++;
		}
		
    TH0 = 0xFC;   /*Reload Timer Values for 1ms*/
    TL0 = 0x67;
}


void INT0_ISR()  interrupt 0
{
    tVal = ticks;
    ticks = 0;

    TH0 = 0xFC;  /*Reload Timer Values for 1ms*/
    TL0 = 0x67;

    pulseCnt++;

    if((tVal>=50)) /*Pulse width greater than 50ms signifies Start of Frame*/
    { 
        pulseCnt = -2; /*Skip first 2 counts*/
        bitMask = 0;
    }
    else if((pulseCnt>=0) && (pulseCnt<32)) 
    {  
			/* Accumulate 32 bit data */
        if(tVal>=2)            
        {
            bitMask |=(unsigned long int)1<<(31-pulseCnt);
        }

    }
    else if(pulseCnt>=32)          /*End of Frame*/
    {
        newKey = bitMask;      
        pulseCnt = 0;
    }
}


void timerInit (void)
{
	  TMOD |= 0x01;  /* Timer 0 Mode 1 */
    TH0 = 0xFC;    /* Reload Value for 1ms for AT89S52*/
    TL0 = 0x67;
    TR0 = 1;       /*Start Timer*/
    ET0 = 1;       /*Enable Timer Interrupt*/
    
    IT0 = 1;       /*Int0 Falling Edge Interrupt*/
    EX0 = 1;       /*Enable INT0 Interrupt*/
    
    EA  = 1;       /*Enable Global Interrupts*/
}


void main()
{

				
		/*	
				IN1 = 1;
				IN2 = 1;
				IN3 = 1;
				IN4 = 1;
		*/		
        LED1 = 0;
				LED2 = 0;
				LED3 = 0;
				LED4 = 0;
				LED5 = 0;
				LED6 = 0;	
				LED7 = 0;
				LED8 = 0;
				LED0 = 0;
	
	 timerInit();
	
	  while(1)
    {
        if(newKey!=0)		
        {  
						{if (newKey == ONE){
							if (ledf1 == 0) { 
							ledf1 = 1;       
							LED1 = 1;
							
						}else {
							ledf1 = 0;
							LED1 = 0;
							
						}}}
						{if (newKey == TWO){
							if (ledf2 == 0) { 
							ledf2 = 1;       
							LED2 = 1;
							
						}else {
							ledf2 = 0;
							LED2 = 0;
							
						}}}
						{if (newKey == THREE){
							if (ledf3 == 0) { 
							ledf3 = 1;       
							LED3 = 1;
							
						}else {
							ledf3 = 0;
							LED3 = 0;
							
						}}}
						{if (newKey == FOUR){
							if (ledf4 == 0) { 
							ledf4 = 1;       
							LED4 = 1;
							
						}else {
							ledf4 = 0;
							LED4 = 0;
							
						}}}
						{if (newKey == FIVE){
							if (ledf5 == 0) { 
							ledf5 = 1;       
							LED5 = 1;
							
						}else {
							ledf5 = 0;
							LED5 = 0;
							
						}}}
						{if (newKey == SIX){
							if (ledf6 == 0) { 
							ledf6 = 1;       
							LED6 = 1;
							
						}else {
							ledf6 = 0;
							LED6 = 0;
							
						}}}
						{if (newKey == SEVEN){
							if (ledf7 == 0) { 
							ledf7 = 1;       
							LED7 = 1;
							
						}else {
							ledf7 = 0;
							LED7 = 0;
							
						}}}
						{if (newKey == EIGHT){
							if (ledf8 == 0) { 
							ledf8 = 1;       
							LED8 = 1;
							
						}else {
							ledf8 = 0;
							LED8 = 0;
							
						}}}
						{if (newKey == NINE){
							if (ledf9 == 0) { 
							ledf9 = 1;       
							LED9 = 1;
							
						}else {
							ledf9 = 0;
							LED9 = 0;
							
						}}}
						{if (newKey == ZERO){
							if (ledf0 == 0) { 
							ledf0 = 1;       
							LED0 = 1;
							
						}else {
							ledf0 = 0;
							LED0 = 0;
							
						}}}
					if (newKey == POWER){
						
				LED1 = 0;
				LED2 = 0;
				LED3 = 0;
				LED4 = 0;
				LED5 = 0;
				LED6 = 0;	
				LED7 = 0;
				LED8 = 0;
			  LED9 = 0;
				LED0 = 0;
						}
								
            newKey = 0;		 
					}
}		
	  }