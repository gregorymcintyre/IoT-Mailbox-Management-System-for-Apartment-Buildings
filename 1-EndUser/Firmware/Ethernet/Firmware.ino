
// Include Libraries
#include "Arduino.h"
#include "Button.h"


// Pin Definitions
#define ETHERNETMODULE_PIN_CS	53
#define ETHERNETMODULE_PIN_INT	2
#define MICROSWITCH_1_PIN_COM	3
#define MICROSWITCH_2_PIN_COM	4
#define MICROSWITCH_3_PIN_COM	5
#define MICROSWITCH_4_PIN_COM	6



// Global variables and defines

// object initialization
Button microSwitch_1(MICROSWITCH_1_PIN_COM);
Button microSwitch_2(MICROSWITCH_2_PIN_COM);
Button microSwitch_3(MICROSWITCH_3_PIN_COM);
Button microSwitch_4(MICROSWITCH_4_PIN_COM);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    microSwitch_1.init();
    microSwitch_2.init();
    microSwitch_3.init();
    microSwitch_4.init();
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1')
    {
    // Disclaimer: The Ethernet LAN Network Module - ENC28J60 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '2') {
    // Micro Switch #1 - Test Code
    //Read microSwitch state. 
    //if microSwitch is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also microSwitch_1.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool microSwitch_1Val = microSwitch_1.read();
    Serial.print(F("Val: ")); Serial.println(microSwitch_1Val);
    }
    else if(menuOption == '3') {
    // Micro Switch #2 - Test Code
    //Read microSwitch state. 
    //if microSwitch is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also microSwitch_2.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool microSwitch_2Val = microSwitch_2.read();
    Serial.print(F("Val: ")); Serial.println(microSwitch_2Val);
    }
    else if(menuOption == '4') {
    // Micro Switch #3 - Test Code
    //Read microSwitch state. 
    //if microSwitch is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also microSwitch_3.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool microSwitch_3Val = microSwitch_3.read();
    Serial.print(F("Val: ")); Serial.println(microSwitch_3Val);
    }
    else if(menuOption == '5') {
    // Micro Switch #4 - Test Code
    //Read microSwitch state. 
    //if microSwitch is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also microSwitch_4.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool microSwitch_4Val = microSwitch_4.read();
    Serial.print(F("Val: ")); Serial.println(microSwitch_4Val);
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Ethernet LAN Network Module - ENC28J60"));
    Serial.println(F("(2) Micro Switch #1"));
    Serial.println(F("(3) Micro Switch #2"));
    Serial.println(F("(4) Micro Switch #3"));
    Serial.println(F("(5) Micro Switch #4"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing Ethernet LAN Network Module - ENC28J60 - note that this component doesn't have a test code"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing Micro Switch #1"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing Micro Switch #2"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing Micro Switch #3"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing Micro Switch #4"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/