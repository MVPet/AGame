#include "Fighter.h"

void Fighter::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Fighter::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Fighter::getVelocity() const
{
	return mVelocity;
}