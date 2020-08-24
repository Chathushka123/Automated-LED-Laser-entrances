#include <Wire.h>

#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor1(13, 12);  // 13 - trigger, 12 - echo 
int led1 = 8;

bool arr [4] = { LOW,LOW,LOW,LOW };

void setup () {
    Serial.begin(9600);
    pinMode(led1,OUTPUT);
    digitalWrite(led1,HIGH);
}

void loop () {
    float distance = distanceSensor1.measureDistanceCm();
    bool val = test(distance);
    digitalWrite(led1,val);
    Serial.println(distance);
    delay(50);
}

bool test(int dist){
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[3];
    if(dist < 180 && dist > 5){
        arr[3] = HIGH;
    }else{
        arr[3] = LOW;
    }

    if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==arr[3]){
      return arr[3];
    }
}
