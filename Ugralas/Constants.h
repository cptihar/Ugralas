#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

// Window \\

#define WINDOW_HEIGHT  600u
#define WINDOW_WIDTH   650u
#define WINDOW_FPS		60u
#define BLOCK_SIZE		50u


// Debug \\

#define DEBUG_STATE 1

#if DEBUG_STATE
	#include <iostream>
	
	#define E_LOG(message) std::cout << "[ERROR] " << message << '\n';
	#define I_LOG(message) std::cout << "[INFO] " << message << '\n';

#endif

#endif // ! GAME_CONSTANTS_H