#pragma once
#include <string>

using namespace std;

class Hazard {
protected:
    string war_name;

public:
    Hazard(const string& war_name);
    const string getName()const;
    virtual const string get_war_msg()const = 0;
    virtual const string get_attack_msg()const = 0;
    virtual const string get_clash_msg()const = 0;

private:
    string _name;

};