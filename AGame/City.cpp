#include "City.h"

// default constructor
City::City()
{
	p1 = new Yu(100.f, 700.f, false);
	p1->load();

	p2 = new Yu(1000.f, 700.f, true);
	p2->load();
}

// loads everything we need for the stage
// could have a forground as well, but as for now just a background works fine
void City::load()
{
	textures.load(Textures::Background, "Assets/City.png");
	animations.load(Animations::Background, 1, .1f, true, textures.get(Textures::Background), 0, 0, 0, 0, 0, 0, 0, 0);

	anim = animations.get(Animations::Background);

	position.x = 0.f;
	position.y = anim->getHeight();
}

// our update loop per frame
// just update everything in the stage
void City::update(sf::Time deltaTime)
{
	anim->update(position, deltaTime);
	p1->update(deltaTime, p2);
	p2->update(deltaTime, p1);
}

void City::draw(sf::RenderWindow* window)
{
	anim->draw(window);
	p1->draw(window);
	p2->draw(window);
}

// pfft, just pass on the input the each player
// only player 1 is here now, but that will change soon
void City::handlePlayerInput()
{
	p1->handlePlayerInput();
	p2->handlePlayerInput();
}