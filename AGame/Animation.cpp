#include "Animation.h"

Animation::Animation()
{}

Animation::Animation(Animations::ID id, int frames, float frameInterval, bool isLooping, sf::Texture& texture) {
	numOfFrames = frames;
	frameIndex = 0;
	updateTime = 0;
	loop = isLooping;
	frameTime = frameInterval;

	sprite.setTexture(texture);

	width = texture.getSize().x / frames;
	height = texture.getSize().y;

	sprite.setTextureRect(sf::IntRect((frameIndex * width), 0, width, height));

	boundBox.top = 100.f;
	boundBox.left = 100.f;
	boundBox.width = sprite.getLocalBounds().width;
	boundBox.height = sprite.getLocalBounds().height;
}

void Animation::update(sf::Vector2f pos, sf::Time deltaTime) {

	sprite.setPosition(pos);
	updateTime += deltaTime.asSeconds();

	if(updateTime >= frameTime)
	{
		frameIndex++;
		updateTime = 0.f;

		if(frameIndex >= numOfFrames)
		{
			if (loop)
				frameIndex = 0;
			else
				frameIndex = numOfFrames - 1;
		}
	}

	sprite.setTextureRect(sf::IntRect((frameIndex * width), 0, width, height));
}

void Animation::setScale(float x, float y)
{
	sprite.setScale(x, y);
}

void Animation::draw(sf::RenderWindow* window)
{ window->draw(sprite); }

int Animation::getHeight()
{ return height; }

int Animation::getWidth()
{ return width; }