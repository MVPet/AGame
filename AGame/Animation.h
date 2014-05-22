#ifndef _ANIMATION
#define _ANIMATION

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

class Animation {

public:
	int getWidth();
	int getHeight();

	Animation::Animation(std::string, std::string, int, bool);
	void update();
	void draw(sf::RenderWindow &app);

private:
	sf::Sprite sprite;
	std::string charName;
	std::string animName;
	int frameIndex;
	int width;
	int height;
	int numOfFrames;
	int updateTime;
	bool loop;

	void load();

};

#endif