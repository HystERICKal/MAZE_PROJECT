#include "../headers/header.h"

/**
 * howFarApart - how far between points
 * @a1: a1
 * @b1: b1
 * @a2: a2
 * @b2: b2
 * Return: float
 */

float howFarApart(float a1, float b1, float a2, float b2)
{
	return (sqrt(pow((a2 - a1), 2) + pow((b2 - b1), 2)));
}

/**
 * mialeChini - is it facing down?
 * @degr: degr
 * Return: bool
 */

bool mialeChini(float degr)
{
	return (degr > 0 && degr < PI);
}

/**
 * mialeJuu - is it facing up?
 * @degr: degr
 * Return: bool
 */

bool mialeJuu(float degr)
{
	return (!mialeChini(degr));
}

/**
 * mialeKulia - is it facing right
 * @degr: degr
 * Return: bool
 */

bool mialeKulia(float degr)
{
	return (degr < 0.5 * PI || degr > 1.5 * PI);
}

/**
 * mialeKushoto - is it facing left
 * @degr: degr
 * Return: bool
 */

bool mialeKushoto(float degr)
{
	return (!mialeKulia(degr));
}
