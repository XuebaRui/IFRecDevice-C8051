/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////
#include "c8051f330.h"
//input
sbit AGC_1dB = P2^3;
sbit AGC_2dB = P2^2;
sbit AGC_4dB = P2^1;
sbit AGC_8dB = P2^0;
sbit AGC_16dB = P1^7;
sbit AGC_32dB = P1^6;
sbit AGC_64dB = P1^5;
//output
sbit A1_1dB = P1^0;
sbit A1_2dB = P1^1;
sbit A1_4dB = P1^2;
sbit A1_8dB = P1^3;
sbit A1_16dB = P1^4;
sbit A2_31dB = P0^5;
sbit A3_1dB = P0^0;
sbit A3_2dB = P0^1;
sbit A3_4dB = P0^2;
sbit A3_8dB = P0^3;
sbit A3_16dB = P0^4;

// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Port_IO_Init()
{
    // P0.0  -  Unassigned,  Push-Pull,  Digital
    // P0.1  -  Unassigned,  Push-Pull,  Digital
    // P0.2  -  Unassigned,  Push-Pull,  Digital
    // P0.3  -  Unassigned,  Push-Pull,  Digital
    // P0.4  -  Unassigned,  Push-Pull,  Digital
    // P0.5  -  Unassigned,  Push-Pull,  Digital
    // P0.6  -  Unassigned,  Open-Drain, Digital
    // P0.7  -  Unassigned,  Open-Drain, Digital

    // P1.0  -  Unassigned,  Push-Pull,  Digital
    // P1.1  -  Unassigned,  Push-Pull,  Digital
    // P1.2  -  Unassigned,  Push-Pull,  Digital
    // P1.3  -  Unassigned,  Push-Pull,  Digital
    // P1.4  -  Unassigned,  Push-Pull,  Digital
    // P1.5  -  Unassigned,  Open-Drain, Digital
    // P1.6  -  Unassigned,  Open-Drain, Digital
    // P1.7  -  Unassigned,  Open-Drain, Digital

    // P2.0  -  Unassigned,  Open-Drain, Digital
    // P2.1  -  Unassigned,  Open-Drain, Digital
    // P2.2  -  Unassigned,  Open-Drain, Digital
    // P2.3  -  Unassigned,  Open-Drain, Digital

    P0MDOUT   = 0x3F;
    P1MDOUT   = 0x1F;
    XBR1      = 0x40;
}

void Oscillator_Init()
{
    OSCICN    = 0x83;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Port_IO_Init();
    Oscillator_Init();
}
int main(void)
{
	unsigned char Agc_Val = 0;
	Init_Device();
	while(1)
	{
		Agc_Val = (unsigned char)AGC_1dB | ((unsigned char)AGC_2dB << 2) | ((unsigned char)AGC_4dB << 2) | ((unsigned char)AGC_8dB << 3) |
				     ((unsigned char)AGC_16dB << 4) | ((unsigned char)AGC_32dB << 5) | ((unsigned char)AGC_64dB << 6);                       
		if(Agc_Val <= 31)
		{
			A1_1dB = Agc_Val & 0x01 ? 1 : 0;
			A1_2dB = Agc_Val & 0x01 ? 1 : 0;
			A1_4dB = Agc_Val & 0x01 ? 1 : 0;
			A1_8dB = Agc_Val & 0x01 ? 1 : 0;
			A1_16dB = Agc_Val & 0x01 ? 1 : 0;
			
			A2_31dB =  0;
			A3_1dB =  0;
			A3_2dB =  0;
			A3_4dB =  0;
			A3_8dB =  0;
			A3_16dB = 0;	
		}
		else if (Agc_Val <= 62)
		{
			A1_1dB =  (Agc_Val - 31) & 0x01 ? 1 : 0;
			A1_2dB =  (Agc_Val - 31) & 0x01 ? 1 : 0;
			A1_4dB =  (Agc_Val - 31) & 0x01 ? 1 : 0;
			A1_8dB =  (Agc_Val - 31) & 0x01 ? 1 : 0;
			A1_16dB = (Agc_Val - 31) & 0x01 ? 1 : 0;	
			A2_31dB =  1; //31db
			
			A3_1dB =  0;
			A3_2dB =  0;
			A3_4dB =  0;
			A3_8dB =  0;
			A3_16dB = 0;
		}
		else
		{
			A1_1dB  =  1;
			A1_2dB  =  1;
			A1_4dB  =  1;
			A1_8dB  =  1;
			A1_16dB =  1;	
			A2_31dB =  1; //62db
			
			A3_1dB =  (Agc_Val - 62) & 0x01 ? 1 : 0;
			A3_2dB =  (Agc_Val - 62) & 0x01 ? 1 : 0;
			A3_4dB =  (Agc_Val - 62) & 0x01 ? 1 : 0;
			A3_8dB =  (Agc_Val - 62) & 0x01 ? 1 : 0;
			A3_16dB = (Agc_Val - 62) & 0x01 ? 1 : 0;				
		}
	}
}
