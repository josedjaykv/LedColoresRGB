/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
UnbufferedSerial pc(USBTX, USBRX,9600);
using namespace std;

int main()
{
    //Con pwmout usamos el peri
    PwmOut ledR(LED1);
    PwmOut ledG(LED2);
    PwmOut ledB(LED3);
    float numR, numG, numB;

    cout << "Ingresa el número para Red: \n";
    cin >> numR;

    cout << "Ingresa el número para Green: \n";
    cin >> numG;

    cout << "Ingresa el número para Blue: \n";
    cin >> numB;

    float valorR = 1-(numR/255);
    float valorG = 1-(numG/255);
    float valorB = 1-(numB/255);

    ledR.write(valorR);
    ledG.write(valorG);
    ledB.write(valorB);

    while (1) {
        // ThisThread::sleep_for(BLINKING_RATE);
        
    }
}