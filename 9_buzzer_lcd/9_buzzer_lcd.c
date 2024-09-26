#include <reg51.h> 
sbit rs=P1^0; 
sbit rw=P1^1; 
sbit e= P1^2; 
 
#define SWITCH P3 // Input Switches (buttons) to PORT1 
sbit buzz = P0^7; // Buzzer 
sbit rst = P1^7; // Reset Switch (Reset the display) - not the microcontrolle 
void delay(unsigned int); 
void cmd(unsigned char); 
void dat(unsigned char); 
unsigned char btnPressed; 
void main(void) 
{ 
 
 
cmd(0x38); 
cmd(0x01); 
cmd(0x0c); 
//cmd(0x83); 
//cmd(0x06); 
 
 
buzz = 0; // Initialize buzzer off 
 
 
while (1) { 
btnPressed = SWITCH; // Read the state of the switches 
 
if (btnPressed != 0xFF) { // If any button is pressed 
cmd(0x01); // Clear display 
cmd(0x80); // Move cursor to the beginning of the first line 
dat('0' + (btnPressed & 0x0F)); // Display the pressed button number 
buzz = 1; // Turn on the buzzer 
delay(1000); // Keep buzzer on for 1 second 
buzz = 0; // Turn off the buzzer 
while (SWITCH != 0xFF); // Wait until the button is released 
} 
} 
} 
void delay(int ms) { 
unsigned int i, j; 
for (i = 0; i < ms; i++) { 
for (j = 0; j < 120; j++); // Delay loop, adjust based on your microcontroller's clock frequency 
} 
}
 
void cmd(unsigned char ch) 
{ 
 
rs=0; 
rw=0; 
P2=ch; 
delay(20); 
} 
void dat(unsigned char ch) 
{ 
 
rs=1; 
rw=0; 
P2=ch; 
delay(100); 
} 
