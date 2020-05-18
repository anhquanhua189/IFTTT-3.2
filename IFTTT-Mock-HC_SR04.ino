// This #include statement was automatically added by the Particle IDE.
#include <HC_SR04.h>


double light = 0.0;

int triggerPin = D4;
int echoPin = D5;

HC_SR04 rangefinder = HC_SR04(triggerPin, echoPin);


void setup() {
    Particle.variable("light", &light, DOUBLE);
}

void loop() {
    light = rangefinder.getDistanceCM();
    
    if (light > 20)
    {
        Particle.publish("LightLevel", "hitting", PRIVATE);
    }
    
    if (light < 10)
    {
        Particle.publish("LightLevel", "not hitting", PRIVATE);
    }
    
    delay(600000);
}
