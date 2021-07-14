#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int button = 13;
boolean running = false;
unsigned long startTime;

void setup() {
    lcd.begin(16, 2);
    pinMode(button, INPUT);
}

void loop() {
    if (digitalRead(button) == HIGH) {
        running = true;
        startTime = millis();
        // wait for button to be released
        while (digitalRead(button) == HIGH) {
            delay(100);
        }
    }
    delay(10);
    if (running) {
        lcd.setCursor(0, 0);
        lcd.print((millis() - startTime) / 1000.);
    }
}