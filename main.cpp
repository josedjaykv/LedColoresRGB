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

void hexToRGB(const std::string& hex, float& red, float& green, float& blue) {
    std::istringstream iss(hex);
    iss >> std::hex >> red;
    iss >> std::hex >> green;
    iss >> std::hex >> blue;
}

int main()
{
    //Con pwmout usamos el peri
    PwmOut ledR(LED1);
    PwmOut ledG(LED2);
    PwmOut ledB(LED3);
    
    std::string hexColor;
    std::cout << "Enter a hexadecimal color: ";
    std::cin >> hexColor;

    float numR, numG, numB;
    hexToRGB(hexColor, numR, numG, numB);

    std::string hexNumber;
    std::cout << "Enter a hexadecimal number: ";
    std::cin >> hexNumber;


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