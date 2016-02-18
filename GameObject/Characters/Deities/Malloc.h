/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Malloc.h
 * Author: sam
 *
 * Created on 16 February 2016, 3:57 PM
 */

#ifndef MALLOC_H
#define MALLOC_H

#include "../Deity.h"

class Malloc : public Deity {
public:
    Malloc();
    Malloc(const Malloc& orig);
    virtual ~Malloc();
    
    void init() override;
    void applyStartEffects() override;
    void applyBribeEffects() override;
    void applyPunishment() override;
    
    void updateValues() override;
    
    Item* getItem() override;
    Perc* getPerc() override;
    
    void levelStat(stat_choices stat) override;
    
    void renderSpecifics() override;
    
private:

};

#endif /* MALLOC_H */

