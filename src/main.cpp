#include "Game.hpp"
#include "Game_over.hpp"
#include "mainMenu.hpp"
#include "mapCreator.hpp"

int main() {
  int state = 3;
  while (true) {
    mainMenu menu;
    while (menu.isRunning()) {
      menu.Update();
      menu.Render();
    }
    if (menu.getNextWindow() == 2) {
      mapCreator MapCreator;
      while (MapCreator.isRunning()) {
        MapCreator.Update();
        MapCreator.Render();
      }

    } else if (menu.getNextWindow() == 1) {
      Game game(&state);
      while (game.running()) {
        game.update();
        game.render();
      }
      if (state == 1 || state == 2) {
        GameOver gameOver(&state);

        while (gameOver.running()) {
          gameOver.update();
          gameOver.render();
        }
      }
      if (state == 1 || state == 3) break;
    } else if (menu.getNextWindow() == 0) {
      break;
    }
  }

  return 0;
}