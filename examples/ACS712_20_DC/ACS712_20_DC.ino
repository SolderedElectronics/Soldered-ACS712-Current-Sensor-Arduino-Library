/**
 **************************************************
 *
 * @file        ACS712_20_DC.ino
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
    // Print mA to Serial
    int mA = ACS.mA_DC();
    Serial.println(mA);

    delay(1000);
}


// -- END OF FILE --
