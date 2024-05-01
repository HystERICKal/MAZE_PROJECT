#include "../headers/header.h"

/**
 * songaMchezaji - songesha
 * @wakati_wake: wakati wake
 */

void songaMchezaji(float wakati_wake)
{
	float songesha_guu, a_mpya, b_mpya;

	player.rotationAngle += player.turnDirection * player.turnSpeed * wakati_wake;
	songesha_guu = player.walkDirection * player.walkSpeed * wakati_wake;

	a_mpya = player.x + cos(player.rotationAngle) * songesha_guu;
	b_mpya = player.y + sin(player.rotationAngle) * songesha_guu;

	if (!findHits(a_mpya, b_mpya))
	{
		player.x = a_mpya;
		player.y = b_mpya;
	}
}

/**
 * fixMchezaji - player rendering
 *
 */

void fixMchezaji(void)
{
	choraMraba(
		player.x * MINIMAP_SCALE_FACTOR,
		player.y * MINIMAP_SCALE_FACTOR,
		player.width * MINIMAP_SCALE_FACTOR,
		player.height * MINIMAP_SCALE_FACTOR,
		0xFFFFFFFF);
}
