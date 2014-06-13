#include "Yu.h"
#include <iostream>

Yu::Yu() : isMovingLeft(false), isMovingRight(false), velocity(100.f), grounded(true), crouched(false), flip(1)
{
	position.x = 100.f;
	position.y = 250.f;
}

void Yu::load()
{
	textures.load(Textures::Stand, "Assets/YuStand.png");
	animations.load(Animations::Stand, 7, .1f, true, textures.get(Textures::Stand));

	textures.load(Textures::Crouch, "Assets/YuCrouch.png");
	animations.load(Animations::Crouch, 10, .1f, true, textures.get(Textures::Crouch));

	textures.load(Textures::FWalk, "Assets/YuFWalk.png");
	animations.load(Animations::FWalk, 12, .1f, true, textures.get(Textures::FWalk));

	textures.load(Textures::BWalk, "Assets/YuBWalk.png");
	animations.load(Animations::BWalk, 11, .1f, true, textures.get(Textures::BWalk));

	anim = animations.get(Animations::Stand);
}

void Yu::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::D)
		isMovingRight = isPressed;
	else if (key == sf::Keyboard::A)
		isMovingLeft = isPressed;
	else if (key == sf::Keyboard::S)
	{
		crouched = isPressed;
		anim = animations.get(Animations::Crouch);
	}
}

void Yu::update(sf::Time deltaTime)
{
	applyFlip();

	sf::Vector2f movement(0.f, 0.f);

	if(!crouched)
	{
		if(isMovingLeft)
		{
			anim = animations.get(Animations::BWalk);
			movement.x -= velocity;
		}
		if(isMovingRight)
		{
			anim = animations.get(Animations::FWalk);
			movement.x += velocity;
		}
		if((!isMovingLeft  && !isMovingRight) || (isMovingLeft && isMovingRight))
			anim = animations.get(Animations::Stand);
	}

	position.x =  position.x + (movement.x * flip * deltaTime.asSeconds());
	position.y = position.y + (movement.y * flip * deltaTime.asSeconds());

	anim->update(position, deltaTime);
}

void Yu::draw(sf::RenderWindow* window)
{
	anim->draw(window);
}

void Yu::applyFlip()
{
	anim->setScale(flip, 1.f);
}