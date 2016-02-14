/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResourceManager.h
 * Author: sam
 *
 * Created on 11 February 2016, 3:31 PM
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#define NUM_BACKGROUND_X 10
#define NUM_BACKGROUND_Y 10

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class Graphic;

class ResourceManager {
public:
    ResourceManager();
    ResourceManager(const ResourceManager& orig);
    virtual ~ResourceManager();
    
    void init();
    
    Graphic* background;
    std::vector<Graphic*> platforms;
    Graphic* running;
    
    Graphic* column;
    Graphic* stamina;
    Graphic* health;
    
    
private:

    
};

#endif /* RESOURCEMANAGER_H */

