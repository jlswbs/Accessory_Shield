// Chua chaotic oscillator //

#include "SSD1306.h"

#define WIDTH   128
#define HEIGHT  64
#define BUZZ    8
#define RLED    9
#define GLED    10
#define BLED    3

OLED oled(WIDTH, HEIGHT);

    float x = 0.5f;
    float y = 0.25f;
    float z = 0.125f;

    float dt = 0.014f;

    float alpha = 15.6f;
    float beta = 28.58f;
    float a = -1.14286f;
    float b = -0.714286f;

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

    alpha = 15.6f - (0.005f * val);

    oled.clearBuffer();

    for (int i = 0; i < 1000; i++) {

        float nx = x;
        float ny = y;
        float nz = z;
    
        float h = (b * x) + (0.5f * (a - b) * (fabs(x + 1.0f) - fabs(x - 1.0f)));
    
        x = nx + dt * (alpha * (ny - nx - h));
        y = ny + dt * (nx - ny + nz);
        z = nz + dt * (-beta * ny);

        int ax = 64 + (26*x);
        int ay = 32 + (56*y);
        int az = 32 + (8*z);

        if (ax == 64) digitalWrite(BUZZ, HIGH);
        else digitalWrite(BUZZ, LOW);

        if (ax == 64) digitalWrite(RLED, LOW);
        else digitalWrite(RLED, HIGH);

        oled.drawPixel(ax, ay);

    }

    oled.displayBuffer();

}