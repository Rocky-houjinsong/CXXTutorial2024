#include "GameMap.hxx".  // #include "../include/GameMap.hxx"
#include "Player.hxx"
#include <utility>

Player::Player(int x, int y, char _id):id(_id){
    if (gameMapPtr == nullptr){
        throw "gameMapPtr is nullptr at Player::Player";
    }
    gameMapPtr ->Modify(x, y, id);
}

void Player::MoveTo(int direction){
    if (gameMapPtr == nullptr){
        throw "gameMapPtr is nullptr at Player::MoveTo";
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    std::pair<int, int> pos = GetPos();
    gameMapPtr->Modify(pos.first, pos.second, '.');
    gameMapPtr->Modify(pos.first + dx[direction], pos.second + dy[direction], id);
    
}

std::pair<int, int> Player::GetPos(){
    if (gameMapPtr == nullptr){
        throw "gameMapPtr is nullptr at Player::GetPos";
    }

    for (int i = 0; i < gameMapPtr->sizeX; i++){
        for (int j = 0; j < gameMapPtr->sizeY; j++){
            if (gameMapPtr->mat[i][j] ==  id){
                return std::make_pair(i, j);
            }
        }
    }
    
    // 此处可添加 默认 异常返回值
}