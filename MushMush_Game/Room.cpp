#include "Room.h"

Room::Room(int tunnel1, int tunnel2, int tunnel3)
{
    _tunnels[0] = tunnel1;
    _tunnels[1] = tunnel2;
    _tunnels[2] = tunnel3;
    _hazard = nullptr;
}


int Room::getTunnel1()const
{
    return _tunnels[0];
}

int Room::getTunnel2()const
{
    return _tunnels[1];
}

int Room::getTunnel3()const
{
    return _tunnels[2];
}

std::string Room::roomHazard() const
{
    string str = "";

    if (roomIsEmpty() == true)
        return str;
    else {
        str = _hazard->get_war_msg();
        return str;
    }
}

bool Room::roomIsEmpty() const
{
    if (_hazard == nullptr)
        return true;
    return false;
}

bool Room::attackInRoom(std::string& message) const
{
    if (isSealed == true)
    {
        message = "You just shot yourself";
        return true;
    }
    if (typeid(*this->_hazard) != typeid(Bat) && typeid(*this->_hazard) != typeid(Pit) && typeid(*this->_hazard) != typeid(MushMush)) {
        message = "";
        return false;
    }
    else {
        message = _hazard->get_attack_msg();
        return true;
    }
}

bool Room::clashInRoom(std::string& msg) const
{
    if (typeid(*_hazard) == typeid(Bat) || typeid(*_hazard) == typeid(Pit) || typeid(*_hazard) == typeid(MushMush))
    {

        msg = _hazard->get_clash_msg();
        return true;
    }

    else {
        msg = "";
        return false;
    }


}

bool Room::isMushMushHere() const
{
    if (_hazard != nullptr) {
        if (typeid(*_hazard) == typeid(MushMush))
            return true;
    }

    return false;
}

void Room::set_hazard(const std::string& eventName)
{

    if (eventName == "Bat")
        _hazard = new Bat;

    if (eventName == "Pit")
        _hazard = new Pit;

    if (eventName == "MushMush")
        _hazard = new MushMush;

}

const Hazard* Room::getHazard() const
{
    return _hazard;
}
bool Room::getSealed() {
    return isSealed;
}