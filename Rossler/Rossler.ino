// Rossler chaotic attractor //

#include "SSD1306.h"

#define WIDTH   128
#define HEIGHT  64
#define BUZZ    8
#define RLED    9
#define GLED    10
#define BLED    3

OLED oled(WIDTH, HEIGHT);

    float x = 0.1f;
    float y = 0.1f;
    float z = 0.1f;

    float dt = 0.02f;

    float a = 0.2f;
    float b = 0.2f;
    float c = 14.0f;

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

    int val = map(analogRead(A1), 0, 1023, 1000, 0);

    a = 0.2f - (0.0002f * val);

    oled.clearBuffer();

    for (int i = 0; i < 1000; i++) {

        float nx = x;
        float ny = y;
        float nz = z;
    
        x = nx + dt * (-ny - nz);
        y = ny + dt * (nx + a * ny);
        z = nz + dt * (b + nz * (nx - c));  

        int ax = 64 + (1*x);
        int ay = 32 + (1*y);
        int az = 32 + z;

        if (ax == 64) digitalWrite(BUZZ, HIGH);
        else digitalWrite(BUZZ, LOW);

        if (ax == 64) digitalWrite(RLED, LOW);
        else digitalWrite(RLED, HIGH);

        oled.drawPixel(ax, ay);

    }

    oled.displayBuffer();

}