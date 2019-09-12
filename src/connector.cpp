#include <Wire.h>
#include <HardwareSerial.h>
#include <Arduino.h>
#include "connector.h"


connector::connector() {
    Wire.begin();
    Serial.begin(9600);
}


void connector::send_data(String x, char id) {
    Wire.beginTransmission(id); // transmit to device #8
    Wire.println(x);
    Wire.endTransmission();    // stop transmitting
}

int connector::resive_data() {
    byte buf[2];
    Wire.requestFrom(8,10);
    int i = 0;
    while (Wire.available()) {
        buf[i] = Wire.read();
        ++i;
        if(i==2) {
            int int32 = (int) buf[1] << 8 | (int) buf[0];
            Serial.println(int32);
            i = 0;
            Serial.println("changed");
        }
    }


}

void connector::slush_Wire() {
    Wire.endTransmission();
    Wire.flush();
}


