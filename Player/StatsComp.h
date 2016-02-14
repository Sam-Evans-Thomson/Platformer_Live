/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatsComp.h
 * Author: sam
 *
 * Created on 12 February 2016, 3:56 PM
 */

#ifndef STATSCOMP_H
#define STATSCOMP_H

#include "../Utilities/Timer.h"
#include <math.h>

//#define STATS_PATH "statsPath.txt"
#define STAMINA_DELAY 1
#define POWER_DAMAGE_FACTOR 1.0
#define POWER_FLAP_FACTOR 0.5
#define CONTROL_DEFENSE_FACTOR 1.0

#define CONTROL_DAMAGE_FACTOR 1.0

enum deity {
    NORMONT,        // General Deity
    MALLOC,         // VIOLENT - Damage - power control stamina
    FRIIMA,         // FLYING - stamina power health
    VIRVRA,         // POISON/Secondaries
    WALABON,        // VAMPIRE  -Health/control
    NO_DEITY,       // nothing
    DEMON_DEITY,    // everythig is harder, gets harder as you level 
};

class StatsComp {
public:
    StatsComp();
    StatsComp(const StatsComp& orig);
    virtual ~StatsComp();
    
    void init();
    void loadStats();
    void refresh();
    
    void update();
    void updateLevelStats();
    void updateEquipStats();
    
    void incPower(int i);
    void incControl(int i);
    
    bool useStamina(float i);
    
    bool takeDamage(float i);
    bool takePhysDamage(float i);
    bool takePoisonDamage(float i);
    bool takeCurseDamage(float i);
    bool takeStaggerDamage(float i);
    
    void gainFavour(int i);
    
    
    
    /// values
    float stamina;
    float staminaMax;
    float staminaRegen;
    Timer* staminaTimer;
    
    float health;
    float healthMax;
    float healthRegen;
    
    float poison;             // poison build up
    float poisonRes;          // resistance to buildup
    float poisonMax;          // poisoned when poison exceeds this.
    
    float curse;              // curse build up
    float curseRes;           // resistance to buildup
    float curseMax;           // cursed when curse exceeds this.
    
    float stagger;            // stagger buildup    
    float staggerRes;         // resistance to stagger
    float staggerMax;         // staggered when stagger exceeds this.
    
    float defenseBase;        // defense based on level and stats.
    float defense;            // defense with equipment factored.

    float damageBasePower;    // damage based on Power.
    float damageBaseControl;  // damage based on Control;
    float damageMelee1;       // damage with equipment factored.
    float damageMelee2;       // damage with equipment factored.
    float damageRange;        // damage with equipment factored.
    
    float distanceRange;      // How far range attacks go.

    float flapPower;          // Force of flapping;
    
    /// stats
    int level;
    
    /* POWER:   Power weapons do more damage.
     *          Range attacks go further.
     *          Wing flaps are more powerful.
     * 
     * CONTROL  Everything uses less stamina.
     *          Range Attacks do more damage.
     *          
     */
    int power;
    int control;
    
    int favour;
    int wealth;
    
    deity alignment;
    
    
private:

};

#endif /* STATSCOMP_H */

