#include "Bat.h"

Bat::Bat() :Hazard("Bat") {
}

const string Bat::get_war_msg()const {
    string temp = "Bat is near";
    return temp;
}

const string Bat::get_attack_msg()const {
    string temp = "Bat is laughing";
    return temp;
}

const string Bat::get_clash_msg()const {
    string temp = "A Bat will move you";
    return temp;
}




