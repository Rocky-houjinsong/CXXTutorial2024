#include <iostream>

#include "GameMap.hxx"
#include "Player.hxx"

int main() {
    gameMapPtr = new GameMap(8, 8);
    auto player =  Player(4, 4, '#');
    bool running = true;

    while (running) {
        std::cout << gameMapPtr << std::endl;
        char ch;

        scanf("%c%*c", &ch);

        switch (ch) {
            case 'w':
                player.MoveTo(3);
                break;
            case 'a':
                player.MoveTo(2);
                break;
            case 'd':
                player.MoveTo(0);
                break;
            case 's':
                player.MoveTo(1);
                break;
            default:
                running = false;
                break;
        }
    }
}
