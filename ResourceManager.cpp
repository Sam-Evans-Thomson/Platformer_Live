/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResourceManager.cpp
 * Author: sam
 * 
 * Created on 11 February 2016, 3:31 PM
 */

#include "ResourceManager.h"
#include "Graphics/Graphic.h"

ResourceManager::ResourceManager() {
    init();
}

ResourceManager::ResourceManager(const ResourceManager& orig) {
}

ResourceManager::~ResourceManager() {
    delete [] background;
}

void ResourceManager::init() {
    Graphic* gr = new Graphic(1,"bgd_0_0_");
    gr->loadTextures();
    for (int i = 0; i < NUM_BACKGROUND_X; i++) {
        for (int j = 0; j < NUM_BACKGROUND_X; j++) {
            background[i][j] = gr;
        }
    }
}


