/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.h
 * Author: sam
 *
 * Created on 17 February 2016, 9:18 AM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

class RangeWeapon;
class MeleeWeapon;
class Armour;
class Ring;
class Amulet;
class Food;
class Consumable;
class Key;
class QuestItem;
class Spell;
class CampItem;
class UpgradeItem;
class Gem;

class Inventory {
public:
    Inventory();
    Inventory(const Inventory& orig);
    virtual ~Inventory();
    
    void init();
    
    void render();
    
    std::vector<RangeWeapon*> rangeWeapons;
    std::vector<MeleeWeapon*> meleeWeapons;
    std::vector<Armour*> armour;
    std::vector<Ring*> rings;
    std::vector<Amulet*> amulets;
    
    std::vector<Food*> food;
    std::vector<Consumable*> consumables;
    
    std::vector<Key*> keys;
    std::vector<QuestItem*> questItems;
    
    std::vector<Spell*> spells;
    std::vector<CampItem*> campItems;
    
    std::vector<UpgradeItem*> upgradeItems;
    std::vector<Gem*> gems;
    
    
private:

};

#endif /* INVENTORY_H */

