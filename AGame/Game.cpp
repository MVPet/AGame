#include "Game.h"
#include <iostream>

// Class will not stay this way forever, especially once menus are added in

// default constructor
Game::Game() : mWindow(sf::VideoMode(1280,720), "SFML Application"), TimePerFrame(sf::seconds(1.f / 60.f))
{
	stage = new RoofNight();
	stage->load();
}

// our "infinte" loop that starts the game clock and loops while the window is open
// updates the game ~60fps
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

// process the events occuring inside the game
void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				//p1->handlePlayerInput(event.key.code, true);
				stage->handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				//p1->handlePlayerInput(event.key.code, false);
				stage->handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
					break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	stage->update(deltaTime);
}

// render the game tot he screen, by clearing the window and drawing everything
void Game::render()
{
	mWindow.clear();
	stage->draw(&mWindow);
	mWindow.display();
}