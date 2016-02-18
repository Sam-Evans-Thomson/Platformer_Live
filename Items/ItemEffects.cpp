/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemEffects.cpp
 * Author: sam
 * 
 * Created on 18 February 2016, 7:53 AM
 */

#include "ItemEffects.h"
#include "../Player/StatsComp.h"

ItemEffects::ItemEffects() {
}

ItemEffects::ItemEffects(const ItemEffects& orig) {
}

ItemEffects::~ItemEffects() {
}

// applying a negative effect number will negate the positive one.
void ItemEffects::applyEffect(StatsComp* holder, StatsComp* target, int i, float amount) {
    
    int value = abs(i);
    int sign = i/value;
    
    
    switch (value) {
        
        // 0 - 100 stat effects on target
        // 100 - 200 effects on the target 
        // 200 - 300 effects on the holder
        
        // 0 nothing.
        case 0 : 
        {

            break;
        }
        
        // increase stamina
        case 1 :
        {
            target->staminaMax += sign*amount;
            break;
        }
        
        // increase stamina Regen
        case 2 :
        {
            target->staminaRegen += sign*amount;
            break;
        }
        
        // increase health
        case 3 :
        {
            target->healthMax += sign*amount;
            break;
        }
        
        // increase health Regen
        case 4 :
        {
            target->healthRegen += sign*amount;
            break;
        }
        
        // increase healing from food
        case 5 :
        {
            target->healthFoodMult += sign*amount;
            break;
        }
        
        // increase health on hit
        case 6 :
        {
            target->healthOnHit += sign*amount;
            break;
        }
        
        // set whether food poisons you
        case 7 :
        {
            if (sign > 0)target->foodPoisons = true;
            else target->foodPoisons = false;
            break;
        }
        
        // increase poison Res
        case 8 :
        {
            target->poisonRes += sign*amount;
            break;
        }
        
        // increase curse resist
        case 9 :
        {
            target->curseRes += sign*amount;
            break;
        }
        
        // increase stagger Res
        case 10 :
        {
            target->staggerRes += sign*amount;
            break;
        }
        
        // increase defense
        case 11 :
        {
            target->defenseBase += sign*amount;
            break;
        }
        
        // increase damage
        case 12 :
        {
            target->damageBasePower += sign*amount;
            target->damageBaseControl += sign*amount;
            break;
        }
        
        // increase poison damage
        case 13 :
        {
            target->damagePoison += sign*amount;
            break;
        }
                
        // increase throw distane
        case 14 :
        {
            target->distanceRange += sign*amount;
            break;
        }
        
        // increase flap Power damage
        case 15 :
        {
            target->flapPower += sign*amount;
            break;
        }
              
        // increase experience multiplier
        case 16 :
        {
            target->expMult += sign*amount;
            break;
        }
                
        // increase power
        case 17 :
        {
            target->power += sign*amount;
            break;
        }
              
        // increase control
        case 18 :
        {
            target->control += sign*amount;
            break;
        }
        
        // Target takes extra damage
        case 101 :
        {
            target->takeDamage(sign*amount);
            break;
        }
        
        // Target takes extra phys damage
        case 102 :
        {
            target->takePhysDamage(sign*amount);
            break;
        }
    }
}
