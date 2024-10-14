#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>

class Player {
    public:
        char id;

        Player(int x, int y, char _id);
        void MoveTo(int direction);
        std::pair<int, int> GetPos();
};

#endif //_PLAYER_H_