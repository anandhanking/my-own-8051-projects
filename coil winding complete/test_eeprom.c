#include <reg51.h>
#include <stdio.h> 

sbit RS = P3^6; //Register Select (RS) pin of 16*2 lcd
sbit EN = P3^7; //Enable (E) pin of 16*2 lcd

sbit SDA = P3^1; //SDA pin of EEPROM
sbit SCL = P3^0; //SCL pin of EEPROM

sbit button1 = P3^6;
sbit eepromSwitch = P3^7;
sbit e2 = P3^4;
sbit led = P3^5;

/*
sbit motor=P2^0;

sbit ones=P0^2;
sbit tens=P0^3;
sbit huns=P0^4;

sbit start=P0^5;
sbit stop =P0^6;
sbit reset=P0^7;

unsigned char msg[]="  Counter  :";
unsigned char msg2[]="Set count  :";
unsigned char msg3[]="Count:";

void counter();
void delay();

void LCD_CMD(unsigned char x); //LCD command function
void LCD_DATA(char w); //LCD data function
void LCD_INI(void) ; // LCD initialzed function
void Send_Data(unsigned char *str); //Send data string

void msDelay(unsigned int); //function for creating delay
void Delay(unsigned char Time); //£unction for creating delay
*/
void EPROM_Start(); //EEPROM Start Function
void EPROM_Stop(); //EEPROM Stop Function
void EPROM_Ack(); //EEPROM Acknowledge Function

void EPROM_Send(unsigned char Data); //EEPROM Send Data Function
unsigned char EPROM_Read(); //EEPROM Read Data Function

void EPROM_WriteByte(unsigned char Data, unsigned char Address, unsigned char Page); //WPROM Write Byte
unsigned char EPROM_ReadByte(unsigned char Address, unsigned char Page); //WPROM Read Byte

unsigned int i;

int k;
int b;
int q;

int val;
int val2 = 1510;
int val3 = 0;

char ch[4];
char eh[4];

void main (void)
{	
	/*
		LCD_INI();
	  TMOD=0x05;                                
    counter();
	*/
	while(1){
	
	if (eepromSwitch == 0){
		
		for(i = 0; i<5; i++)
        {
					EPROM_WriteByte(val2,i,0); //Write Data to EEPROM
			
				}
			}
		if (e2 == 0){
		
		for(i = 0; i<5; i++)
        {
					EPROM_WriteByte(val3,i,0); //Write Data to EEPROM
			
				}
			}
	
		
	
if (button1 == 0){
			
						if ((EPROM_ReadByte(i, 0)==1510))
								{
									led = 0;
								}
					}
		}
}
	
/* void counter()
 {
   TL0=0;                                  
   TR0=1;
	 
	while(motor=0);	
	 
		LCD_CMD(0x80); 	 
			
			for(k=0;k<12;k++)
				{
					LCD_DATA(msg[k]);
				}		 
		
		LCD_CMD(0xc0);
		 
			for(k=0;k<12;k++)
				{
					LCD_DATA(msg2[k]);
				}
				
   while(1)
  	 {
      LCD_CMD(0x8c);                           
      val=TL0|TH0<<8;                 
     
			sprintf(ch,"%u",val);             

			for(k=0;k<5;k++)
				{
          LCD_DATA(ch[k]);
        }
			
			LCD_CMD(0xcc);
		 
			sprintf(eh,"%u",val2);
			
			for (b=0;b<5;b++)
				{
					LCD_DATA(eh[b]);
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
	delay();
}

if (tens==0){
	val2 = val2+10;
	delay();
 }

if (huns==0){
	val2 = val2+100;
	delay();
}

if (button1 == 0){
		
					LCD_CMD(0x01); //lcd clear screen		
					
					LCD_CMD(0x80);
			
		for(q=0;q<6;q++)
				{
          LCD_DATA(msg3[q]);
        }
			
					LCD_CMD(0x87);
					
		for (i = 0; i<5; i++)
				{
					LCD_DATA(EPROM_ReadByte(i, 0)); //Read Data From EEPROM
				}
			}

if (eepromSwitch == 0){
			
		  sprintf(ch,"%u",val);
      for(i = 0; i<5; i++)
        {
					EPROM_WriteByte(ch[i],i,0); //Write Data to EEPROM
			
				}			
			}
		} 
	} 
void delay()
 {
   int i;
   for(i=0;i<=30000;i++);                
 } 

void LCD_DATA (char w)
{
	P1 = w; // Put w into LCDD
	RS = 1; // RS is equal to 1
	EN = 1; // EN is equal to 1
	msDelay(1); //Delay
	EN = 0; //En is equal to 0
	return; // Return
}

void LCD_CMD (unsigned char x)
{
	P1 = x; // Put X into LCD
	RS = 0; // RS is equal to 0
	EN = 1; // EN is equal to 1
	msDelay(1); //Delay
	EN = 0; //En is equal to 0
	return; // Return
}

void LCD_INI (void)
{
	LCD_CMD(0x38); //Set Function 00111000
	LCD_CMD(0x0c); //Set Display On/Off 00001110
}

void msDelay(unsigned int Time)
{
	unsigned int y,z; //Define variable
	for (y=0; y<Time; y++) // For Loop for delay
	for (z=0; z<500; z++); //For Loop for delay
}
*/
void Delay (unsigned char Time)
{
	unsigned char y; //Define variable
	for (y=0; y<Time; y++); // For Loop for delay
}

