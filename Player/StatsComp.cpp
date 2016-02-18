/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatsComp.cpp
 * Author: sam
 * 
 * Created on 12 February 2016, 3:56 PM
 */

#include "StatsComp.h"
#include "Player.h"
#include "../GameObject/Characters/Deity.h"

extern Player player;

StatsComp::StatsComp() {
    init();
}

StatsComp::StatsComp(const StatsComp& orig) {
}

StatsComp::~StatsComp() {
}

void StatsComp::init() {
    
    staminaMax          = 300.0;
    staminaRegen        = 1.0;
    staminaTimer        = new Timer();
    
    healthMax           = 500.0;
    healthRegen         = 0.0;
    healthFoodMult      = 1.0;
    healthOnHit         = 0.0;
    foodPoisons         = false;
    
    poisonRes           = 1.0;
    poisonMax           = 100.0;
    isPoisoned          = false;
    
    curseRes            = 1.0;
    curseMax            = 1000;
    isCursed            = false;
    
    staggerRes          = 0.0;
    staggerMax          = 50.0;
    
    defenseBase         = 10.0;
    defense             = 10.0;
    
    damageBasePower     = 10.0;
    damageBaseControl   = 10.0;
    
    damagePoison        = 0.0;
    
    distanceRange       = 10.0;
    
    flapPower           = 50.0;
    flapMult            = 1.0;
    
    level               = 1;
    expMult             = 1.0;
    
    power               = 10;
    control             = 10;
    
    favour              = 0;
    wealth              = 0;
    
    alignment           = nullptr;
        
}

void StatsComp::loadStats() { }

void StatsComp::refresh() {
    stamina         = staminaMax;
    health          = healthMax;
    poison          = 0;
    curse           = 0;
    stagger         = 0;
    
}

void StatsComp::updateLevelStats() {
    damageBasePower     = POWER_DAMAGE_FACTOR      *sqrt(power);
    flapPower           = POWER_FLAP_FACTOR        *sqrt(power) * flapMult;   
    distanceRange       = POWER_DAMAGE_FACTOR      *sqrt(power);
    defenseBase         = CONTROL_DEFENSE_FACTOR   *sqrt(control);
    damageBaseControl   = CONTROL_DAMAGE_FACTOR    *sqrt(control);
    
    curseRes            = 0.1*level;
    poisonRes           = 0.1*level;

}

void StatsComp::update() {
    if (staminaTimer->getSeconds() > STAMINA_DELAY && stamina < staminaMax) {
        stamina += staminaRegen;
    }
    if (health <= healthMax) health += healthRegen;
    if (curse > 0) curse -= curseRes;
    if (poison > 0) poison -= poisonRes;
}

bool StatsComp::useStamina(float i) {
    if (stamina <= 0) return false;
    else { 
        float stm = i/control;
        staminaTimer->start();
        stamina -= stm; 
        return true;
    }
}

bool StatsComp::takeDamage(float i) {
    health -= i;
    if (health <= 0) return false;
    return true;
}

bool StatsComp::takePhysDamage(float i) {
    float dmg = i/defense;
    health -= dmg;
    if (health <= 0) {
        player.dies();
        return false;
    }
    return true;
}

bool StatsComp::takeCurseDamage(float i) {
    float crs = i/curseRes;
    curse += crs;
    if (curse >= curseMax) return false;
    return true;
}

bool StatsComp::takePoisonDamage(float i) {
    float psn = i/poisonRes;
    poison += psn;
    if (poison >= poisonMax) return false;
    return true;
}

bool StatsComp::takeStaggerDamage(float i) {
    float stgr = i/staggerRes;
    stagger += stgr;
    if (stagger >= staggerMax) return false;
    return true;
}

void StatsComp::gainFavour(int i) { favour += (int)(expMult*i);
}

void StatsComp::healFood(float i) {
    isPoisoned = foodPoisons;
    health += healthFoodMult*i;
    if (health > healthMax) health = healthMax;
}

void StatsComp::heal(int i) {
    health += i;
    if (health > healthMax) health = healthMax;
}
