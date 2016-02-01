/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Timer.h
 * Author: sam
 *
 * Created on 1 February 2016, 1:34 PM
 */

#ifndef TIMER_H
#define TIMER_H

#include <time.h>

class Timer {
public:
    Timer();
    Timer(const Timer& orig);
    virtual ~Timer();
    
    void start();
    void refresh();
    
    unsigned long getMillis();
    unsigned long getSeconds();
    unsigned long getMinutes();

private:
    unsigned long startTime;
};

#endif /* TIMER_H */

