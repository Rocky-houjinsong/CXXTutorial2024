#include "GameMap.hxx"

GameMap* gameMapPtr;

GameMap::GameMap(int _sizeX, int _sizeY) : sizeX(_sizeX), sizeY(_sizeY){
    for (int  i = 0; i < sizeX; i++){
        for (int j = 0; j < sizeY; j++){
            mat[i][j] = '.';
        }
    }
}

void GameMap::Modify(int x, int y, char ch){
    if (x < 0 || x >= sizeX) {
       throw "x out of bounds";
    }

    if (y < 0 || y >= sizeY){
       throw "y out of bounds";
    }
    mat[x][y] = ch;
    
}

std::ostream& operator<< (std::ostream& os, const GameMap* gameMapPtr){
    if (gameMapPtr == nullptr){
        throw "gammeMapPtr is nullptr at output";
    }

    for (int j = 0; j < ( 2 * gameMapPtr ->sizeY + 1 ); j++){
        os << "-";
    }
    
    os << std::endl;

    for (int i = 0; i < (gameMapPtr ->sizeX); i++){
        for (int j = 0; j < (gameMapPtr ->sizeY); j++){
            os << " " << gameMapPtr ->mat[i][j];
        }
        os << std::endl;
    }
    
    for (int j = 0; j <  (2 * gameMapPtr -> sizeY + 1); j++){
        os << "-";
    }
    
    return os;
}