void EPROM_Start()
{
	SCL = 0; // SCL Iis equal to 0
	SDA = 1; // SDA is equal to 1
	Delay(30); //Delay
	SCL = 1; // SCL is equal to 1
	Delay(30); //DElay
	SDA =0; // SDA is equal to 0
	Delay(30); //Delay
	SCL = 0; // SCL is equal to 0
}

void EPROM_Stop()
{
	SCL = 0; // SCL is equal to 0
	Delay(30); //Delay
	SDA = 0; // SDA is equal to 0
	Delay(30); //Delay
	SCL = 1; // SCL is equal to 1
	Delay(30); //Delay
	SDA = 1; // SDA is equal to 1
}

void EPROM_Ack()
{
	SDA = 0; // SDA is equal to 0
	Delay(30); //Delay
	SCL = 1; // SCL is equal to 1
	Delay(30); //Delay
	SCL = 0; // SCL is equal to 0
	SDA = 1; // SDA is equal to 1
}

void EPROM_Send(unsigned char Data)
{
	unsigned char i; //Define variable
	for (i = 0; i< 8; i++) //For loop for sending data bit by bit
	{
		SDA = Data & 0x80; //AND operation with 10000000
		SCL = 1; // SCL is equal to 1
		SCL = 0; // SCL is equal to 0
		Data<<=1; //Shift Data with 1
	}
		EPROM_Ack(); //Call EEPROM Acknowledge
}
unsigned char EPROM_Read()
{
	unsigned char i, Data = 0; //Define variable
	for (i = 0; i < 8; i++) //For loop
	{
		Delay(20); //Delay
		SCL = 1; // SCL is equal to 1
		Data |= SDA; //Add Data into data
		if(i<7)
		Data<<=1; //Shift data with 1
		SCL = 0; // SCL is equal to 0
	}
	return Data; //Return data
}

void EPROM_WriteByte (unsigned char Data, unsigned char Address, unsigned char Page)
{
	EPROM_Start(); // Call start
	EPROM_Send(0xA0 | (Page<<1)); // Send page number
	EPROM_Send(Address); //Send address loaction
	EPROM_Send(Data); //Send Data
	EPROM_Stop(); //Call stop
	Delay(10); //Delay
}

unsigned char EPROM_ReadByte(unsigned char Address, unsigned char Page)
{
	unsigned char Data;

		EPROM_Start(); //Call staret
		EPROM_Send(0xA0 | (Page<<1));// Send page number
		EPROM_Send(Address); //Send address location
		EPROM_Start(); //Call start
		EPROM_Send(0xA1 | (Page<<1)); //Send page number
		Data = EPROM_Read(); //Read Data
		EPROM_Stop(); // Call Stop
		Delay(5); //Delay
		return Data;
}