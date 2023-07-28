// ModelRailwayLEDController Written By Ben Forster July 2023

// Define the zones
// Zone 1 = Ponteland Station Lights (Red)
// Zone 2 = Forston Station Lights (Grey) + Shop Lights
// Zone 3 = Central Station Lights
// Zone 4 = Goods Yard & Factory Lights
// Zone 5 = Goods Yard Shops & Waterfall Park House Lights
// Zone 6 = Station Road Shops & Houses Cinema

// first define the libraries
#include "FastLed.h"
#include "ArduinoTimer.h"

// then define the input pins
const int zone1OnPin = 54;
const int zone2OnPin = 55;
const int zone3OnPin = 56;
const int zone4OnPin = 57;
const int zone5OnPin = 58;
const int zone6OnPin = 59;
const int dimLightsOnPin = 60;

bool zone1On = false;
bool zone2On = false;
bool zone3On = false;
bool zone4On = false;
bool zone5On = false;
bool zone6On = false;
bool dimLightsOn = false;

// then set up the relays pins to turn on for each zone
const int zone1RelayPins[1] = { 11 };
const int zone2RelayPins[1] = { 10 };
const int zone3RelayPins[1] = { 9 };
const int zone4RelayPins[1] = { 8 };
const int zone5RelayPins[1] = { 7 };
const int zone6RelayPins[1] = { 6 };

// then set up the output pins for the FastLed Led Strips
const int zone1LEDPins[1] = { 53 };
const int zone2LEDPins[1] = { 52 };
const int zone3LEDPins[1] = { 51 };
const int zone4LEDPins[1] = { 50 };
const int zone5LEDPins[1] = { 49 };
const int zone6LEDPins[3] = { 48, 47, 46};

// then set up the FastLed controllers for each zone
// Zone 1

// Zone 2

// Zone 3

// Zone 4

// Zone 5

// Zone 6
CRGB zone6LEDArrayTerraceHouses[2][26];
CRGB zone6LEDArrayCinema[10];

#define WARMCOLOURDIM 0x773300
#define WARMCOLOURBRIGHT 0xFF6600

FastLED.addLeds<WS2182B, zone6LEDPins[0], GRB>(zone6LEDArrayTerraceHouses[0], 26);
FastLED.addLeds<WS2182B, zone6LEDPins[1], GRB>(zone6LEDArrayTerraceHouses[1], 26);
FastLED.addLeds<WS2182B, zone6LEDPins[2], GRB>(zone6LEDArrayCinema, 10);


// then define the light changing charecteristics
const int zone6LEDArrayDownstairsConstantOnIndex[5] = [8, 9, 10, 11, 12];

// then define the timer settings
bool zone6DownstairsTimerStarted = false;
bool zone6UpstairsTimerStarted = false;

ArduinoTimer zone6DownstairsTimer;
ArduinoTimer zone6UpstairsTimer;

long zone6DownstairsRandomTimeSeconds = 10;
long zone6UpstairsRandomTimeSeconds = 10;


void setup() {
    // start the serial
    Serial.begin(9600);

    // then go through each zones switch input pin and set it as input pullup
    pinMode(zone1OnPin, INPUT_PULLUP);
    pinMode(zone2OnPin, INPUT_PULLUP);
    pinMode(zone3OnPin, INPUT_PULLUP);
    pinMode(zone4OnPin, INPUT_PULLUP);
    pinMode(zone5OnPin, INPUT_PULLUP);
    pinMode(zone6OnPin, INPUT_PULLUP);
    pinMode(dimLightsOnPin, INPUT_PULLUP);

    // then go through the relay pins and set them to output
    for(int i = 0; i < sizeof(zone1RelayPins); i++) {
        pinMode(zone1RelayPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone2RelayPins); i++) {
        pinMode(zone2RelayPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone3RelayPins); i++) {
        pinMode(zone3RelayPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone4RelayPins); i++) {
        pinMode(zone4RelayPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone5RelayPins); i++) {
        pinMode(zone5RelayPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone6RelayPins); i++) {
        pinMode(zone6RelayPins[i], OUTPUT);
    }

    // then go through the FastLED pins and set them to output
    for(int i = 0; i < sizeof(zone1LEDPins); i++) {
        pinMode(zone1LEDPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone2LEDPins); i++) {
        pinMode(zone2LEDPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone3LEDPins); i++) {
        pinMode(zone3LEDPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone4LEDPins); i++) {
        pinMode(zone4LEDPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone5LEDPins); i++) {
        pinMode(zone5LEDPins[i], OUTPUT);
    }
    for(int i = 0; i < sizeof(zone6LEDPins); i++) {
        pinMode(zone6LEDPins[i], OUTPUT);
    }
}

