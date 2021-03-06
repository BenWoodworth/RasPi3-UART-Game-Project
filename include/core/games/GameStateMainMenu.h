#ifndef GAMESTATEMAINMENU_H_
#define GAMESTATEMAINMENU_H_

#include "gameapi/GameState.h"
#include "games/snake/GameStateSnake.h"
#include "games/tic-tac-toe/GameStateTicTacToe.h"
#include "terminal/Key.h"

class GameStateMainMenu : public GameState {
private:
    uint8_t color;
    uint8_t ch;
    std::string label_1;
    std::string label_2;
    bool hasInput;
    uint8_t selectedState;
    GameManager* gameManager;
    GameState* selectedStateObject;
public:
    GameStateMainMenu() {
        color = Colors::fromRgb(0, 0, 0);
        ch = '0';
        label_1 = "Snake";
        label_2 = "Tic-Tac-Toe";
        hasInput = false;
        selectedState = 1;
        selectedStateObject = NULL;
    }

    void tick(GameManager* gameManager);

    void handleInput(Key key);
};

#endif
