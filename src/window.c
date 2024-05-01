#include "../headers/header.h"

static SDL_Renderer *kirendi;
static color_t *rangi_gani;
static SDL_Texture *rangi_ya_thao;
static SDL_Window *dirisha;

/**
 * startScreen - anzisha
 * Return: bool
 */
bool startScreen(void)
{
	SDL_DisplayMode onyeshaa;
	int onyesha_yote, onyesha_yote_juu;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return (false);
	}
	SDL_GetCurrentDisplayMode(0, &onyeshaa);
	onyesha_yote = onyeshaa.w;
	onyesha_yote_juu = onyeshaa.h;
	dirisha = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		onyesha_yote,
		onyesha_yote_juu,
		SDL_WINDOW_BORDERLESS);
	if (!dirisha)
	{
		fprintf(stderr, "Error creating SDL dirisha.\n");
		return (false);
	}
	kirendi = SDL_CreateRenderer(dirisha, -1, 1);
	if (!kirendi)
	{
		fprintf(stderr, "Error creating SDL kirendi.\n");
		return (false);
	}
	SDL_SetRenderDrawBlendMode(kirendi, SDL_BLENDMODE_BLEND);

	rangi_gani = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);

	rangi_ya_thao = SDL_CreateTexture(kirendi, SDL_PIXELFORMAT_RGBA32,
									  SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

	return (true);
}

/**
 * stopScreen - finish kumalo
 *
 */

void stopScreen(void)
{
	free(rangi_gani);
	SDL_DestroyTexture(rangi_ya_thao);
	SDL_DestroyRenderer(kirendi);
	SDL_DestroyWindow(dirisha);
	SDL_Quit();
}

/**
 * removeRangi - ondoa ufla
 * @rangi: rangi
 */

void removeRangi(color_t rangi)
{
	int v;

	for (v = 0; v < SCREEN_WIDTH * SCREEN_HEIGHT; v++)
		rangi_gani[v] = rangi;
}

/**
 * fixRangi - kurenda tu
 *
 */

void fixRangi(void)
{
	SDL_UpdateTexture(
		rangi_ya_thao,
		NULL,
		rangi_gani,
		(int)(SCREEN_WIDTH * sizeof(color_t)));
	SDL_RenderCopy(kirendi, rangi_ya_thao, NULL, NULL);
	SDL_RenderPresent(kirendi);
}

/**
 * choraDot - sti marangi
 * @a: a
 * @b: b
 * @rangi: pixel rangi
 */

void choraDot(int a, int b, color_t rangi)
{
	rangi_gani[(SCREEN_WIDTH * b) + a] = rangi;
}
