#pragma once
#include "Hazard.h"

class Pit : public Hazard {
public:
    Pit();
    virtual const string get_war_msg()const;
    virtual const string get_attack_msg()const;
    virtual const string get_clash_msg()const;

};
