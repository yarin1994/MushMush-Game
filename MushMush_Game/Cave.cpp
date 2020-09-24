#include "Cave.h"

Cave::Cave(const int* const sealedRooms, int size)
{
    _Cave[0] = new RegularRoom(2, 18, 19);
    _Cave[1] = new RegularRoom(5, 17, 18);
    _Cave[2] = new RegularRoom(0, 4, 17);
    _Cave[3] = new RegularRoom(7, 16, 19);
    _Cave[4] = new RegularRoom(2, 6, 15);
    _Cave[5] = new RegularRoom(1, 9, 14);
    _Cave[6] = new RegularRoom(1, 9, 14);
    _Cave[7] = new RegularRoom(3, 11, 12);
    _Cave[8] = new RegularRoom(6, 10, 11);
    _Cave[9] = new RegularRoom(5, 10, 13);
    _Cave[10] = new RegularRoom(8, 9, 12);
    _Cave[11] = new RegularRoom(7, 8, 15);
    _Cave[12] = new RegularRoom(7, 10, 14);
    _Cave[13] = new RegularRoom(6, 9, 17);
    _Cave[14] = new RegularRoom(5, 12, 16);
    _Cave[15] = new RegularRoom(4, 11, 19);
    _Cave[16] = new RegularRoom(3, 14, 18);
    _Cave[17] = new RegularRoom(1, 2, 13);
    _Cave[18] = new RegularRoom(0, 1, 16);
    _Cave[19] = new RegularRoom(0, 3, 15);

    for (int i = 0; i < size; i++)
    {
        int temp1, temp2, temp3, in;
        in = sealedRooms[i];

        temp1 = _Cave[in]->getTunnel1();
        temp2 = _Cave[in]->getTunnel2();
        temp3 = _Cave[in]->getTunnel3();
        delete _Cave[in];
        _Cave[in] = new SealedRoom(temp1, temp2, temp3);
    }

    _player_idx = -1;
    Alive = true;
    isMushMushAlive=true;

}

Cave::~Cave()
{
    for (int i = 0; i < 20; i++)
    {
        delete _Cave[i];
    }
}

void Cave::movePlayer(int idx) {
    if (idx == _Cave[_player_idx]->getTunnel1() || idx == _Cave[_player_idx]->getTunnel2() || idx == _Cave[_player_idx]->getTunnel3())
    {
        _player_idx = idx;
    }
    else throw  "Invalid Index Exception";
}


int Cave::findMushMush(void) const
{
    int i;
    for (i = 0; i < 20; i++)
    {
        if (_Cave[i]->isMushMushHere() == true)
        {
            return i;
        }
    }
    throw "MushMush Not Found Exception";
}


void Cave::plotHazard(int idx, const std::string& eventName)
{

    if (idx < 0 || idx>19 || _Cave[idx]->roomIsEmpty() == false)
        throw "Invalid Index Exception";
    if (eventName != "Bat" && eventName != "Pit" && eventName != "MushMush")
        throw "Invalid Hazard Exception";
    _Cave[idx]->set_hazard(eventName);
}


void Cave::plotPlayerIdx(int idx)
{
    if (idx < 0 || idx > 19)
        throw "Invalid Index Exception";
    else {
        if (_Cave[idx]->roomHazard() != "")
            throw "Invalid Index Exception";
        else _player_idx = idx;
    }
}

const Room* Cave::getRoomAtIndex(int index) const
{
    if (index < 0 || index >19)
        throw "Invalid Index Exception";

    return _Cave[index];
}


void Cave::hazardNearPlayer(std::string* hazards) const
{
    int room = this->_player_idx;
    hazards[0] = _Cave[_Cave[room]->getTunnel1()]->roomHazard();
    hazards[1] = _Cave[_Cave[room]->getTunnel2()]->roomHazard();
    hazards[2] = _Cave[_Cave[room]->getTunnel3()]->roomHazard();

}

std::string Cave::playerAttack(int idx)
{
    //CHECKS IF THE IDX IS LEAGAL
    if (_Cave[_player_idx]->getTunnel1() != idx && _Cave[_player_idx]->getTunnel2() != idx && _Cave[_player_idx]->getTunnel3() != idx)
    {
        throw "Invalid Index Exception";
    }
    else {
        string msg = "";
        int mush_idx = findMushMush();
        _Cave[idx]->attackInRoom(msg);

        //CHECKS IF THE HAZARD IS MUSHMUSH
        if (typeid(*(_Cave[idx]->getHazard())) == typeid(MushMush))
        {
            isMushMushAlive=false;
            return msg;
        }

        //CHECKS IF THE TARGET IS SEALED ROOM
        if (_Cave[idx]->getSealed())
        {
            Alive = false;
            return msg;
        }
        //MOVING MUSHMUSH INTO ANONTHER ROOM
        if(Alive){
            if (_Cave[_Cave[mush_idx]->getTunnel1()]->roomIsEmpty()) {
                _Cave[_Cave[mush_idx]->getTunnel1()]->set_hazard("MushMush");
                _Cave[mush_idx]->set_hazard("");
            }

            if (_Cave[_Cave[mush_idx]->getTunnel2()]->roomIsEmpty()) {
                _Cave[_Cave[mush_idx]->getTunnel2()]->set_hazard("MushMush");
                _Cave[mush_idx]->set_hazard("");
            }

            if (_Cave[_Cave[mush_idx]->getTunnel3()]->roomIsEmpty()) {
                _Cave[_Cave[mush_idx]->getTunnel3()]->set_hazard("MushMush");
                _Cave[mush_idx]->set_hazard("");
            }
        }
        return msg;
    }

}
string Cave::playerClash(int idx) {
    string clash_msg;
    bool BatClash = false;
    string msg = "";
    if (idx >= 0 && idx<=19)
    {
        if (BatClash != _Cave[idx]->clashInRoom(clash_msg))
        {
            _Cave[_player_idx]->set_hazard(msg);
            _player_idx = idx;
            clash_msg = playerClash(_Cave[_player_idx]->getTunnel1()); //recursive function
            return clash_msg;
        }
        else
        {
            const Hazard* hazard;
            hazard= _Cave[_player_idx]->getHazard();
            if (hazard != nullptr)
                Alive = true;
            return clash_msg;
        }
    }
    else {
        throw "Invalid Index Exception";
    }
}


bool Cave::gameOver() const
{
    if ((Alive == false)||(Alive==true && isMushMushAlive==false))return true;
    return false;
}

