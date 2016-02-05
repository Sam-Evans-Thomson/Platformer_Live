/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateComponent.h
 * Author: sam
 *
 * Created on 2 February 2016, 2:20 PM
 */


#ifndef STATECOMPONENT_H
#define STATECOMPONENT_H


class RunningState;
class PrimaryState;
class SecondaryState;

class StateComponent {
public:
    StateComponent();
    StateComponent(const StateComponent& orig);
    virtual ~StateComponent();
    
    void init();
    
    virtual void update(double timeDelta);
    
    void changePrimaryState(PrimaryState* primeState);
    void changeSecondaryState(SecondaryState* secondState);
    
    PrimaryState* primary;
    SecondaryState* secondary;

    // Primary States;
      RunningState*        running;
//    JumpingState        jumping;
//    DodgeState          dodge;
//    DropAttackState     dropAttack;
//    StunState           stun;
//    ClimbingState       climbing;
//    GrabbingState       grabbing;
//    ActivateState       activate;
//    SwimmingState       swimming;
//    
//    // Secondary States
//    NullState           null;
//    EatingState         eating;
//    Melee1State         melee1;
//    Melee2State         melee2;
//    RangeState          range;
//    BlockState          block;
//    

private:
protected:
    
};

#endif /* STATECOMPONENT_H */

