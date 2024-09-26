#include <ncurses.h>
#include "../../models/SnakeCore/inc/SnakeGameModel.h"
#include "frontend.h"

using namespace s21;
SnakeGameModel::GameControl get_signal(int user_input) {
    SnakeGameModel::GameControl rc = SnakeGameModel::NOSIG;
    if (user_input == KEY_UP)
        rc = SnakeGameModel::MOVE_UP;
    else if (user_input == KEY_DOWN)
        rc = SnakeGameModel::MOVE_DOWN;
    else if (user_input == KEY_LEFT)
        rc = SnakeGameModel::MOVE_LEFT;
    else if (user_input == KEY_RIGHT)
        rc = SnakeGameModel::MOVE_RIGHT;
    else if (user_input == 27)
        rc = SnakeGameModel::STOP_GAME;
    else if (user_input == 10)
        rc = SnakeGameModel::STAR_GAME;
    else if (user_input == ERR)
        rc = SnakeGameModel::NOSIG;
    else if (user_input == 'p')
        rc = SnakeGameModel::PAUSE_GAME;
    return rc;
}

void game_loop(SnakeGameModel* gameModel) {
    bool break_flag = TRUE;
    while (break_flag) {
        if (gameModel->getState() == s21::SnakeGameModel::GAMEOVER || gameModel->getState() == s21::SnakeGameModel::EXIT_STATE)
            break_flag = FALSE;
        gameModel->stateMachine();
        gameModel->setGameControl(get_signal(getch()));
        PrintGameField(gameModel);
    }
}

void game_end(SnakeGameModel game_data) {
    BaseBoardModel boardModel = game_data.getGameBoard();
    SnakeModel snakeModel = game_data.getSnakeModel();
    for (auto it = snakeModel.begin(); it != snakeModel.end(); ++it) {
        int x = (*it).x, y = (*it).y;
        if (x >= 0 && x < boardModel.getWidth() && y >= 0 && y < boardModel.getHeight())
            printf("%c ",  '#');
        else printf("%c ",  '.');
    }

    printf("\nGame over!\n");
    printf("\nScore: %d\n", game_data.getScore());
    printf("\nBest Score: %d\n", game_data.getBestScore());
}

void ncursesMode() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(200);
}
int main(void) {
    SnakeGameModel game_data;
    ncursesMode();
    game_loop(&game_data);
    game_end(game_data);
    endwin();
    return 0;
}