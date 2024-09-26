/*
#include <reg51.h>
#define msec 10

unsigned int arr[10] = {0x40, 0xF9, 0x24, 0x30, 0x19, 0x12, 0x02, 0xF8, 0x00, 0x10};
sbit d2 = P1^0;
sbit d1 = P1^1;
sbit d0 = P1^2;
sbit d = P1^3;
unsigned int v1, v2, v3, v4,v0;

void delay(unsigned int count) {
    unsigned int j, k;
    for (j = 0; j <= count; j++)
        for (k = 0; k <= 5; k++);
}

void main() {
    v1 = 9;
    v2 = 9;
    v3 = 9;
    v4 = 9;

    while (1) {
        P2 = 0xFF;
        d = 1;
        d2 = d0 = d1 = 0;
        P2 = arr[v1];
        delay(msec);

        P2 = 0xFF;
        d0 = 1;
        d1 = d = d2 = 0;
        P2 = arr[v2];
        delay(msec);

        P2 = 0xFF;
        d1 = 1;
        d2 = d = d0 = 0;
        P2 = arr[v3];
        delay(msec);

        P2 = 0xFF;
        d2 = 1;
        d1 = d = d0 = 0;
        P2 = arr[v4];
        delay(msec);

        if (v1 == 0 && v2 == 0 && v3 == 0 && v4 == 0) {
            // If the counter reaches 0000, reset to 9999
            v1 = 9;
            v2 = 9;
            v3 = 9;
            v4 = 9;
        } else {
            // Decrement the counter
           // if (v0 == 0) {
               // v0 = 9;
                if (v1 > 0) v1--;
                else {
                    v1 = 9;
                    if (v2 > 0) v2--;
                    else {
                        v2 = 9;
                        if (v3 > 0) v3--;
                        else {
                            v3 = 9;
                            if (v4 > 0) v4--;
                            else v4 = 9;
                        }
                    }
                }
            //} else {
               // v0--;
           // }
        }
    }
}
*/


#include <reg51.h>
#define msec 100
unsigned int arr[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x10};
sbit d2=P1^0;
sbit d1=P1^1;
sbit d0=P1^2;
sbit d= P1^3;
unsigned int v1,v2,v3,v4,v0;
void delay(unsigned int count)
{
unsigned int j,k;
for (j=0;j<=count;j++)
for (k=0;k<=5;k++);
}
void main()
{
 v1=v2=v3=v4=v0=0;
 while(1)
{  
{
     v0=v0+1;
if(v0==2)
{
v0=1;
v1=v1+1;
}

    P2=0xFF;
   if(v1==10)
{
v1=0;
v2=v2+1;
}
d = 1;
d2 = d0 = d1= 0;
P2 = arr[v1];
delay(msec);


P2=0xFF;
   if(v2==10)
{
v2=0;
v3=v3+1;
}
d0 = 1;
d1 =d=d2= 0;
P2 = arr[v2];
delay(msec);


P2=0xFF;
   if(v3==10)
{
v3=0;
v4=v4+1;
}
d1 = 1;
d2 =d=d0= 0;
P2 = arr[v3];
delay(msec);


P2=0xFF;
if(v4==10)
{
v1=0;
v2=0;
v3=0;
v4=0;
    }
d2 = 1;
d1 =d=d0= 0;
P2 = arr[v4];
delay(msec);


delay(msec);
P2=0xFF;
}
}
}

