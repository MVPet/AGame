#include "Yu.h"
#include <iostream>

Yu::Yu() : isMovingLeft(false), isMovingRight(false), velocity(50.f), grounded(true)
{
	position.x = 100.f;
	position.y = 100.f;
}

void Yu::load()
{
	std::cerr << "BLAH" << std::endl;
	textures.load(Textures::Stand, "Assets/YuStand.png");

	//sprite.setTexture(textures.get(Textures::Stand));
	//sprite.setPosition(100.f, 100.f);
	anim = new Animation(Animations::Stand, 1, true, textures.get(Textures::Stand));
}

void Yu::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::D)
		isMovingRight = isPressed;
	else if (key == sf::Keyboard::A)
		isMovingLeft = isPressed;
}

void Yu::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if(isMovingLeft)
		movement.x -= velocity;
	if(isMovingRight)
		movement.x += velocity;

	position.x =  position.x + (movement.x * deltaTime.asSeconds());
	position.y = position.y + (movement.y * deltaTime.asSeconds());

	anim->update(position);
}

void Yu::draw(sf::RenderWindow* window)
{
	anim->draw(window);
}