// XOR fractal //

#include "SSD1306.h"

#define WIDTH   WIDTH_128
#define HEIGHT  HEIGHT_64
#define BUZZ    8
#define RLED    9
#define GLED    10
#define BLED    3

OLED oled(WIDTH_128, HEIGHT_64);

int tmp, cnt;


void setup() {

    pinMode(BUZZ, OUTPUT);
    pinMode(RLED, OUTPUT);
    pinMode(GLED, OUTPUT);
    pinMode(BLED, OUTPUT);

    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);

    oled.begin();
    oled.clearScr();

}

void loop(){

    oled.clearBuffer();

    for (int y = 0; y < HEIGHT; y++) {

        int val = analogRead(A1) >> 4;
        
        for (int x = 0; x < WIDTH; x++) { 

            tmp = ((x ^ (y + cnt)) % val) % 4;

            if (tmp == false) digitalWrite(BUZZ, HIGH);
            else digitalWrite(BUZZ, LOW);

            if (tmp == false) digitalWrite(RLED, LOW);
            else digitalWrite(RLED, HIGH);

            if (tmp == false) oled.drawPixel(x, y);

        }

    }

    oled.displayBuffer();

    cnt++;

}