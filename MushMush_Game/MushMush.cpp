#include "MushMush.h"

MushMush::MushMush() :Hazard("MushMush") {
}

const string MushMush::get_war_msg()const {
    string temp = "MushMush is near";
    return temp;
}

const string MushMush::get_attack_msg()const {
    string temp = "You got MushMush";
    return temp;
}

const string MushMush::get_clash_msg()const {
    string temp = "MushMush got you";
    return temp;
}




