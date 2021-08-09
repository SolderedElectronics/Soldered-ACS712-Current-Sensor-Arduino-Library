//
//    FILE: ACS712_20_AC_DEMO.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo to set midpoint and mVperAmpere for class.
//    DATE: 2020-03-18
//
// Modified by: Soldered for use with https://solde.red/[_sku]

#include "ACS712-SOLDERED.h"

// Declare a ACS712 object
ACS712 ACS(A0, ACS712_5A);

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
