#include <reg51.h> #include <stdio.h> #include <stdlib.h> #include <string.h>

#define LCD_DATA P2

void delay_ms(unsigned int ms) { unsigned int i, j;
for (i = 0; i < ms; i++)
for (j = 0; j < 300; j++); // Adjust this loop count based on your microcontroller's clock frequency
}

sbit rs = P1^0; sbit rw = P1^1;
sbit e = P1^2;

sbit btn0 = P3^0; sbit btn1 = P3^1; sbit btn2 = P3^2; sbit btn3 = P3^3; sbit btn4 = P3^4; sbit btn5 = P3^5; sbit btn6 = P3^6; sbit btn7 = P3^7;

sbit btnPlus = P1^3; sbit btnMinus = P1^4; sbit btnMultiply = P1^5; sbit btnDivide = P1^6; sbit btnEquals = P1^7;

void LCD_command(unsigned char command) { rs = 0; // Selecting command
rw = 0; // We are writing to the LCD LCD_DATA = command; // Sending the command e = 1;
delay_ms(1); e = 0;
delay_ms(1);
}

void LCD_data(unsigned char dat) { rs = 1; // Selecting
rw = 0; // We are writing to the LCD LCD_DATA = dat; // Sending the
e = 1;
delay_ms(1); e = 0;
delay_ms(1);
}

void LCD_init() {
LCD_command(0x38); // 2 lines, 5x8 matrix LCD_command(0x0E); // Display on, cursor blinking LCD_command(0x01); // Clear display delay_ms(10);
LCD_command(0x06); // Increment cursor
}

void LCD_clear() {
LCD_command(0x01); // Clear display delay_ms(10);
}

void LCD_print(char *str) {
LCD_clear(); // Clear the display before printing while (*str != '\0') {
LCD_data(*str); str++;
}
}

void LCD_print_number(int num) { char buffer[16]; sprintf(buffer, "%d", num); LCD_print(buffer);
}

void main() {
unsigned char operand1[3] = ""; unsigned char operand2[3] = ""; char operator = '\0';
int result = 0;

LCD_init();

while (1) {
if (btn0 == 1) {
if (strlen(operand1) < 2) { strcat(operand1, "0"); LCD_print(operand1);
}
}

if (btn1 == 1) {
if (strlen(operand1) < 2) { strcat(operand1, "1"); LCD_print(operand1);
}
}

// Repeat this pattern for btn2 to btn7

if (btnPlus == 1 || btnMinus == 1 || btnMultiply == 1 || btnDivide == 1) { operator = btnPlus == 1 ? '+' : btnMinus == 1 ? '-' : btnMultiply == 1
? '*' : '/';
LCD_print(&operator);
}

if (btn2 == 1) {
if (strlen(operand2) < 2) { strcat(operand2, "2"); LCD_print(operand2);
}
}
// Repeat this pattern for btn3 to btn7

if (btnEquals == 1 && operator != '\0') { int num1 = atoi(operand1);
int num2 = atoi(operand2);

switch (operator) { case '+':
result = num1 + num2; break;
case '-':
result = num1 - num2; break;
case '*':
result = num1 * num2; break;
case '/':
if (num2 != 0) {
result = num1 / num2;
} else {
LCD_clear();
LCD_print("Error: Division by 0");
while (1); // End the program or handle the error as needed
}
break;
}

LCD_print("="); LCD_print_number(result);
break; // End the program after displaying the result
}
}

while (1); // Infinite loop to keep the program running
}
