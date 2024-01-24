/*

  IBT.cpp - Library for ease use of IBT2 BTS7960 motor driver.
  Created by Al Mahir Ahmed, October 6th 2023.
  Released into the public domain.
  Contact: mahirgored@gmail.com; Github: Vulcan758

*/

#include "Arduino.h"
#include "CytronDriverMD30C.h"

CytronDriverMD30C::CytronDriverMD30C(int DIR_, int PWM_){
    PWM = PWM_;
    DIR = DIR_;

    pinMode(PWM, OUTPUT);
    pinMode(DIR, OUTPUT);

}

void CytronDriverMD30C::setSpeedLevel(int level){
    digitalWrite(PWM, HIGH);
    int val = map(constrain(abs(level), 0, 10), 0, 10, 0, 255);
    if (level < 0){
        digitalWrite(DIR, HIGH);
        
    }
    else{
        digitalWrite(DIR, LOW);
    }

    analogWrite(PWM, val);

}
// for now until you're done

void CytronDriverMD30C::setRawSpeed(int value){
    digitalWrite(PWM, HIGH);
    int val = constrain(abs(value), 0, 255);
    if (value < 0){
        digitalWrite(DIR, HIGH);
        
    }
    else{
        digitalWrite(DIR, LOW);
    }

    analogWrite(PWM, val);

}


void CytronDriverMD30C::stop_(){
    analogWrite(PWM, 0);
    digitalWrite(PWM, 0);
    //this->checkEnable(0);
}