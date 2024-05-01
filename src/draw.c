#include "../headers/header.h"

/**
 * choraMraba - rectangle creator
 * @a: a
 * @b: b
 * @upana: upana
 * @urefu: urefu
 * @rangi: rangi
 */

void choraMraba(int a, int b, int upana, int urefu, color_t rangi)
{
	int i, j;

	for (i = a; i <= (a + upana); i++)
		for (j = b; j <= (b + urefu); j++)
			choraDot(i, j, rangi);
}

/**
 * choraMstari - line creator
 * @a0: a0
 * @b0: b0
 * @a1: a1
 * @b1: b1
 * @rangi: pixel rangi
 */

void choraMstari(int a0, int b0, int a1, int b1, color_t rangi)
{
	float a_up, b_up, a_now, b_now;
	int i, side_refu, a_tri, b_tri;

	a_tri = (a1 - a0);
	b_tri = (b1 - b0);

	side_refu = (abs(a_tri) >= abs(b_tri)) ? abs(a_tri) : abs(b_tri);

	a_up = a_tri / (float)side_refu;
	b_up = b_tri / (float)side_refu;

	a_now = a0;
	b_now = b0;

	for (i = 0; i < side_refu; i++)
	{
		choraDot(round(a_now), round(b_now), rangi);
		a_now += a_up;
		b_now += b_up;
	}
}
