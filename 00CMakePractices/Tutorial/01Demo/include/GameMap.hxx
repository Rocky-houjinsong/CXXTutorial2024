#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

#include <iostream>
#include <ostream>
#include <utility>

const int MAXSIZE = 101;

class GameMap{
    public:
        int sizeX, sizeY;
        char mat[MAXSIZE] [MAXSIZE];

        GameMap(int _sizeX, int _sizeY);

        void Modify(int x, int y, char ch);

        friend std::ostream& operator<<(std::ostream& os,
                                        const GameMap* gameMapPtr);
};

extern GameMap* gameMapPtr;



#endif  //_GAME_MAP_H_