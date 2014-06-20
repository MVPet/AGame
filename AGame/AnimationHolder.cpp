#include "AnimationHolder.h"
#include <assert.h>

// loads a new animation and places it intot he animation map
void AnimationHolder::load(Animations::ID id, int frames, float frameInterval, bool isLooping, sf::Texture& texture)
{
	Animation* anim;
	anim = new Animation(id, frames, frameInterval, isLooping, texture);
	auto inserted = AnimationMap.insert(std::make_pair(id, anim));
	assert(inserted.second);
}

// we find an animation in the map and return the address of it
Animation* AnimationHolder::get(Animations::ID id)
{
	auto found = AnimationMap.find(id);
	assert(found != AnimationMap.end());

	return &*found->second;
}