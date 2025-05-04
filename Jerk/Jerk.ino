// Jerk chaotic circuit //

#include "SSD1306.h"

#define WIDTH   128
#define HEIGHT  64
#define BUZZ    8
#define RLED    9
#define GLED    10
#define BLED    3

OLED oled(WIDTH, HEIGHT);

    float a = 0.00000001f;
    float b = 0.026f;
    
    float x = 0.1f;
    float y = 0.1f;
    float z = 0.1f;

    float dt = 0.01f; 


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

    a = 0.00000001f + (0.00000002f * val);

    oled.clearBuffer();

    for (int i = 0; i < 1000; i++) {

        float nx = x;
        float ny = y;
        float nz = z;

        x = nx + dt * (ny);
        y = ny + dt * (nz);
        z = nz + dt * (-nz - nx - a * (expf(ny / b) - 1.0f));

        int ax = 88 + (44 * x);
        int ay = 40 + (28 * y);

        if (ax == 64) digitalWrite(BUZZ, HIGH);
        else digitalWrite(BUZZ, LOW);

        if (ax == 64) digitalWrite(RLED, LOW);
        else digitalWrite(RLED, HIGH);

        oled.drawPixel(ax, ay);

    }

    oled.displayBuffer();

}