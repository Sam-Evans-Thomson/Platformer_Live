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

class Player;

class PrimaryState;
class SecondaryState;

// PRIMARY STATES
class RunningState;
class JumpingState;
class DodgeState;
class DropAttackState;
class StunState;
class ClimbingState;
class GrabbingState;
class ActivateState;

// SECONDARY STATES
// These can be concurrent with the Primary state but not with each other.
class NullState;
class EatingState;
class Melee1State;
class Melee2State;
class RangeState;
class BlockState;




class PrimaryState{
public:
    PrimaryState();
    PrimaryState(const PrimaryState& orig);
    virtual ~PrimaryState();
    
    void setInputComponent(InputComponent* ic);
    void setStateComponent(StateComponent* sc);
    
    virtual void update(double timeDelta);
    
    virtual void pressA();
    virtual void pressB();
    virtual void pressX();
    virtual void pressY();
    virtual void pressSel();
    virtual void pressStrt();
    virtual void pressLB();
    virtual void pressRB();

private:
    
protected:
    StateComponent* stateComp;
    InputComponent* inputComp;
};

class SecondaryState{
public:
    
    SecondaryState();
    SecondaryState(const SecondaryState& orig);
    virtual ~SecondaryState();
    
    void setInputComponent(InputComponent* ic);
    void setStateComponent(StateComponent* sc);
    
    virtual void update(double timeDelta);
    
private:
      
protected:
    StateComponent* stateComp;
    InputComponent* inputComp;
};


/*
 *  Running and standing including slopes.
 */
class RunningState : public PrimaryState {
public:
    RunningState();
    RunningState(const RunningState& orig);
    virtual ~RunningState();
    
    void update(double timeDelta);
    void inputs();
private: 
};


/*
 *  Jumping, falling and flapping.
 */
class JumpingState : public PrimaryState {
public:
    JumpingState();
    void update(double timeDelta);
private: 
};




/*
 *
 */
class BlockState : public PrimaryState {
public:
    BlockState();
    void update(double timeDelta);
private:     
};


/*
 *
 */
class DodgeState : public PrimaryState {
public:
    DodgeState();
    void update(double timeDelta);
private:     
};


/*
 *
 */
class DropAttackState : public PrimaryState {
public:
    DropAttackState();
    void update(double timeDelta);
private:     
};


/*
 *
 */
class StunState : public PrimaryState {
public:
    StunState();
    void update(double timeDelta);
private:     
};


/*
 *
 */
class ClimbingState : public PrimaryState {
public:
    ClimbingState();
    void update(double timeDelta);
private:     
};


/*
 *
 */
class GrabbingState : public PrimaryState {
public:
    GrabbingState();
    void update(double timeDelta);
private:     
};


/*
 *
 */
class ActivateState : public PrimaryState {
public:
    ActivateState();
    void update(double timeDelta);
private:     
};



/*
 *  when no Secondary State is needed.
 */
class NullState : public SecondaryState {
public:
    NullState();
    void update(double timeDelta);
private:   
};

/*
 *  Melee 1 and Melee 2 [does not include 
 */
class Melee1State : public SecondaryState {
public:
    Melee1State();
    void update(double timeDelta);
private:     
};


/*
 *  Melee 1 and Melee 2 [does not include 
 */
class Melee2State : public SecondaryState {
public:
    Melee2State();
    void update(double timeDelta);
private:     
};


/*
 *
 */
class RangeState : public SecondaryState {
public:
    RangeState();
    void update(double timeDelta);
private:     
};


/*
 *  includes all consumables.
 */
class EatingState : public SecondaryState {
public:
    EatingState();
    void update(double timeDelta);
private:     
};

class StateComponent {
public:
    StateComponent(Player* p);
    StateComponent(const StateComponent& orig);
    virtual ~StateComponent();
    
    void init();
    
    virtual void update(double timeDelta);
    
    void jump();
    void dodge();
    void useItem();
    void activate();
    void block();
    void melee1();
    void melee2();
    void range();
    void flap();
    void runLeft();
    void runRight();

    
    Player* p;
    
private:
    
    InputComponent* inputs;
    PrimaryState* primary;
    SecondaryState* secondary;
    
    // Primary States;
    RunningState        running;
    JumpingState        jumping;
    DodgeState          dodge;
    DropAttackState     dropAttack;
    StunState           stun;
    ClimbingState       climbing;
    GrabbingState       grabbing;
    ActivateState       activate;
    
    // Secondary States
    NullState           null;
    EatingState         eating;
    Melee1State         melee1;
    Melee2State         melee2;
    RangeState          range;
    BlockState          block;
    
protected:
    
};

#endif /* STATECOMPONENT_H */

