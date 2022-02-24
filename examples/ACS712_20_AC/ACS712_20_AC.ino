/**
 **************************************************
 *
 * @file        ACS712_20_AC.ino
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
