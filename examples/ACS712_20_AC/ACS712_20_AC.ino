//
//    FILE: ACS712_20_AC.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//    DATE: 2020-03-18
//
// Modified by: Soldered for use with https://solde.red/333073


#include "ACS712-SOLDERED.h"

// Declare a ACS712 object
ACS712 ACS(A0, ACS712_5A);


void setup()
{
    // Initialize the serial port
    Serial.begin(115200);
    Serial.println(__FILE__);

    // Determine midpoint of the ACS712 and noise
    ACS.autoMidPoint();
    Serial.print("MidPoint: ");
    Serial.print(ACS.getMidPoint());
    Serial.print(". Noise mV: ");
    Serial.println(ACS.getNoisemV());
}


void loop()
{
    // Read current and print to serial
    int mA = ACS.mA_AC();
    Serial.print("mA: ");
    Serial.print(mA);
    Serial.print(". Form factor: ");
    Serial.println(ACS.getFormFactor());

    delay(1000);
}


// -- END OF FILE --
