/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Malloc.cpp
 * Author: sam
 * 
 * Created on 16 February 2016, 3:57 PM
 */

#include "Malloc.h"

Malloc::Malloc() {
}

Malloc::Malloc(const Malloc& orig) {
}

Malloc::~Malloc() {
}

void Malloc::init() {
    statOptions[0] = STAT_POWER;
    statOptions[1] = STAT_CONTROL;
    statOptions[2] = STAT_STAMINA;
    statOptions[3] = STAT_NONE;
    
    happiness       = 0;
    storedFavour    = 0;
    
    // initalise graphic.
    // initialise text.
    
    updateValues();
}

void Malloc::applyStartEffects() {
    STAT->damageBasePower   = (int)(1.1*STAT->damageBasePower);
    STAT->damageBaseControl = (int)(1.1*STAT->damageBaseControl);
}

void Malloc::applyBribeEffects() {
    // Give player Malloc's Blessing Item
}

void Malloc::applyPunishment() {
    STAT->healthMax = STAT->healthMax/2;
}

void Malloc::updateValues() {
    nextLevelCost = 8 * (10 + 3*STAT->level) * (10+STAT->level); 
    // 1 -> 1,144
    // 5 -> 3,000
    // 20 -> 16,800
    // 50 -> 76,800
    
    nextItemCost = 2500 + 8500*numItemsTaken;
    nextPercCost = 3700 + 8100*numPercsTaken;
}

Item* Malloc::getItem() {

}

Perc* Malloc::getPerc() {

}

void Malloc::levelStat(stat_choices stat) {
    switch (stat) {
        case STAT_POWER     : STAT->power        += 3;  break;
        case STAT_CONTROL   : STAT->control      += 3;  break;
        case STAT_STAMINA   : STAT->staminaMax   += 20; break;
    }
}

void Malloc::renderSpecifics() {

}
