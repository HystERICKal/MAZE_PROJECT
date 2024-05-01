#include "../headers/header.h"

ray_t miale[NUM_RAYS];

static bool pata_ukuta_lala, pata_ukuta_amka;
static float gonga_ukuta_lala, gonga_ukuta_lala_b, gonga_ukuta_amka_a, gonga_ukuta_amka_b;
static int ukuta_lala, ukuta_amka;

/**
 * kuguzanaLala - ukuta lala
 * @miale_hit: miale inapo gonga
 */

void kuguzanaLala(float miale_hit)
{
	float ukuta_lala_guza_a, ukuta_lala_guza_b, kutana_a, kutana_b, kanyaga_a, kanyaga_b;

	pata_ukuta_lala = false;
	gonga_ukuta_lala = gonga_ukuta_lala_b = ukuta_lala = 0;

	kutana_b = floor(player.y / TILE_SIZE) * TILE_SIZE;
	kutana_b += mialeChini(miale_hit) ? TILE_SIZE : 0;

	kutana_a = player.x + (kutana_b - player.y) / tan(miale_hit);

	kanyaga_b = TILE_SIZE;
	kanyaga_b *= mialeJuu(miale_hit) ? -1 : 1;
	kanyaga_a = TILE_SIZE / tan(miale_hit);
	kanyaga_a *= (mialeKushoto(miale_hit) && kanyaga_a > 0) ? -1 : 1;
	kanyaga_a *= (mialeKulia(miale_hit) && kanyaga_a < 0) ? -1 : 1;
	ukuta_lala_guza_a = kutana_a;
	ukuta_lala_guza_b = kutana_b;

	while (ikoNdani(ukuta_lala_guza_a, ukuta_lala_guza_b))
	{
		float angalia_a = ukuta_lala_guza_a;
		float angalia_b = ukuta_lala_guza_b + (mialeJuu(miale_hit) ? -1 : 0);

		if (findHits(angalia_a, angalia_b))
		{
			gonga_ukuta_lala = ukuta_lala_guza_a;
			gonga_ukuta_lala_b = ukuta_lala_guza_b;
			ukuta_lala = pataDhamaniNav((int)floor(angalia_b / TILE_SIZE),
										(int)floor(angalia_a / TILE_SIZE));
			pata_ukuta_lala = true;
			break;
		}
		ukuta_lala_guza_a += kanyaga_a;
		ukuta_lala_guza_b += kanyaga_b;
	}
}

/**
 * kuguzanaJuu - guzana na ukuta
 * @miale_hit: miale inapo gonga
 */

void kuguzanaJuu(float miale_hit)
{
	float guza_ingine_a, guza_ingine_b;
	float kutana_a, kutana_b, kanyaga_a, kanyaga_b;

	pata_ukuta_amka = false;
	gonga_ukuta_amka_a = 0;
	gonga_ukuta_amka_b = 0;
	ukuta_amka = 0;

	kutana_a = floor(player.x / TILE_SIZE) * TILE_SIZE;
	kutana_a += mialeKulia(miale_hit) ? TILE_SIZE : 0;
	kutana_b = player.y + (kutana_a - player.x) * tan(miale_hit);

	kanyaga_a = TILE_SIZE;
	kanyaga_a *= mialeKushoto(miale_hit) ? -1 : 1;
	kanyaga_b = TILE_SIZE * tan(miale_hit);
	kanyaga_b *= (mialeJuu(miale_hit) && kanyaga_b > 0) ? -1 : 1;
	kanyaga_b *= (mialeChini(miale_hit) && kanyaga_b < 0) ? -1 : 1;
	guza_ingine_a = kutana_a;
	guza_ingine_b = kutana_b;

	while (ikoNdani(guza_ingine_a, guza_ingine_b))
	{
		float angalia_a = guza_ingine_a + (mialeKushoto(miale_hit) ? -1 : 0);
		float angalia_b = guza_ingine_b;

		if (findHits(angalia_a, angalia_b))
		{
			gonga_ukuta_amka_a = guza_ingine_a;
			gonga_ukuta_amka_b = guza_ingine_b;
			ukuta_amka = pataDhamaniNav((int)floor(angalia_b / TILE_SIZE),
										(int)floor(angalia_a / TILE_SIZE));
			pata_ukuta_amka = true;
			break;
		}
		guza_ingine_a += kanyaga_a;
		guza_ingine_b += kanyaga_b;
	}
}

/**
 * mialeAngaza - angaza miale
 * @miale_hit: miale inapogonga
 * @toa_ngozi: kazana
 */

void mialeAngaza(float miale_hit, int toa_ngozi)
{
	float gonga_umbali_a, gonga_umbali_b;

	miale_hit = remainder(miale_hit, TWO_PI);
	if (miale_hit < 0)
		miale_hit = TWO_PI + miale_hit;

	kuguzanaLala(miale_hit);

	kuguzanaJuu(miale_hit);

	gonga_umbali_a = pata_ukuta_lala
						 ? howFarApart(player.x, player.y, gonga_ukuta_lala, gonga_ukuta_lala_b)
						 : FLT_MAX;
	gonga_umbali_b = pata_ukuta_amka
						 ? howFarApart(player.x, player.y, gonga_ukuta_amka_a, gonga_ukuta_amka_b)
						 : FLT_MAX;

	if (gonga_umbali_b < gonga_umbali_a)
	{
		miale[toa_ngozi].distance = gonga_umbali_b;
		miale[toa_ngozi].wallHitX = gonga_ukuta_amka_a;
		miale[toa_ngozi].wallHitY = gonga_ukuta_amka_b;
		miale[toa_ngozi].wallHitContent = ukuta_amka;
		miale[toa_ngozi].wasHitVertical = true;
		miale[toa_ngozi].miale_hit = miale_hit;
	}
	else
	{
		miale[toa_ngozi].distance = gonga_umbali_a;
		miale[toa_ngozi].wallHitX = gonga_ukuta_lala;
		miale[toa_ngozi].wallHitY = gonga_ukuta_lala_b;
		miale[toa_ngozi].wallHitContent = ukuta_lala;
		miale[toa_ngozi].wasHitVertical = false;
		miale[toa_ngozi].miale_hit = miale_hit;
	}
}

/**
 * mialeYote - angaza zote
 *
 */

void mialeYote(void)
{
	int along;

	for (along = 0; along < NUM_RAYS; along++)
	{
		float miale_hit = player.rotationAngle +
						  atan((along - NUM_RAYS / 2) / PROJ_PLANE);
		mialeAngaza(miale_hit, along);
	}
}

/**
 * fixMiale - chora miale
 */

void fixMiale(void)
{
	int v;

	for (v = 0; v < NUM_RAYS; v += 50)
	{
		choraMstari(
			player.x * MINIMAP_SCALE_FACTOR,
			player.y * MINIMAP_SCALE_FACTOR,
			miale[v].wallHitX * MINIMAP_SCALE_FACTOR,
			miale[v].wallHitY * MINIMAP_SCALE_FACTOR,
			0xFF0000FF);
	}
}
