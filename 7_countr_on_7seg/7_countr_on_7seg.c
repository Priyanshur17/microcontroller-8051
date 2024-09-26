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
unsigned int ch[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; 
unsigned int r,i; 
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
 
i=0; 
while(i<=r){ 
P2 = ch[i]; 
i++; 
Delay(650); 
} 
P2=0xc0; 
} 
} 
