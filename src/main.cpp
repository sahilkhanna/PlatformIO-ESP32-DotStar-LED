#include <Arduino.h>
#include <dotstar.h>

DotStar leds(6,DOTSTAR_RGB);
uint8_t r,g,b=0;
int count=0;
uint8_t nextColor[3];
uint8_t currentColor[3];
void setup() {
    // put your setup code here, to run once:
    
    Serial.begin(115200);
    while(!Serial);
    leds.begin();
    leds.print();
        nextColor[0] = random(255);
        nextColor[1] = random(255);
        nextColor[2] = random(255);
    currentColor[0]=nextColor[0];
    currentColor[1]=nextColor[1];
    currentColor[2]=nextColor[2];
}

void loop() {
    // put your main code here, to run repeatedly:
    leds.setColor(0,currentColor[0],currentColor[1],currentColor[2]);
    leds.setColor(1,currentColor[0],currentColor[1],currentColor[2]);
    leds.setColor(2,currentColor[0],currentColor[1],currentColor[2]);
    leds.setColor(3,currentColor[0],currentColor[1],currentColor[2]);
    leds.setColor(4,currentColor[0],currentColor[1],currentColor[2]);
    leds.setColor(5,currentColor[0],currentColor[1],currentColor[2]);
    
    count++;
    if (count>10000){
        nextColor[0] = random(255);
        nextColor[1] = random(255);
        nextColor[2] = random(255);
        count=0;
    }

    if(currentColor[0]<nextColor[0])
        currentColor[0]++;
    else if(currentColor[0]>nextColor[0])
        currentColor[0]--;

    if(currentColor[1]<nextColor[1])
        currentColor[1]++;
    else if(currentColor[1]>nextColor[1])
        currentColor[1]--;

     if(currentColor[2]<nextColor[2])
        currentColor[2]++;
    else if(currentColor[2]>nextColor[2])
        currentColor[2]--;

    if(currentColor[0]==nextColor[0] && currentColor[1]==nextColor[1] && currentColor[2]==nextColor[2]){
        count=0;
        
        nextColor[0] = random(255);
        nextColor[1] = random(255);
        nextColor[2] = random(255);
    }

    leds.print();
    delay(1);
}