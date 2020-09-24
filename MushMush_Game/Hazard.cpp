#include "Hazard.h"

Hazard::Hazard(const string& war_name)
{
    _name = war_name;
}

const string Hazard::getName()const
{
    return _name;
}