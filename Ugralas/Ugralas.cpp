#include "Window.h"

int main(void)
{
	srand((unsigned int)time(NULL));
	prg::GameWindow game_window;
	game_window.main_loop();
}