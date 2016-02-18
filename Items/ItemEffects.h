/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ItemEffects.h
 * Author: sam
 *
 * Created on 18 February 2016, 7:53 AM
 */

#ifndef ITEMEFFECTS_H
#define ITEMEFFECTS_H

#include <math.h>
#include <stdlib.h>

class StatsComp;

class ItemEffects {
public:
    ItemEffects();
    ItemEffects(const ItemEffects& orig);
    virtual ~ItemEffects();
    
    void applyEffect(StatsComp* holder, StatsComp* target, int i, float amount);
private:

};

#endif /* ITEMEFFECTS_H */

