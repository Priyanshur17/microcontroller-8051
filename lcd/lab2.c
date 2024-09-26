#include <reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit e= P1^2;
void delay(unsigned int);
void cmd(unsigned char);
void dat(unsigned char);

void main(void)
{
unsigned char ch[]="Priyanshu Raj";
unsigned char ch1[]="2021UCP1148";
	
	
	
	
	
unsigned int i,j,k;

cmd(0x38);
cmd(0x01);
cmd(0x0c);
//cmd(0x83);
//cmd(0x06);


for(i=0;ch[i]!='\0';i++)
   dat(ch[i]);

cmd(0xc0);
for(j=0;ch1[j]!='\0';j++)
{
dat(ch1[j]);
  }
while(1){
for(k=0;k<16;k++)
{
cmd(0x1c);
}
}
}
void delay(unsigned int t)
{
unsigned int i,j;
e=1;
for(i=0;i<t;i++)
for(j=0;j<1275;j++);
e=0;
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





/*
#include <reg51.h>

sbit rs = P1^0;
sbit rw = P1^1;
sbit e  = P1^2;

sbit btn0 = P3^0;
sbit btn1 = P3^1;
sbit btn2 = P3^2;
sbit btn3 = P3^3;
sbit btn4 = P3^4;
sbit btn5 = P3^5;
sbit btn6 = P3^6;
sbit btn7 = P3^7;
sbit btnPlus = P1^3;
sbit btnMinus = P1^4;
sbit btnMultiply = P1^5;
sbit btnDivide = P1^6;
sbit btnEquals = P1^7;


void delay(unsigned int t);
void lcd_init();
void cmd(unsigned char ch);
void dat(unsigned char ch);
void display(char* str);
char getButtonPress();

void main(void) {
    char input[16];
    char result[16];
    unsigned char i = 0;

    lcd_init();

    while (1) {
        char button = getButtonPress();
        
        if (button != '\0' && i < 15) {
            input[i] = button;
            input[i + 1] = '\0';
            i++;
            display(input);
        }

        if (button == '=') {
            // Assuming the operator is the second-to-last character
            char operator = input[i - 2];
            calculate(operator);
            display(input);
            i = 0;
        }
    }
}

void delay(unsigned int t) {
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 1275; j++);
}

void lcd_init() {
    cmd(0x38);  // 2 lines, 5x8 matrix
    cmd(0x01);  // Clear display
    cmd(0x0c);  // Display ON, Cursor OFF
    cmd(0x80);  // Set cursor to the beginning of the first line
}

void cmd(unsigned char ch) {
    rs = 0;
    rw = 0;
    P2 = ch;
    e = 1;
    delay(20);
    e = 0;
}

void dat(unsigned char ch) {
    rs = 1;
    rw = 0;
    P2 = ch;
    e = 1;
    delay(20);
    e = 0;
}

void display(char* str) {
    cmd(0x01);  // Clear display
    cmd(0x80);  // Set cursor to the beginning of the first line
    while (*str != '\0') {
        dat(*str);
        str++;
    }
}

char getButtonPress() {
    if (!btn0) {
        delay(50);
        while (!btn0);
        return '0';
    }
    if (!btn1) {
        delay(50);
        while (!btn1);
        return '1';
    }
    if (!btn2) {
        delay(50);
        while (!btn2);
        return '2';
    }
    if (!btn3) {
        delay(50);
        while (!btn3);
        return '3';
    }
    if (!btn4) {
        delay(50);
        while (!btn4);
        return '4';
    }
    if (!btn5) {
        delay(50);
        while (!btn5);
        return '5';
    }
    if (!btn6) {
        delay(50);
        while (!btn6);
        return '6';
    }
    if (!btn7) {
        delay(50);
        while (!btn7);
        return '7';
    }
    
    // Assume # for division, * for multiplication, + for addition, - for subtraction, = for equals
    if (!btnPlus) {
        delay(50);
        while (!btnPlus);
        return '+';
    }
    if (!btnMinus) {
        delay(50);
        while (!btnMinus);
        return '-';
    }
    if (!btnMultiply) {
        delay(50);
        while (!btnMultiply);
        return '*';
    }
    if (!btnDivide) {
        delay(50);
        while (!btnDivide);
        return '#';
    }
    if (!btnEquals) {
        delay(50);
        while (!btnEquals);
        return '=';
    }

    return '\0';
}

void calculate(char operator) {
    char* token;
    char num1[8];
    char num2[8];
    int operand1, operand2;
    int result;

    token = strtok(input, &operator);
    strcpy(num1, token);
    operand1 = atoi(num1);

    token = strtok(NULL, &operator);
    strcpy(num2, token);
    operand2 = atoi(num2);

    switch (operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '#':
            if (operand2 != 0)
                result = operand1 / operand2;
            else
                result = 0;  // Division by zero, handle appropriately
            break;
    }

    sprintf(result, "%d", result);
    strcpy(input, result);
}



#include <reg51.h>
#include <string.h>
#include <stdlib.h>  // Include this header for atoi function
#include <stdio.h>   // Include this header for sprintf function

sbit rs = P1^0;
sbit rw = P1^1;
sbit e  = P1^2;

sbit btn0 = P3^0;
sbit btn1 = P3^1;
sbit btn2 = P3^2;
sbit btn3 = P3^3;
sbit btn4 = P3^4;
sbit btn5 = P3^5;
sbit btn6 = P3^6;
sbit btn7 = P3^7;

sbit btnPlus = P1^3;    // Connect this button for addition
sbit btnMinus = P1^4;   // Connect this button for subtraction
sbit btnMultiply = P1^5; // Connect this button for multiplication
sbit btnDivide = P1^6;   // Connect this button for division
sbit btnEquals = P1^7;   // Connect this button for equals

char operand1[16];  // String to store the first operand
char operand2[16];  // String to store the second operand
char operator;      // Variable to store the operator
char input[32];      // String to store the entire expression (input)
int val=0;
// Function prototypes
void delay(unsigned int t) {
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 127; j++);
}
void cmd(unsigned char ch) ;
void calculate();
void display(char* str);
char getButtonPress();
void dat(unsigned char ch);

void lcd_init();
void main(void) {
    unsigned char i = 0;

    lcd_init();

    while (1) {
        char button = getButtonPress();
        
        if (button != '\0' && i < 15) {
            input[i] = button;
            input[i + 1] = '\0';
            i++;
            
        }

        if (button == '=') {
            // Assuming the operator is the second-to-last character
            operator = input[i - 2];

            // Separate the operands and store them in operand1 and operand2
            strcpy(operand1, strtok(input, &operator));
            strcpy(operand2, strtok(NULL, &operator));

            calculate();

            // Display the entire expression and result
            display(input);
            i = 0;
        }
    }
}

void display(char* str) {
    cmd(0x01);  // Clear display
    cmd(0x80);  // Set cursor to the beginning of the first line
    while (str[val] != '\0') {
        dat(str[val]);
        val++;
    }
}

void calculate() {
    int num1 = atoi(operand1);
    int num2 = atoi(operand2);
    int result;

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '#':
            if (num2 != 0)
                result = num1 / num2;
            else
                result = 0;  // Division by zero, handle appropriately
            break;
    }

    // Display the entire expression and result
    sprintf(input, "%s %c %s = %d", operand1, operator, operand2, result);
}
char getButtonPress() {
    if (btn0) {
        delay(10);
        while (!btn0);
        return '0';
    }
    if (btn1) {
        delay(10);
        while (!btn1);
        return '1';
    }
    if (btn2) {
        delay(10);
        while (!btn2);
        return '2';
    }
    if (btn3) {
        delay(10);
        while (!btn3);
        return '3';
    }
    if (btn4) {
        delay(10);
        while (!btn4);
        return '4';
    }
    if (btn5) {
        delay(10);
        while (!btn5);
        return '5';
    }
    if (btn6) {
        delay(10);
        while (!btn6);
        return '6';
    }
    if (btn7) {
        delay(10);
        while (!btn7);
        return '7';
    }
    
    // Assume # for division, * for multiplication, + for addition, - for subtraction, = for equals
    if (btnPlus) {
        delay(10);
        while (!btnPlus);
        return '+';
    }
    if (btnMinus) {
        delay(10);
        while (!btnMinus);
        return '-';
    }
    if (btnMultiply) {
        delay(10);
        while (!btnMultiply);
        return '*';
    }
    if (btnDivide) {
        delay(10);
        while (!btnDivide);
        return '#';
    }
    if (btnEquals) {
        delay(10);
        while (!btnEquals);
        return '=';
    }

    return '\0';
}
void lcd_init() {
    //cmd(0x38);  // 2 lines, 5x8 matrix
    cmd(0x01);  // Clear display
    cmd(0x0c);  // Display ON, Cursor OFF
    cmd(0x80);  // Set cursor to the beginning of the first line
}

void cmd(unsigned char ch) {
    rs = 0;
    rw = 0;
    P2 = ch;
    e = 1;
    delay(10);
    e = 0;
}

void dat(unsigned char ch) {
    rs = 1;
    rw = 0;
    P2 = ch;
    e = 1;
    delay(10);
    e = 0;
}

*/

//#include <reg51.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define LCD_DATA P2
//
//void delay_ms(unsigned int ms) {
//    unsigned int i, j;
//    for (i = 0; i < ms; i++)
//        for (j = 0; j < 300; j++);  // Adjust this loop count based on your microcontroller's clock frequency
//}
//
//sbit rs = P1^0;
//sbit rw = P1^1;
//sbit e  = P1^2;
//
//sbit btn0 = P3^0;
//sbit btn1 = P3^1;
//sbit btn2 = P3^2;
//sbit btn3 = P3^3;
//sbit btn4 = P3^4;
//sbit btn5 = P3^5;
//sbit btn6 = P3^6;
//sbit btn7 = P3^7;
//
//sbit btnPlus = P1^3;
//sbit btnMinus = P1^4;
//sbit btnMultiply = P1^5;
//sbit btnDivide = P1^6;
//sbit btnEquals = P1^7;
//
//void LCD_command(unsigned char command) {
//    rs = 0; // Selecting command
//    rw = 0; // We are writing to the LCD
//    LCD_DATA = command; // Sending the command
//    e = 1;
//    delay_ms(1);
//    e = 0;
//    delay_ms(1);
//}
//
//void LCD_data(unsigned char dat) {
//    rs = 1; // Selecting 
//    rw = 0; // We are writing to the LCD
//    LCD_DATA = dat; // Sending the
//    e = 1;
//    delay_ms(1);
//    e = 0;
//    delay_ms(1);
//}
//
//void LCD_init() {
//    LCD_command(0x38); // 2 lines, 5x8 matrix
//    LCD_command(0x0E); // Display on, cursor blinking
//    LCD_command(0x01); // Clear display
//    delay_ms(10);
//    LCD_command(0x06); // Increment cursor
//}
//
//void LCD_clear() {
//    LCD_command(0x01); // Clear display
//    delay_ms(10);
//}
//
//void LCD_print(char *str) {
//    LCD_clear(); // Clear the display before printing
//    while (*str != '\0') {
//        LCD_data(*str);
//        str++;
//    }
//}
//
//void LCD_print_number(int num) {
//    char buffer[16];
//    sprintf(buffer, "%d", num);
//    LCD_print(buffer);
//}
//
//void main() {
//    unsigned char operand1[3] = "";
//    unsigned char operand2[3] = "";
//    char operator = '\0';
//    int result = 0;
//
//    LCD_init();
//
//    while (1) {
//        if (btn0 == 1) {
//            if (strlen(operand1) < 2) {
//                strcat(operand1, "0");
//                LCD_print(operand1);
//            }
//        }
//
//        if (btn1 == 1) {
//            if (strlen(operand1) < 2) {
//                strcat(operand1, "1");
//                LCD_print(operand1);
//            }
//        }
//
//        // Repeat this pattern for btn2 to btn7
//
//        if (btnPlus == 1 || btnMinus == 1 || btnMultiply == 1 || btnDivide == 1) {
//            operator = btnPlus == 1 ? '+' : btnMinus == 1 ? '-' : btnMultiply == 1 ? '*' : '/';
//            LCD_print(&operator);
//        }
//
//        if (btn2 == 1) {
//            if (strlen(operand2) < 2) {
//                strcat(operand2, "2");
//                LCD_print(operand2);
//            }
//        }
//
//        // Repeat this pattern for btn3 to btn7
//
//        if (btnEquals == 1 && operator != '\0') {
//            int num1 = atoi(operand1);
//            int num2 = atoi(operand2);
//
//            switch (operator) {
//                case '+':
//                    result = num1 + num2;
//                    break;
//                case '-':
//                    result = num1 - num2;
//                    break;
//                case '*':
//                    result = num1 * num2;
//                    break;
//                case '/':
//                    if (num2 != 0) {
//                        result = num1 / num2;
//                    } else {
//                        LCD_clear();
//                        LCD_print("Error: Division by 0");
//                        while (1); // End the program or handle the error as needed
//                    }
//                    break;
//            }
//
//            LCD_print("=");
//            LCD_print_number(result);
//            break; // End the program after displaying the result
//        }
//    }
//
//    while (1); // Infinite loop to keep the program running
//}
