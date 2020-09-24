#include "SealedRoom.h"


SealedRoom::SealedRoom(int tunnel1, int tunnel2, int tunnel3) : Room(tunnel1, tunnel2, tunnel3) {
    isSealed = true;
}

SealedRoom::~SealedRoom() {}
