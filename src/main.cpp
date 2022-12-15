#include <Arduino.h>

static const uint8_t led = LED_BUILTIN_TX;

void setup(void) {
    Serial.begin(115200);
    pinMode(led, OUTPUT);
}

static const uint8_t PLUS = 1;
static const uint8_t MIN = 2;
static const uint8_t LOS = 0;

uint8_t pinmodes[] = {
    PLUS, MIN, LOS,
    MIN, PLUS, LOS,
    PLUS, LOS, MIN,
    MIN, LOS, PLUS,
    LOS, PLUS, MIN,
    LOS, MIN, PLUS    
};

uint8_t modes[] = {INPUT, OUTPUT, OUTPUT};
uint8_t power[] = {LOW, HIGH, LOW};

void charlieplex(uint8_t led) {
    static const uint8_t led_a = 9;
    static const uint8_t led_b = 10;
    static const uint8_t led_c = 11;

    pinMode(led_a, modes[pinmodes[led * 3]]);
    pinMode(led_b, modes[pinmodes[led * 3 + 1]]);
    pinMode(led_c, modes[pinmodes[led * 3 + 2]]);

    digitalWrite(led_a, power[pinmodes[led * 3]]);
    digitalWrite(led_b, power[pinmodes[led * 3 + 1]]);
    digitalWrite(led_c, power[pinmodes[led * 3 + 2]]);

}

void loop(void) {

    for (uint8_t l=0; l<6; l++) {
        charlieplex(l);
    }
    delay(500);
}
