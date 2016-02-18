/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Walabon.cpp
 * Author: sam
 * 
 * Created on 16 February 2016, 4:40 PM
 */

#include "Walabon.h"

Walabon::Walabon() {
}

Walabon::Walabon(const Walabon& orig) {
}

Walabon::~Walabon() {
}

void Walabon::init() {
    statOptions[0] = STAT_HEALTH;
    statOptions[1] = STAT_CONTROL;
    statOptions[2] = STAT_NONE;
    statOptions[3] = STAT_NONE;
    
    happiness       = 0;
    storedFavour    = 0;
    
    // initalise graphic.
    // initialise text.
    
    updateValues();
}

void Walabon::applyStartEffects() {
    STAT->healthFoodMult = -0.1;
    STAT->healthOnHit = STAT->level;
    STAT->staminaRegen += 0.2;
}

void Walabon::applyBribeEffects() {
    STAT->healthMax *= 1.15;
}

void Walabon::applyPunishment() {
    STAT->foodPoisons = true;
}

void Walabon::updateValues() {
    nextLevelCost = 10 * (12 + 2*STAT->level) * (10+STAT->level); 
    // 1 -> 1,540
    // 5 -> 3,300
    // 20 -> 15,600
    // 50 -> 67,200
    
    nextItemCost = 2000 + 8100*numItemsTaken;
    nextPercCost = 3200 + 7700*numPercsTaken;
}

Item* Walabon::getItem() {

}

Perc* Walabon::getPerc() {

}

void Walabon::levelStat(stat_choices stat) {
    switch (stat) {
        case STAT_CONTROL   : STAT->control      += 2;  break;
        case STAT_HEALTH    : STAT->healthMax    += 30; break;
    }
    STAT->healthOnHit = STAT->level;
    STAT->staminaRegen += 0.05;
}

void Walabon::renderSpecifics() {

}
