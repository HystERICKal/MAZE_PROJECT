#include "../headers/header.h"

static const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
	{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6},
	{6, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 6, 0, 7, 7, 0, 0, 0, 0, 6},
	{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 7, 0, 6},
	{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 6},
	{6, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 1, 0, 0, 0, 0, 7, 7, 0, 6},
	{6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
	{6, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
	{6, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}};

/**
 * findHits - is there a collision
 * @a: a
 * @b: b
 * Return: boolean
 */

bool findHits(float a, float b)
{
	int a_kwa_map, b_kwa_map;

	if (a < 0 || a >= MAP_NUM_COLS * TILE_SIZE ||
		b < 0 || b >= MAP_NUM_ROWS * TILE_SIZE)
		return (true);

	a_kwa_map = floor(a / TILE_SIZE);
	b_kwa_map = floor(b / TILE_SIZE);
	return (map[b_kwa_map][a_kwa_map] != 0);
}

/**
 * ikoNdani - iko ndani?
 * @a: a
 * @b: b
 * @Return: bool
 */

bool ikoNdani(float a, float b)
{
	return (a >= 0 && a <= MAP_NUM_COLS * TILE_SIZE &&
			b >= 0 && b <= MAP_NUM_ROWS * TILE_SIZE);
}

/**
 * pataDhamaniNav - value of map
 * @across: across
 * @along: along
 * @Return: int
 */

int pataDhamaniNav(int across, int along)
{

	return (map[across][along]);
}

/**
 * fixNav - mao rendering
 *
 */

void fixNav(void)
{
	int x, y, a_box, b_box;
	color_t rangi_yake;

	for (x = 0; x < MAP_NUM_ROWS; x++)
	{
		for (y = 0; y < MAP_NUM_COLS; y++)
		{
			a_box = y * TILE_SIZE;
			b_box = x * TILE_SIZE;
			rangi_yake = map[x][y] != 0 ? 0xFFFFFFFF : 0x00000000;

			choraMraba(
				a_box * MINIMAP_SCALE_FACTOR,
				b_box * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				rangi_yake);
		}
	}
}
