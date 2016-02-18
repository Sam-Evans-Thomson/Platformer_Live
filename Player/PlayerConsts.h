/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerConsts.h
 * Author: sam
 *
 * Created on 8 February 2016, 5:59 PM
 */

#ifndef PLAYERCONSTS_H
#define PLAYERCONSTS_H

#define BASE_GRAVITY 46
#define BASE_FRICTION 1

#define MAX_X_FORCE 500
#define MAX_Y_FORCE 2000
#define MAX_Y_FORCE_UP -600

#define PLAYER_RUN_SPEED 50.0

#define DODGE_STAMINA 500
#define PLAYER_DODGE_FORCE 35.0
#define DODGE_LENGTH 0.20
#define INVIN_START 0.10
#define INVIN_END 0.20

#define PLAYR_W 100
#define PLAYR_H 140

#define JUMP_COUNT_MAX 10
#define JUMP_FORCE 18

#define FLAP_COUNT_MAX 60
#define FLAP_FORCE 3

#define FALL_FORCE_STAGGER 1400

#define NO_RESTRICTION -1
#define FACING_L 0
#define FACING_R 1

///////FLAGS
#define FLAG_FALLING 0
#define FLAG_HITWILL 1
#define FLAG_ONGROUND 2

#endif /* PLAYERCONSTS_H */

