#include "Animation.h"

// Default constructor
Animation::Animation()
{}

// Specialized constructor with info about the Animation
Animation::Animation(Animations::ID id, int frames, float frameInterval, bool isLooping, sf::Texture& texture, float bTop, float bLeft, float bHeight, float bWidth, float atTop, float atLeft, float atHeight, float atWidth) : frameIndex(0), updateTime(0), done(false)
{
	numOfFrames = frames;
	loop = isLooping;
	frameTime = frameInterval;

	sprite.setTexture(texture);

	width = texture.getSize().x / frames;
	height = texture.getSize().y;

	sprite.setTextureRect(sf::IntRect((frameIndex * width), 0, width, height));
	sprite.setOrigin(0, height);

	sTop = bTop;
	sLeft = bLeft;

	aTop  = atTop;
	aLeft = atLeft;


	boundBox.top = (sprite.getPosition().y - sprite.getLocalBounds().height) + sTop;
	boundBox.left = (sprite.getPosition().x) + sLeft;
	boundBox.height = bHeight;
	boundBox.width = bWidth;

	attackBox.top = (sprite.getPosition().y - sprite.getLocalBounds().height) + aTop;
	attackBox.left = (sprite.getPosition().x) + aLeft;
	attackBox.height = atHeight;
	attackBox.width = atWidth;
}

// How the Animation updates per frame
// Goes throught the frames of the animation depending on how long each frame is
// Whole Animation system could be improved with a series of Frame objects containing detailed info about each frame, but I'll cross that bridge when we get there
void Animation::update(sf::Vector2f pos, sf::Time deltaTime) {

	sprite.setPosition(pos);
	
	updateBoxes();

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

void Animation::updateBoxes()
{
	boundBox.top = (sprite.getPosition().y - sprite.getLocalBounds().height) + sTop;
	attackBox.top = (sprite.getPosition().y - sprite.getLocalBounds().height) + aTop;

	if(sprite.getScale().x == 1.f)
	{
		boundBox.left = sprite.getPosition().x + sLeft;
		attackBox.left = sprite.getPosition().x + aLeft;
	}
	else
	{
		boundBox.left = sprite.getPosition().x - sLeft - boundBox.width;
		attackBox.left = sprite.getPosition().x - aLeft - attackBox.width;
	}
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
{ 
	window->draw(sprite); 

	/*sf::RectangleShape square;
	square.setOutlineThickness(10);
	square.setOutlineColor(sf::Color::Green);
	square.setPosition(boundBox.left, boundBox.top);

	sf::Vector2f temp;
	temp.x = boundBox.width;
	temp.y = boundBox.height;
	square.setSize(temp);

	window->draw(square);

	sf::RectangleShape square2;
	square2.setOutlineThickness(10);
	square2.setOutlineColor(sf::Color::Red);
	square2.setPosition(attackBox.left, attackBox.top);

	temp.x = attackBox.width;
	temp.y = attackBox.height;
	square2.setSize(temp);

	window->draw(square2);*/
}

int Animation::getHeight()
{ return height; }

int Animation::getWidth()
{ return width; }

bool Animation::isDone()
{ return done; }

bool Animation::getLoop()
{ return loop; }

sf::FloatRect Animation::getBoundBox()
{ return boundBox; }

sf::FloatRect Animation::getAttackBox()
{ return attackBox; }