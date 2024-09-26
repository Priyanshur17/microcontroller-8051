
#include <reg51.h>
#include <stdlib.h>

void clock_rot(void);
void anti_rot(void);
void wave_patt(void);
void random_patt(void);

sbit btn_a = P0^0;
sbit btn_b = P0^1;
sbit btn_c = P0^2;
sbit btn_d = P0^3;

sbit l0 = P2^0;
sbit l1 = P2^1;
sbit l2 = P2^2;
sbit l3 = P2^3;
sbit l4 = P2^4;
sbit l5 = P2^5;
sbit l6 = P2^6;
sbit l7 = P2^7;

void delay(unsigned int t) {
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 500; j++);
}

void main() {
    P1 = 0;
    l0 = l1 = l2 = l3 = l4 = l5 = l6 = l7 = 0;

    while (1) {
        if (btn_a) {
            clock_rot();
        }
        if (btn_b) {
            anti_rot();
        }
        if (btn_c) {
            wave_patt();
        }
        if (btn_d) {
            random_patt();
        }
    }
}

void clock_rot() {
    P1 = 0;
    while (1) {
        l0 = 1;
        delay(100);
        l0 = 0;
        l1 = 1;
        delay(100);
        l1 = 0;
        l2 = 1;
        delay(100);
        l2 = 0;
        l3 = 1;
        delay(100);
        l3 = 0;
        l4 = 1;
        delay(100);
        l4 = 0;
        l5 = 1;
        delay(100);
        l5 = 0;
        l6 = 1;
        delay(100);
        l6 = 0;
        l7 = 1;
        delay(100);
        l7 = 0;
        delay(100);

        if (btn_a == 0) {
            break;
        }
    }
}

void anti_rot() {
    P1 = 0;
    while (1) {
        l0 = 1;
        delay(100);
        l0 = 0;
        l7 = 1;
        delay(100);
        l7 = 0;
        l6 = 1;
        delay(100);
        l6 = 0;
        l5 = 1;
        delay(100);
        l5 = 0;
        l4 = 1;
        delay(100);
        l4 = 0;
        l3 = 1;
        delay(100);
        l3 = 0;
        l2 = 1;
        delay(100);
        l2 = 0;
        l1 = 1;
        delay(100);
        l1 = 0;
        delay(100);

        if (btn_b == 0) {
            break;
        }
    }
}

void wave_patt() {
    P1 = 0;
    while (1) {
        l2 = l7 = 1;
        delay(100);
        l2 = l7 = 0;
        delay(100);
       l2 = l7 = l3 = l6 = 1;
        delay(100);
        l2 = l7  = l3 = l6 = 0;
        delay(100);
        l0 = l1 = l2 = l7  = l3 = l6 = 1;
        delay(100);
        l0 = l1 = l2 = l7  = l3 = l6= 0;
        delay(100);
        l4 = l5 = l6 = l3 = l2 = l1=l7=l0 = 1;
        delay(100);
        l4 = l5 = l6 = l3 = l2 = l1=l7=l0 = 0;
        delay(100);

        if (btn_c == 0) {
            break;
        }
    }
}

void random_patt() {
    while (1) {
        int k = rand() % 3;
        if (k == 0) {
            clock_rot();
        } else if (k == 1) {
            anti_rot();
        } else {
            wave_patt();
        }

        if (btn_d == 0) {
            break;
        }
    }
}

		