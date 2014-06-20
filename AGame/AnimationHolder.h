#ifndef _ANIMATIONHOLDER
#define _ANIMATIONHOLDER

#include <SFML/Graphics.hpp>
#include <memory>
#include "Animation.h"

class AnimationHolder
{
public:
	void		load(Animations::ID id, int frames, float frameInterval, bool isLooping, sf::Texture& texture);
	Animation*	get(Animations::ID id);

private:
	std::map<Animations::ID, Animation*> AnimationMap;
};

#endif // AnimationHolder.h
