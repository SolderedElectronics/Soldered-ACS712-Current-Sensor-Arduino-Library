/**
 **************************************************
 *
 * @file        ACS712_30_DC_DEMO.ino
 * @brief       Example for measure AC current
 *              https://github.com/e-radionicacom/Soldered-ACS712-Current-Sensor-Arduino-Library
 *              
 *
 *
 *
 * @authors    Rob Tillaart
 * Modified by: Soldered for use with https://solde.red/333073
 *
 ***************************************************/


//Connecting diagram
//Breakout      Arduino
//|-------------|
//OUT-----------A0
//GND-----------GND
//VCC-----------5V

#include "ACS712-SOLDERED.h"

// Declare a ACS712 object
ACS712 ACS(A0, ACS712_30A);

void setup()
{
    // Initialize the Serial port
    Serial.begin(115200);
    Serial.println(__FILE__);
    ACS.autoMidPoint();
}


void loop()
{
    // Read the current value
    int mA = ACS.mA_DC();
    Serial.println(mA);

    // Check if input on Serial and reply
    if (Serial.available() > 0)
    {
        char c = Serial.read();
        if (c == '+')
            ACS.incMidPoint();
        if (c == '-')
            ACS.decMidPoint();
        if (c == '0')
            ACS.setMidPoint(512);
        Serial.println(ACS.getMidPoint());

        if (c == '*')
            ACS.setmVperAmp(ACS.getmVperAmp() * 1.05);
        if (c == '/')
            ACS.setmVperAmp(ACS.getmVperAmp() / 1.05);
        Serial.println(ACS.getmVperAmp());
    }
    delay(1000);
}


// -- END OF FILE --
