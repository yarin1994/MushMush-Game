#pragma once

#include "Hazard.h"

class Bat : public Hazard {
public:
    Bat();
    virtual const string get_war_msg()const;
    virtual const string get_attack_msg()const;
    virtual const string get_clash_msg()const;


};
