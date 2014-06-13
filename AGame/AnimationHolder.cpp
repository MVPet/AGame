#include "AnimationHolder.h"
#include <assert.h>

void AnimationHolder::load(Animations::ID id, int frames, float frameInterval, bool isLooping, sf::Texture& texture)
{
	Animation* anim;
	anim = new Animation(id, frames, frameInterval, true, texture);
	auto inserted = AnimationMap.insert(std::make_pair(id, anim));
	assert(inserted.second);
}

Animation* AnimationHolder::get(Animations::ID id)
{
	auto found = AnimationMap.find(id);
	assert(found != AnimationMap.end());

	return &*found->second;
}