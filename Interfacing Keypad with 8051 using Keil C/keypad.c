// #include<reg52.h>							 
// #include<lcd.h>

// //LCD Module Connections
// sbit RS = P0^0;                                                                   
// sbit EN = P0^1;                            
// sbit D0 = P2^0;
// sbit D1 = P2^1;
// sbit D2 = P2^2;
// sbit D3 = P2^3;
// sbit D4 = P2^4;
// sbit D5 = P2^5;
// sbit D6 = P2^6;
// sbit D7 = P2^7;
// //End LCD Module Connections

// //Keypad Connections
// sbit R1 = P1^0;
// sbit R2 = P1^1;
// sbit R3 = P1^2;
// sbit R4 = P1^3;
// sbit C1 = P1^4;
// sbit C2 = P1^5;
// sbit C3 = P1^6;
// sbit C4 = P1^7;
// //End Keypad Connections

// void Delay(int a)
// {
//     int j;
//     int i;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<100;j++)
//         {
//         }
//     }
// }

// char Read_Keypad()
// {
//  C1=1;
//  C2=1;
//  C3=1;
//  C4=1;
//  R1=0;
//  R2=1;
//  R3=1;
//  R4=1;
//  if(C1==0){Delay(100);while(C1==0);return '7';}
//  if(C2==0){Delay(100);while(C2==0);return '8';}
//  if(C3==0){Delay(100);while(C3==0);return '9';}
//  if(C4==0){Delay(100);while(C4==0);return '/';}
//  R1=1;
//  R2=0;
//  R3=1;
//  R4=1;
//  if(C1==0){Delay(100);while(C1==0);return '4';}
//  if(C2==0){Delay(100);while(C2==0);return '5';}
//  if(C3==0){Delay(100);while(C3==0);return '6';}
//  if(C4==0){Delay(100);while(C4==0);return 'X';}
//  R1=1;
//  R2=1;
//  R3=0;
//  R4=1;
//  if(C1==0){Delay(100);while(C1==0);return '1';}
//  if(C2==0){Delay(100);while(C2==0);return '2';}
//  if(C3==0){Delay(100);while(C3==0);return '3';}
//  if(C4==0){Delay(100);while(C4==0);return '-';}
//  R1=1;
//  R2=1;
//  R3=1;
//  R4=0;
//  if(C1==0){Delay(100);while(C1==0);return 'C';}
//  if(C2==0){Delay(100);while(C2==0);return '0';}
//  if(C3==0){Delay(100);while(C3==0);return '=';}
//  if(C4==0){Delay(100);while(C4==0);return '+';}
//  return 0 ;
// }

// void main()
// {
// 	int i=0;
// 	char c,p;
// 	Lcd8_Init();
// 	c='_';                                  
//   while(1)
//   {                                   
// 		Lcd8_Set_Cursor(1,1);
// 		Lcd8_Write_String("Keys Pressed:");
// 		Lcd8_Set_Cursor(2,1);
// 		Lcd8_Write_String("Times:");
//     while(!(c = Read_Keypad()));
// 		p=c;
// 		while(p==c)
// 		{
// 			i++;
// 			Lcd8_Set_Cursor(1,14);
// 			Lcd8_Write_Char(c);
// 			Lcd8_Set_Cursor(2,7);
// 			Lcd8_Write_Char(i+48);
// 		  Delay(100);
// 	    while(!(c = Read_Keypad()));
//    }
// 	 i=0;
// 	 Lcd8_Clear();
//  }
// }



// #include<reg52.h>							 
// #include<lcd.h>



// //Keypad Connections
// sbit R1 = P1^0;
// sbit R2 = P1^1;
// sbit R3 = P1^2;
// sbit R4 = P1^3;
// sbit C1 = P1^4;
// sbit C2 = P1^5;
// sbit C3 = P1^6;
// sbit C4 = P1^7;
// //End Keypad Connections

// void Delay(int a)
// {
//     int j;
//     int i;
//     for(i=0;i<a;i++)
//     {
//         for(j=0;j<100;j++)
//         {
//         }
//     }
// }