void loop() {
    for(var i = 0; i < 2; i++) {
        // then check if any switches have been changed
        if(digitalRead(zone1OnPin) == LOW && zone1On == false) {
            // then set zone 1 on
            zone1On = true;
        }
        else {
            // then set zone 1 off
            zone1On = false;
        }
        if(digitalRead(zone2OnPin) == LOW && zone2On == false) {
            // then set zone 2 on
            zone2On = true;
        }
        else {
            // then set zone 2 off
            zone2On = false;
        }
        if(digitalRead(zone3OnPin) == LOW && zone3On == false) {
            // then set zone 3 on
            zone3On = true;
        }
        else {
            // then set zone 3 off
            zone3On = false;
        }
        if(digitalRead(zone4OnPin) == LOW && zone4On == false) {
            // then set zone 4 on
            zone4On = true;
        }
        else {
            // then set zone 4 off
            zone4On = false;
        }
        if(digitalRead(zone5OnPin) == LOW && zone5On == false) {
            // then set zone 5 on
            zone5On = true;
        }
        else {
            // then set zone 5 off
            zone5On = false;
        }
        if(digitalRead(zone6OnPin) == LOW && zone6On == false) {
            // then set zone 6 on
            zone6On = true;
        }
        else {
            // then set zone 6 off
            zone6On = false;
        }
        // then delay by 10ms to debounce any switches
        if(digitalRead(dimLightsOnPin) == LOW && dimLightsOn == false) {
            // then set the dimLightsOn to true
            dimLightsOn = true;
        }
        else {
            // then set the dimLightsOn to false
            dimLightsOn = false;
        }
        delay(10);
    }

    // then check if zone 1 is on
    if(zone1On == true) {
        // then turn any relays that belong to zone 1 on
        for(var i = 0; i < sizeof(zone1RelayPins); i++) {
            // then put the pin on
            digitalWrite(zone1RelayPins[i], HIGH);
        }
    }
    else {
        // then turn any relays that belong to zone 1 off
        for(var i = 0; i < sizeof(zone1RelayPins); i++) {
            // then put the pin off
            digitalWrite(zone1RelayPins[i], LOW);
        }
    }
    // then check if zone 2 is on
    if(zone2On == true) {
        // then turn any relays that belong to zone 2 on
        for(var i = 0; i < sizeof(zone2RelayPins); i++) {
            // then put the pin on
            digitalWrite(zone2RelayPins[i], HIGH);
        }
    }
    else {
        // then turn any relays that belong to zone 2 off
        for(var i = 0; i < sizeof(zone2RelayPins); i++) {
            // then put the pin off
            digitalWrite(zone2RelayPins[i], LOW);
        }
    } 
    // then check if zone 3 is on
    if(zone3On == true) {
        // then turn any relays that belong to zone 3 on
        for(var i = 0; i < sizeof(zone3RelayPins); i++) {
            // then put the pin on
            digitalWrite(zone3RelayPins[i], HIGH);
        }
    }
    else {
        // then turn any relays that belong to zone 3 off
        for(var i = 0; i < sizeof(zone3RelayPins); i++) {
            // then put the pin off
            digitalWrite(zone3RelayPins[i], LOW);
        }
    } 
    // then check if zone 4 is on
    if(zone4On == true) {
        // then turn any relays that belong to zone 4 on
        for(var i = 0; i < sizeof(zone4RelayPins); i++) {
            // then put the pin on
            digitalWrite(zone4RelayPins[i], HIGH);
        }
    }
    else {
        // then turn any relays that belong to zone 4 off
        for(var i = 0; i < sizeof(zone4RelayPins); i++) {
            // then put the pin off
            digitalWrite(zone4RelayPins[i], LOW);
        }
    }
     // then check if zone 5 is on
    if(zone5On == true) {
        // then turn any relays that belong to zone 5 on
        for(var i = 0; i < sizeof(zone5RelayPins); i++) {
            // then put the pin on
            digitalWrite(zone5RelayPins[i], HIGH);
        }
    }
    else {
        // then turn any relays that belong to zone 5 off
        for(var i = 0; i < sizeof(zone5RelayPins); i++) {
            // then put the pin off
            digitalWrite(zone5RelayPins[i], LOW);
        }
    }
    // then check if zone 6 is on
    if(zone6On == true) {
        // then turn any relays that belong to zone 6 on
        for(var i = 0; i < sizeof(zone6RelayPins); i++) {
            // then put the pin on
            digitalWrite(zone6RelayPins[i], HIGH);
        }

        // Then do the LED strips in this zone
        // First do the downstairs lights on the block of houses
        // We are going to pick a random time to wait for and then we are going to pick a random number of lights that is less than half of the total lights
        // Then we are going to put them on or of and then repeat
        
        // Downstairs
        // 1 - check if the timer has not been started
        if(zone6DownstairsTimerStarted == false) {
            // then start the timer
            zone6DownstairsTimer.Reset();
            zone6DownstairsTimerStarted = true;
            // then choose a random time to wait between 15 and 60 seconds
            zone6DownstairsRandomTimeSeconds = random(15, 61);

        }
        // 2 - then check if the required time has passed
        if(zone6DownstairsTimer.TimePassed_Seconds(zone6DownstairsRandomTimeSeconds)) {
            // then choose a random number of lights to turn off
            for(int i = 0; i < (int)random(0,8); i++) {
                // then pick another random number between 0 and the maximum number of lights
                int random = random(0, sizeof(zone6LEDArrayTerraceHouses[0]));
                // then put the light off
                zone6LEDArrayTerraceHouses[0][random] = CRGB(0x000000);
            }
            // then choose a random number of lights to turn on
            for(int i = 0; i < (int)random(0,8); i++) {
                // then pick another random number between 0 and the maximum number of lights
                int random = random(0, sizeof(zone6LEDArrayTerraceHouses[0]));
                // then put the light on
                if(dimLightsOn == true) {
                    zone6LEDArrayTerraceHouses[0][random] = CRGB(WARMCOLOURDIM);
                }
                else {
                    zone6LEDArrayTerraceHouses[0][random] = CRGB(WARMCOLOURBRIGHT);
                }
            }
            FastLED.show();
        }

        // Upstairs
        // 1 - check if the timer has not been started
        if(zone6UpstairsTimerStarted == false) {
            // then start the timer
            zone6UpstairsTimer.Reset();
            zone6UpstairsTimerStarted = true;
            // then choose a random time to wait between 15 and 60 seconds
            zone6UpstairsRandomTimeSeconds = random(15, 61);

        }
        // 2 - then check if the required time has passed
        if(zone6UpstairsTimer.TimePassed_Seconds(zone6UpstairsRandomTimeSeconds)) {
            // then choose a random number of lights to turn off
            for(int i = 0; i < (int)random(0,8); i++) {
                // then pick another random number between 0 and the maximum number of lights
                int random = random(0, sizeof(zone6LEDArrayTerraceHouses[1]));
                // then put the light off
                zone6LEDArrayTerraceHouses[1][random] = CRGB(0x000000);
            }
            // then choose a random number of lights to turn on
            for(int i = 0; i < (int)random(0,8); i++) {
                // then pick another random number between 0 and the maximum number of lights
                int random = random(0, sizeof(zone6LEDArrayTerraceHouses[1]));
                // then put the light on
                if(dimLightsOn == true) {
                    zone6LEDArrayTerraceHouses[1][random] = CRGB(WARMCOLOURDIM);
                }
                else {
                    zone6LEDArrayTerraceHouses[1][random] = CRGB(WARMCOLOURBRIGHT);
                }
            }
            FastLED.show();
        }


    }
    else {
        // then turn any relays that belong to zone 6 off
        for(var i = 0; i < sizeof(zone6RelayPins); i++) {
            // then put the pin off
            digitalWrite(zone6RelayPins[i], LOW);
        }
    } 

}