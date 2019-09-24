#include <WatchDog_WCL.h>

SYSTEM_MODE(MANUAL);

WatchDog wd;

void setup() {
    pinMode(D7, INPUT);
    RGB.control(true);
    if  (System.resetReason() == RESET_REASON_WATCHDOG) {
        RGB.color(255,0,0);
        delay(CONCURRENT_WAIT_FOREVER);
    }  else {
        RGB.color(0,0,255);
    }
    wd.initialize(5000);
    wd.pet();
}

void loop() {
    if (digitalRead(D7) == LOW) {
        wd.pet();
    }
}