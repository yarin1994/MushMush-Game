#pragma once

#include <string>
#include "Room.h"

#include "Hazard.h"
#include "Bat.h"
#include "MushMush.h"
#include "Pit.h"
#include "Cave.h"
#include "RegularRoom.h"
#include "SealedRoom.h"
#include <iostream>


class Room;
class Cave
{
public:
    Cave(const int* const sealedRooms, int size);
    ~Cave();
    const Room* getRoomAtIndex(int index) const;
    void plotHazard(int idx, const std::string& eventName);
    void plotPlayerIdx(int idx);
    int findMushMush(void) const;
    void movePlayer(int idx);
    std::string playerAttack(int idx);
    std::string playerClash(int idx);
    bool gameOver() const;

    void hazardNearPlayer(std::string* hazards) const;

private:
    Room* _Cave[20];
    int _player_idx;
    bool Alive;
    bool isMushMushAlive;

};
#pragma once
