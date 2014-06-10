#include "Game.h"
#include <iostream>

Game::Game() : mWindow(sf::VideoMode(1280,720), "SFML Application"), TimePerFrame(sf::seconds(1.f / 60.f))
{
	p1 = new Yu();
	p1->load();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				p1->handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				p1->handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
					break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	p1->update(deltaTime);
}

void Game::render()
{
	mWindow.clear();
	p1->draw(&mWindow);
	mWindow.display();
}