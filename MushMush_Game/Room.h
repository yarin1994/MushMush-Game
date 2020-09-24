#pragma once

#include "Hazard.h"
#include "Bat.h"
#include "Pit.h"
#include "MushMush.h"
#include <string>
#include <typeinfo>
using namespace std;

class Hazard;

#pragma pack(push, 1)
class Room
{
public:
    Room(int tunnel1, int tunnel2, int tunnel3);
    virtual ~Room(){};
    bool attackInRoom(std::string& message) const;
    int getTunnel1() const;
    int getTunnel2() const;
    int getTunnel3() const;
    std::string roomHazard() const;
    const Hazard* getHazard() const;
    void set_hazard(const std::string& eventName);
    bool roomIsEmpty() const;
    bool isMushMushHere() const;
    bool clashInRoom(std::string& msg) const;
    bool getSealed();

protected:
    const Hazard* _hazard;
    bool isSealed = false;

private:
    int _tunnels[3];

};


#pragma pack(pop)
