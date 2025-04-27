// Lorenz chaotic attractor //

#include "SSD1306.h"

#define WIDTH   128
#define HEIGHT  64
#define BUZZ    8
#define RLED    9
#define GLED    10
#define BLED    3

OLED oled(WIDTH, HEIGHT);

    float s = 10.0f;
    float r = 28.0f;
    float b = 8.0f / 3.0f;

    float x = 1.0f;
    float y = 1.0f;
    float z = 1.0f;

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

    s = 10.0f + (0.042f * val);

    oled.clearBuffer();

    for (int i = 0; i < 1000; i++) {

        float nx = x;
        float ny = y;
        float nz = z;
    
        x = nx + dt * (s * (ny - nx));
        y = ny + dt * (nx * (r - nz) - ny);
        z = nz + dt * (nx * ny - b * nz);

        int ax = 64 + (3*x);
        int ay = 32 + y;
        int az = 64 - (8+z);

        if (ax == 64) digitalWrite(BUZZ, HIGH);
        else digitalWrite(BUZZ, LOW);

        if (ax == 64) digitalWrite(RLED, LOW);
        else digitalWrite(RLED, HIGH);

        oled.drawPixel(ax, az);

    }

    oled.displayBuffer();

}