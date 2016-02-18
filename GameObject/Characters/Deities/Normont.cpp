/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Normont.cpp
 * Author: sam
 * 
 * Created on 16 February 2016, 3:10 PM
 */

#include "Normont.h"

Normont::Normont() {
}

Normont::Normont(const Normont& orig) {
}

Normont::~Normont() {
}

void Normont::init() {
    statOptions[0] = STAT_POWER;
    statOptions[1] = STAT_CONTROL;
    statOptions[2] = STAT_HEALTH;
    statOptions[3] = STAT_STAMINA;
    
    happiness       = 0;
    storedFavour    = 0;
    
    // initalise graphic.
    // initialise text.
    
    updateValues();
}

void Normont::applyStartEffects() {
    STAT->expMult = 1.2;
}

void Normont::applyBribeEffects() {
    STAT->power = (int)(1.10*STAT->power);
}

void Normont::applyPunishment() {
    STAT->expMult = 0.8;
}

void Normont::updateValues() {
    nextLevelCost = 10 * (10 + 2*STAT->level) * (10+STAT->level); 
    // 1 -> 1,320
    // 5 -> 3,000
    // 20 -> 15,000
    // 50 -> 66,000
    
    nextItemCost = 2000 + 8000*numItemsTaken;
    nextPercCost = 3200 + 7600*numPercsTaken;
}

Item* Normont::getItem() {

}

Perc* Normont::getPerc() {

}

void Normont::levelStat(stat_choices stat) {
    switch (stat) {
        case STAT_POWER     : STAT->power        += 2;  break;
        case STAT_CONTROL   : STAT->control      += 2;  break;
        case STAT_HEALTH    : STAT->healthMax    += 20; break;
        case STAT_STAMINA   : STAT->staminaMax   += 20; break;
    }
}

void Normont::renderSpecifics() {

}
