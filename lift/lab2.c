#include <REG51.H>

sbit UP_LED = P3^0;
sbit DOWN_LED = P3^1;

sbit a = P2^0;
sbit b = P2^1;
sbit c = P2^2;
sbit d = P2^3;
sbit e = P2^4;
sbit f = P2^5;
sbit g = P2^6;
int currentFloor=0;
int floo;// Assume the lift starts from the ground floor
unsigned int segments[] = {0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x10};

void displayDigit(unsigned int digit) {
    P2 = segments[digit];
}

void delay(unsigned int count) {
    unsigned int i, j;
    for (i = 0; i < count; i++)
        for (j = 0; j < 500; j++);
}

void moveUp(int diff) {
    UP_LED = 1;  // Indicate up movement
    DOWN_LED = 0;  // No down movement
     // Moved the declaration of floo to the top of the function
    for (floo = currentFloor; floo <= currentFloor+diff; floo++) {
        displayDigit(floo % 10);
        delay(500);  // Simulate movement delay
    }
    currentFloor = floo - 1; // Update the current floor after the loop
}

void moveDown(int diff) {
    UP_LED = 0;  // No up movement
    DOWN_LED = 1;  // Indicate down movement
     // Moved the declaration of floo to the top of the function
    for (floo = currentFloor; floo >= currentFloor-diff; floo--) {
        displayDigit(floo % 10);
        delay(500);  // Simulate movement delay
    }
    currentFloor = floo + 1; // Update the current floor after the loop
}

void stop(int currentFloor) {
    UP_LED = 0;  // No up movement
    DOWN_LED = 0;  // No down movement
    displayDigit(currentFloor % 10);  // Display current floor
    delay(500);  // Simulate stop delay
}

void control(int targetFloor) {
    if (targetFloor > currentFloor) {
        moveUp(targetFloor - currentFloor);
    } else if (targetFloor < currentFloor) {
        moveDown(currentFloor - targetFloor);
    }
    stop(currentFloor);
}

void main() {
    UP_LED = 0;  // Initialize up LED to OFF
    DOWN_LED = 0;  // Initialize down LED to OFF
 
    while (1) {
			if(P0 == 1){
				control(0);
			}
       else if (P0 == 32) {
            control(5);
        } else if (P0 == 2) {
            control(1);
        } else if (P0 == 4) {
            control(2);
        } else if (P0 == 8) {
            control(3);
        } else if (P0 == 16) {
            control(4);
        }
    }
}


/*
#include <REG51.H>
#include <stdio.h>
int p,q,r;
//q=10; //for every motor freezing count
//r=10; //rotation of the motor 0 min 32000 max
delay(c)
{
int i,j;
if(c==0)
{
for(i=0;i<500;i++)
{
for(j=0;j<r;j++);
}
}
return c;
}
// elevator going up
up(b)
{
int i,j;
for (i=1;i<=b;i++)
{
for (j=0;j<=10;j++)
{
P3=1;
delay(0);
P3=2;
delay(0);
P3=4;
delay(0);
P3=8;
delay(0);
P3=16;
delay(0);
}
P2=p+i;
}
p=p+b;
return b;
}
// elevator going down
down(b)
{
int i,j;
for (i=1;i<=b;i++)
{
for (j=0;j<=q;j++)
{
P3=16;
delay(0);
P3=8;
P3=4;
delay(0);
P3=2;
delay(0);
P3=1;
delay(0);
}
P2=p-i;
}
p=p-b;
return b;
}
control(a)
{
int difference;
if(a>p)
{
difference=a-p;
up(difference);
}
if(a<p)
{
difference=p-a;
down(difference);
}
return a;
}
main()
{
int p1;
p=0;
P2=p;
while(1)
{
if(P0==2)
{
p1=1;
control(1);
}
if(P0==4)
{
p1=2;
control(2);
}
if(P0==8)
{
p1=3;
control(3);
}
if(P0==16)
{
p1=4;
delay(0);
control(4);
}
if(P0==32)
{
p1=5;
control(5);
}
if(P0==1)
{
p1=0;
control(0);
}
}
}

*/

