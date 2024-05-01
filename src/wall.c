#include "../headers/header.h"

/**
 * changeColorIntensity - rangi badili
 * @juu_ya: juu ya nini
 * @rangi: rangi
 */

void changeColorIntensity(color_t *rangi, float juu_ya)
{
	color_t yote = (*rangi & 0xFF000000);
	color_t nyekundu = (*rangi & 0x00FF0000) * juu_ya;
	color_t kijan = (*rangi & 0x0000FF00) * juu_ya;
	color_t nyeusi = (*rangi & 0x000000FF) * juu_ya;

	*rangi = yote | (nyekundu & 0x00FF0000) | (kijan & 0x0000FF00) | (nyeusi & 0x000000FF);
}

/**
 * renderFloor - rendering
 * @wallBottomPixel: ya chini
 * @rangi_yake: rangi yake
 * @a: a
 */

void renderFloor(int ya_chini, color_t *rangi_yake, int a)
{
	int d, urefu_wake, upana_wake, laini_a, laini_b;
	float umbali, kumalo;

	upana_wake = wallTextures[3].width;
	urefu_wake = wallTextures[3].height;

	for (d = ya_chini - 1; d < SCREEN_HEIGHT; d++)
	{
		kumalo = player.height / (d - SCREEN_HEIGHT / 2);
		umbali = (kumalo * PROJ_PLANE) / cos(rays[a].rayAngle - player.rotationAngle);

		laini_a = (int)abs((umbali * sin(rays[a].rayAngle)) + player.d);
		laini_b = (int)abs((umbali * cos(rays[a].rayAngle)) + player.a);

		laini_b = (int)(abs(laini_b * upana_wake / 30) % upana_wake);
		laini_a = (int)(abs(laini_a * urefu_wake / 30) % urefu_wake);

		*rangi_yake = wallTextures[4].texture_buffer[(upana_wake * laini_a) + laini_b];
		choraDot(a, d, *rangi_yake);
	}
}

/**
 * renderCeil - cheki juu
 * @ya_juu: ya juu
 * @rangi_yake: rangi
 * @a: a
 */

void renderCeil(int ya_juu, color_t *rangi_yake, int a)
{
	int d, upana_wake, urefu_wake, laini_a, laini_b;

	upana_wake = wallTextures[3].width;
	urefu_wake = wallTextures[3].height;

	for (d = 0; d < ya_juu; d++)
	{
		float umbali, kumalo;

		kumalo = player.height / (d - SCREEN_HEIGHT / 2);
		umbali = (kumalo * PROJ_PLANE) / cos(rays[a].rayAngle - player.rotationAngle);

		laini_a = (int)abs((-umbali * sin(rays[a].rayAngle)) + player.d);
		laini_b = (int)abs((-umbali * cos(rays[a].rayAngle)) + player.a);

		laini_b = (int)(abs(laini_b * upana_wake / 40) % upana_wake);
		laini_a = (int)(abs(laini_a * urefu_wake / 40) % urefu_wake);

		*rangi_yake = wallTextures[6].texture_buffer[(upana_wake * laini_a) + laini_b];
		choraDot(a, d, *rangi_yake);
	}
}

/**
 * fixUkuta - rendering
 *
 */
void fixUkuta(void)
{
	int a, d, wordig, upana_wake, urefu_wake,
		laini_b, ya_chini, urefu_kando,
		ya_juu, kutoka_juu, laini_a;
	float ako_wapi, iko_refu_aje;
	color_t rangi_yake;

	for (a = 0; a < NUM_RAYS; a++)
	{
		ako_wapi = rays[a].umbali * cos(rays[a].rayAngle - player.rotationAngle);
		iko_refu_aje = (TILE_SIZE / ako_wapi) * PROJ_PLANE;
		urefu_kando = (int)iko_refu_aje;
		ya_juu = (SCREEN_HEIGHT / 2) - (urefu_kando / 2);
		ya_juu = ya_juu < 0 ? 0 : ya_juu;
		ya_chini = (SCREEN_HEIGHT / 2) + (urefu_kando / 2);
		ya_chini = ya_chini > SCREEN_HEIGHT
					   ? SCREEN_HEIGHT
					   : ya_chini;
		wordig = rays[a].wallHitContent - 1;
		upana_wake = wallTextures[wordig].width;
		urefu_wake = wallTextures[wordig].height;
		renderFloor(ya_chini, &rangi_yake, a);
		renderCeil(ya_juu, &rangi_yake, a);

		if (rays[a].wasHitVertical)
			laini_b = (int)rays[a].wallHitY % TILE_SIZE;
		else
			laini_b = (int)rays[a].wallHitX % TILE_SIZE;

		for (d = ya_juu; d < ya_chini; d++)
		{
			kutoka_juu = d + (urefu_kando / 2) - (SCREEN_HEIGHT / 2);
			laini_a = kutoka_juu *
					  ((float)urefu_wake / urefu_kando);
			rangi_yake = wallTextures[wordig].texture_buffer[(upana_wake * laini_a) + laini_b];
			if (rays[a].wasHitVertical)
				changeColorIntensity(&rangi_yake, 0.5);
			choraDot(a, d, rangi_yake);
		}
	}
}
