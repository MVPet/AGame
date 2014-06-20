#include "Animation.h"

// Default constructor
Animation::Animation()
{}

// Specialized constructor with info about the Animation
Animation::Animation(Animations::ID id, int frames, float frameInterval, bool isLooping, sf::Texture& texture) : frameIndex(0), updateTime(0), done(false)
{
	numOfFrames = frames;
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

// How the Animation updates per frame
// Goes throught the frames of the animation depending on how long each frame is
// Whole Animation system could be improved with a series of Frame objects containing detailed info about each frame, but I'll cross that bridge when we get there
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
			{
				done = true;
				frameIndex = numOfFrames - 1;
			}
		}
	}

	sprite.setTextureRect(sf::IntRect((frameIndex * width), 0, width, height));
}

// Resets the Animation as if it was never played
void Animation::resetAnimation()
{
	done = false;
	frameIndex = 0;
}

void Animation::setScale(float x, float y)
{ sprite.setScale(x, y); }

void Animation::draw(sf::RenderWindow* window)
{ window->draw(sprite); }

int Animation::getHeight()
{ return height; }

int Animation::getWidth()
{ return width; }

bool Animation::isDone()
{ return done; }

bool Animation::getLoop()
{ return loop; }