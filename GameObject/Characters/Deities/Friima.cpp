/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Friima.cpp
 * Author: sam
 * 
 * Created on 16 February 2016, 4:11 PM
 */

#include "Friima.h"

Friima::Friima() {
}

Friima::Friima(const Friima& orig) {
}

Friima::~Friima() {
}

void Friima::init() {
    statOptions[0] = STAT_POWER;
    statOptions[1] = STAT_HEALTH;
    statOptions[2] = STAT_STAMINA;
    statOptions[3] = STAT_NONE;
    
    happiness       = 0;
    storedFavour    = 0;
    
    // initalise graphic.
    // initialise text.
    
    updateValues();
}

void Friima::applyStartEffects() {
    STAT->staminaRegen += 0.2;
    STAT->flapMult = 1.08;
    
    // Can spend gold as experience.
}

void Friima::applyBribeEffects() {
    STAT->wealth += 10000;
}

void Friima::applyPunishment() {
    STAT->flapPower *= 0.8;
}

void Friima::updateValues() {
    nextLevelCost = 10 * (12 + 2*STAT->level) * (10+STAT->level); 
    // 1 -> 1,540
    // 5 -> 3,300
    // 20 -> 15,600
    // 50 -> 67,200
    
    nextItemCost = 2000 + 8100*numItemsTaken;
    nextPercCost = 3200 + 7700*numPercsTaken;
}

Item* Friima::getItem() {

}
 
Perc* Friima::getPerc() {

}

void Friima::levelStat(stat_choices stat) {
    switch (stat) {
        case STAT_POWER     : STAT->power        += 3;  break;
        case STAT_HEALTH    : STAT->healthMax    += 20; break;
        case STAT_STAMINA   : STAT->staminaMax   += 25; break;
    }
}

void Friima::renderSpecifics() {

}
