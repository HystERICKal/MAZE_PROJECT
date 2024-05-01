#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include "upng.h"

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64

#define MINIMAP_SCALE_FACTOR 0.25

#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS SCREEN_WIDTH

#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

#define NUM_TEXTURES 8

typedef uint32_t color_t;

void keyboardEntry(void);
extern bool GameRunning;

bool startScreen(void);
void stopScreen(void);
void removeRangi(color_t color);
void fixPlay(void);
void fixRangi(void);
void choraDot(int x, int y, color_t color);
void choraMraba(int x, int y, int width, int height, color_t color);
void choraMstari(int x0, int y0, int x1, int y1, color_t color);

bool findHits(float x, float y);
bool ikoNdani(float x, float y);
void fixNav(void);
int pataDhamaniNav(int row, int col);

typedef struct player_s
{
	float x;
	float y;
	float width;
	float height;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
} player_t;

extern player_t player;

void songaMchezaji(float DeltaTime);
void fixMchezaji(void);

typedef struct ray_s
{
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	bool wasHitVertical;
	int wallHitContent;
} ray_t;

extern ray_t rays[NUM_RAYS];

float howFarApart(float x1, float y1, float x2, float y2);
bool mialeJuu(float angle);
bool mialeChini(float angle);
bool mialeKushoto(float angle);
bool mialeKulia(float angle);
void mialeYote(void);
void mialeAngaza(float rayAngle, int stripId);
void fixMiale(void);
void kuguzanaLala(float rayAngle);
void kuguzanaJuu(float rayAngle);

typedef struct texture_s
{
	int width;
	int height;
	color_t *texture_buffer;
	upng_t *upngTexture;
} texture_t;

texture_t wallTextures[NUM_TEXTURES];

void ugumuSawa(void);
void bureUkuta(void);

void fixUkuta(void);

#endif /*HEADER_H*/