// char Read_Keypad()
// {
//  C1=1;
//  C2=1;
//  C3=1;
//  C4=1;
//  R1=0;
//  R2=1;
//  R3=1;
//  R4=1;
//  if(C1==0){Delay(100);while(C1==0);return '7';}
//  if(C2==0){Delay(100);while(C2==0);return '8';}
//  if(C3==0){Delay(100);while(C3==0);return '9';}
//  if(C4==0){Delay(100);while(C4==0);return '/';}
//  R1=1;
//  R2=0;
//  R3=1;
//  R4=1;
//  if(C1==0){Delay(100);while(C1==0);return '4';}
//  if(C2==0){Delay(100);while(C2==0);return '5';}
//  if(C3==0){Delay(100);while(C3==0);return '6';}
//  if(C4==0){Delay(100);while(C4==0);return 'X';}
//  R1=1;
//  R2=1;
//  R3=0;
//  R4=1;
//  if(C1==0){Delay(100);while(C1==0);return '1';}
//  if(C2==0){Delay(100);while(C2==0);return '2';}
//  if(C3==0){Delay(100);while(C3==0);return '3';}
//  if(C4==0){Delay(100);while(C4==0);return '-';}
//  R1=1;
//  R2=1;
//  R3=1;
//  R4=0;
//  if(C1==0){Delay(100);while(C1==0);return 'C';}
//  if(C2==0){Delay(100);while(C2==0);return '0';}
//  if(C3==0){Delay(100);while(C3==0);return '=';}
//  if(C4==0){Delay(100);while(C4==0);return '+';}
//  return 0 ;
// }
// unsigned int ch[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
// unsigned int r,i;
// void main()
// {
// 	int i=0;
// 	char c,p;
// 	P2=0xc0;
// 	c='_';                                  
//   while(1)
//   {                                   
	

//     c = Read_Keypad();
	
//     r = c-'0';
// 	if(r>9 || r<0){continue;}

// 	i=0;
// 	while(i<=r){
// 		P2 = ch[i];
// 		i++;
// 		Delay(650);
// 	}
// 	P2=0xc0;
//  }
// }





#include<reg52.h>							 
#include<lcd.h>



//Keypad Connections
sbit R1 = P1^0;
sbit R2 = P1^1;
sbit R3 = P1^2;
sbit R4 = P1^3;
sbit C1 = P1^4;
sbit C2 = P1^5;
sbit C3 = P1^6;
sbit C4 = P1^7;
//End Keypad Connections

void Delay(int a)
{
    int j;
    int i;
    for(i=0;i<a;i++)
    {
        for(j=0;j<100;j++)
        {
        }
    }
}

char Read_Keypad()
{
 C1=1;
 C2=1;
 C3=1;
 C4=1;
 R1=0;
 R2=1;
 R3=1;
 R4=1;
 if(C1==0){Delay(100);while(C1==0);return '7';}
 if(C2==0){Delay(100);while(C2==0);return '8';}
 if(C3==0){Delay(100);while(C3==0);return '9';}
 if(C4==0){Delay(100);while(C4==0);return '/';}
 R1=1;
 R2=0;
 R3=1;
 R4=1;
 if(C1==0){Delay(100);while(C1==0);return '4';}
 if(C2==0){Delay(100);while(C2==0);return '5';}
 if(C3==0){Delay(100);while(C3==0);return '6';}
 if(C4==0){Delay(100);while(C4==0);return 'X';}
 R1=1;
 R2=1;
 R3=0;
 R4=1;
 if(C1==0){Delay(100);while(C1==0);return '1';}
 if(C2==0){Delay(100);while(C2==0);return '2';}
 if(C3==0){Delay(100);while(C3==0);return '3';}
 if(C4==0){Delay(100);while(C4==0);return '-';}
 R1=1;
 R2=1;
 R3=1;
 R4=0;
 if(C1==0){Delay(100);while(C1==0);return 'C';}
 if(C2==0){Delay(100);while(C2==0);return '0';}
 if(C3==0){Delay(100);while(C3==0);return '=';}
 if(C4==0){Delay(100);while(C4==0);return '+';}
 return 0 ;
}
unsigned int arr[10] = {0x40, 0xF9, 0x24, 0x30, 0x19, 0x12, 0x02, 0xF8, 0x00, 0x10};
unsigned int r;

sbit d2 = P3 ^ 0;
sbit d1 = P3 ^ 1;
sbit d0 = P3 ^ 2;
sbit d = P3 ^ 3;
void main()
{
	int i=0;
	char c,p;
	P2=0xc0;
	c='_';                                  
  while(1)
  {                                   
	

    c = Read_Keypad();
	
    r = c-'0';
	if(r>9 || r<0){continue;}

	d=1;
	d1=d2=d0=0;
	P2=arr[r];
 }
}