#include "../headers/header.h"

bool mchezo_anza = false;
int mwisho_wa_flemu;
player_t mchezaji;

/**
 * setup_game - start game init
 *
 */

void setup_game(void)
{

	mchezaji.x = SCREEN_WIDTH / 2;
	mchezaji.y = SCREEN_HEIGHT / 2;
	mchezaji.width = 1;
	mchezaji.height = 30;
	mchezaji.walkDirection = 0;
	mchezaji.walkSpeed = 100;
	mchezaji.turnDirection = 0;
	mchezaji.turnSpeed = 45 * (PI / 180);
	mchezaji.rotationAngle = PI / 2;
	ugumuSawa();
}

/**
 * update_game - update the game
 *
 */
void update_game(void)
{
	float wakatu_huu;
	int wakati_wa_kungoja = FRAME_TIME_LENGTH - (SDL_GetTicks() - mwisho_wa_flemu);

	if (wakati_wa_kungoja > 0 && wakati_wa_kungoja <= FRAME_TIME_LENGTH)
	{
		SDL_Delay(wakati_wa_kungoja);
	}
	wakatu_huu = (SDL_GetTicks() - mwisho_wa_flemu) / 1000.0f;

	mwisho_wa_flemu = SDL_GetTicks();

	songaMchezaji(wakatu_huu);
	mialeYote();
}

/**
 * render - rendering process
 *
 */

void fixPlay(void)
{
	removeRangi(0xFF000000);

	fixUkuta();

	fixNav();
	fixMiale();
	fixMchezaji();

	fixRangi();
}

/**
 * Destroy - Destroy textures
 *
 */
void destroy_game(void)
{
	bureUkuta();
	stopScreen();
}

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	mchezo_anza = startScreen();

	setup_game();

	while (mchezo_anza)
	{
		keyboardEntry();
		update_game();
		fixPlay();
	}
	destroy_game();
	return (0);
}
