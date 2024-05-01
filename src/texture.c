#include "../headers/header.h"

static const char *textureFileNames[NUM_TEXTURES] = {
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/mossystone.png",
	"./images/graystone.png",
	"./images/colorstone.png",
	"./images/bluestone.png",
	"./images/wood.png",
	"./images/eagle.png",
};

/**
 * ugumuSawa - are they ready?
 *
 */
void ugumuSawa(void)
{
	int v;

	for (v = 0; v < NUM_TEXTURES; v++)
	{
		upng_t *upng;

		upng = upng_new_from_file(textureFileNames[v]);

		if (upng != NULL)
		{
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{
				wallTextures[v].upngTexture = upng;
				wallTextures[v].width = upng_get_width(upng);
				wallTextures[v].height = upng_get_height(upng);
				wallTextures[v].texture_buffer = (color_t *)upng_get_buffer(upng);
			}
		}
	}
}

/**
 * bureUkuta - ziwachilie
 *
 */

void bureUkuta(void)
{
	int v;

	for (v = 0; v < NUM_TEXTURES; v++)
		upng_free(wallTextures[v].upngTexture);
}
