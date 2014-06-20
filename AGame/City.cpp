#include "City.h"

// default constructor
City::City()
{
	position.x = 0.f;
	position.y = 0.f;

	p1 = new Yu(100.f, 250.f);
	p1->load();
}

// loads everything we need for the stage
// could have a forground as well, but as for now just a background works fine
void City::load()
{
	textures.load(Textures::Background, "Assets/City.png");
	animations.load(Animations::Background, 1, .1f, true, textures.get(Textures::Background));

	anim = animations.get(Animations::Background);
}

// our update loop per frame
// just update everything in the stage
void City::update(sf::Time deltaTime)
{
	anim->update(position, deltaTime);
	p1->update(deltaTime);
}

void City::draw(sf::RenderWindow* window)
{
	anim->draw(window);
	p1->draw(window);
}

// pfft, just pass on the input the each player
// only player 1 is here now, but that will change soon
void City::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	p1->handlePlayerInput(key, isPressed);
}