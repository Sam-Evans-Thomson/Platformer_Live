/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Timer.cpp
 * Author: sam
 * 
 * Created on 1 February 2016, 1:34 PM
 */

#include "Timer.h"

Timer::Timer() {
}

Timer::Timer(const Timer& orig) {
}

Timer::~Timer() {
}

void Timer::start() { startTime = clock(); }
void Timer::refresh() { startTime = clock(); }

unsigned long Timer::getMillis() {
    return ((unsigned long)clock()-startTime)/ (CLOCKS_PER_SEC/1000);
}

unsigned long Timer::getSeconds() {
    return ((unsigned long)clock()-startTime)/ (CLOCKS_PER_SEC);
}

unsigned long Timer::getMinutes() {
    return ((unsigned long)clock()-startTime)/ (60000*CLOCKS_PER_SEC);
}


