#include "Animation.h"

Animation::Animation(std::string cName, std::string aName, int frames, bool isLooping) {
	charName = cName;
	animName = aName;
	numOfFrames = frames;
	frameIndex = 0;
	updateTime = 0;
	loop = isLooping;

	load();
}

void Animation::update() {
	frameIndex++;

	if(frameIndex > numOfFrames && loop)
		frameIndex = 0;

	sprite.setTextureRect(sf::IntRect((frameIndex * width), 0, width, height));
}

void Animation::load() {
	sf::Texture* texture;

	if(texture->loadFromFile("Texture/Chatacrers/" + charName + "/" + animName + ".png"))
	{
		std::cout <<"Texture not found!" << std::endl;
		return;
	} else
		sprite.setTexture(*texture);

	height = texture->getSize().y;
	width = (texture->getSize().x / numOfFrames);

	sprite.setTextureRect(sf::IntRect((frameIndex * width), 0, width, height));

	delete(texture);
}

void Animation::draw(sf::RenderWindow &app)
{ app.draw(sprite); }

int Animation::getHeight()
{ return height; }

int Animation::getWidth()
{ return width; }