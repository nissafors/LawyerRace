#ifndef _STATIC_H_
#define _STATIC_H_

///Direction for enemies and player (player uses only DOWN - LEFT)
enum Direction {
	RIGHT  = 0,
	LEFT = 1,
	UP    = 2, 
	DOWN  = 3,
	UP_RIGHT = 4,
	UP_LEFT = 5,
	DOWN_LEFT = 6,
	DOWN_RIGHT = 7,
	STILL = 8
};

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

extern int DIFFICULTY;

extern const char* const WINDOW_TEXT;

extern int W_WIDTH;	///<Window Width
extern int W_HEIGHT;	///<Window Height

extern const int W_BPP;		///<Window Depth

extern const int P_WIDTH;		///<Size of Player sprite width
extern const int P_HEIGHT;	///<Size of Player sprite height
extern const char* const P1_SRC;
extern const char* const P2_SRC;
extern const char* const P3_SRC;
extern const char* const P4_SRC;

extern const int E_WIDTH;		///<Size of Enemy sprite width
extern const int E_HEIGHT;	///<Size of Enemy sprite height
extern const char* const E_SRC;

extern const int D_WIDTH;		///<Size of Dollar sprite width
extern const int D_HEIGHT;	///<Size of Dollar sprite height
extern const char* const D_SRC;

extern const int MAX_R_WIDTH;
extern const int MAX_R_HEIGHT;
extern const int R_1_WIDTH;
extern const int R_1_HEIGHT;
extern const char* const R_1_SRC;
extern const int R_2_WIDTH;
extern const int R_2_HEIGHT;
extern const char* const R_2_SRC;
extern const int R_3_WIDTH;
extern const int R_3_HEIGHT;
extern const char* const R_3_SRC;

extern int MAX_ENEMIES;
extern int ENEMIES_BEFORE_ROCK;
extern int MAX_ROCKS;

/*!
* SPEED_FACTOR is used in FPS.cpp to control speed of the game. 
* Based on width of screen, because I think it should take the same amount of time to travel from side to side regardless of screensize.
* Tweaks also allows the entities default speed to be 1.0.
*/
extern float SPEED_FACTOR;		
extern const float P_VELOCITY;		///< Player velocity
extern float E_VELOCITY;		///< Enemy velocity
extern float R_1_VELOCITY;		///< Rock velocity
extern float R_2_VELOCITY;	///< Rock velocity
extern float R_3_VELOCITY;		///< Rock velocity

#endif