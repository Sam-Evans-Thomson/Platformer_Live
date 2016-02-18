/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virvra.cpp
 * Author: sam
 * 
 * Created on 16 February 2016, 4:29 PM
 */

#include "Virvra.h"

Virvra::Virvra() {
}

Virvra::Virvra(const Virvra& orig) {
}

Virvra::~Virvra() {
}

void Virvra::init() {
    statOptions[0] = STAT_RESIST;
    statOptions[1] = STAT_HEALTH;
    statOptions[2] = STAT_STAMINA;
    statOptions[3] = STAT_NONE;
    
    happiness       = 0;
    storedFavour    = 0;
    
    // initalise graphic.
    // initialise text.
    
    updateValues();
}

void Virvra::applyStartEffects() {
    STAT->damagePoison  += 10.0;
    STAT->poisonRes     += 10.0;
}

void Virvra::applyBribeEffects() {
    STAT->favour += STAT->wealth;
    STAT->wealth = 0;
}

void Virvra::applyPunishment() {
    STAT->currCamp = STAT->lastCamp;
    // can never rejoin;
}

void Virvra::updateValues() {
    nextLevelCost = 10 * (12 + 2*STAT->level) * (10+STAT->level); 
    // 1 -> 1,540
    // 5 -> 3,300
    // 20 -> 15,600
    // 50 -> 67,200
    
    nextItemCost = 2000 + 8100*numItemsTaken;
    nextPercCost = 3200 + 7700*numPercsTaken;
}

Item* Virvra::getItem() {

}

Perc* Virvra::getPerc() {

}

void Virvra::levelStat(stat_choices stat) {
    switch (stat) {
        case STAT_RESIST    : STAT->curseRes     += 2;
                              STAT->poisonRes    += 2;  break;
        case STAT_HEALTH    : STAT->healthMax    += 20; break;
        case STAT_STAMINA   : STAT->staminaMax   += 20; break;
    }
}

void Virvra::renderSpecifics() {

}
