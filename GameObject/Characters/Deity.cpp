/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deity.cpp
 * Author: sam
 * 
 * Created on 16 February 2016, 2:23 PM
 */

#include "Deity.h"
#include "../../Graphics/Graphic.h"


Deity::Deity() {
}

Deity::Deity(const Deity& orig) {
}

Deity::~Deity() {
}

void Deity::init() {

}

void Deity::applyStartEffects() {

}

void Deity::applyBribeEffects() {

}

void Deity::applyPunishment() {

}

void Deity::updateValues() {

}

void Deity::storeFavour(int fav) { storedFavour += fav; }

void Deity::levelStat(stat_choices stat) {

}

Item* Deity::getItem() {

}

Perc* Deity::getPerc() {

}

void Deity::render() {
    //Do stuff here.
    
    renderSpecifics();
}

void Deity::changeHappiness(int hap) { happiness += hap; }

void Deity::renderSpecifics() {

}


