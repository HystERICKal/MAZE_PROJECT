#include "../headers/header.h"

/**
 * SDL_KEYDOWN_FUNC - key pressed already
 * @the_sesh: session
 */

void SDL_KEYDOWN_FUNC(SDL_Event the_sesh)
{
	if (the_sesh.key.keysym.sym == SDLK_ESCAPE)
		GameRunning = false;
	if (the_sesh.key.keysym.sym == SDLK_UP)
		player.walkDirection = +1;
	if (the_sesh.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = -1;
	if (the_sesh.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = +1;
	if (the_sesh.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = -1;
	if (the_sesh.key.keysym.sym == SDLK_w)
		player.walkDirection = +1;
	if (the_sesh.key.keysym.sym == SDLK_s)
		player.walkDirection = -1;
	if (the_sesh.key.keysym.sym == SDLK_a)
		player.turnDirection = -1;
	if (the_sesh.key.keysym.sym == SDLK_d)
		player.turnDirection = +1;
}

/**
 * SDL_KEYUP_FUNC - key unpressed
 * @the_sesh: session
 */

void SDL_KEYUP_FUNC(SDL_Event the_sesh)
{
	if (the_sesh.key.keysym.sym == SDLK_UP)
		player.walkDirection = 0;
	if (the_sesh.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = 0;
	if (the_sesh.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = 0;
	if (the_sesh.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = 0;
	if (the_sesh.key.keysym.sym == SDLK_w)
		player.walkDirection = 0;
	if (the_sesh.key.keysym.sym == SDLK_s)
		player.walkDirection = 0;
	if (the_sesh.key.keysym.sym == SDLK_a)
		player.turnDirection = 0;
	if (the_sesh.key.keysym.sym == SDLK_d)
		player.turnDirection = 0;
}

/**
 * keyboardEntry - user input handled
 *
 */
void keyboardEntry(void)
{
	SDL_Event the_sesh;

	SDL_PollEvent(&the_sesh);

	if (the_sesh.type == SDL_QUIT)
		GameRunning = false;
	else if (the_sesh.type == SDL_KEYDOWN)
		SDL_KEYDOWN_FUNC(the_sesh);
	else if (the_sesh.type == SDL_KEYUP)
		SDL_KEYUP_FUNC(the_sesh);
}
