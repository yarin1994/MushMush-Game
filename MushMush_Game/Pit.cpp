#include "Pit.h"

Pit::Pit() :Hazard("Pit") {
}

const string Pit::get_war_msg()const {
    string temp = "Pit is near";
    return temp;
}

const string Pit::get_attack_msg()const {
    string temp = "Pit is whistling";
    return temp;
}

const string Pit::get_clash_msg()const {
    string temp = "You fell into a Pit";
    return temp;
}




