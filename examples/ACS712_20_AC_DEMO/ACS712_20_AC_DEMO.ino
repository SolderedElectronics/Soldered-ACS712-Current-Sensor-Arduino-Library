/**
 **************************************************
 *
 * @file        ACS712_20_AC_DEMO.ino
 * @brief       Example for measure AC current
 *              https://github.com/e-radionicacom/Soldered-ACS712-Current-Sensor-Arduino-Library
 *              
 *
 *
 *
 * @authors    Rob Tillaart
 * Modified by: Soldered for use with https://solde.red/333147
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
ACS712 ACS(A0, ACS712_20A);

void setup()
{
    // Initialise the serial port
    Serial.begin(115200);
    Serial.println(__FILE__);
    ACS.autoMidPoint();
}


void loop()
{
    // Read the current value
    int mA = ACS.mA_AC();
    Serial.println(mA);

    // See if any input on serial and reply
    if (Serial.available() > 0)
    {
        char c = Serial.read();

        if (c == '*')
            ACS.setmVperAmp(ACS.getmVperAmp() + 1);
        if (c == '/')
            ACS.setmVperAmp(ACS.getmVperAmp() - 1);
        Serial.print("mVperAmp:\t");
        Serial.println(ACS.getmVperAmp());

        if (c == '+')
            ACS.setFormFactor(ACS.getFormFactor() * 1.05);
        if (c == '-')
            ACS.setFormFactor(ACS.getFormFactor() / 1.05);
        Serial.print("formFactor:\t");
        Serial.println(ACS.getFormFactor());
    }
    delay(1000);
}


// -- END OF FILE --
