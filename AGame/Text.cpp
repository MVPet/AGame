/*
// Let's make our window
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "A Game!");

	// Set the framerate to 60fps
	window->setFramerateLimit(60);

	// Our game manager
	Manager* manager = new Manager(window);
	
	// while the game is open
    while (window->isOpen())
    {
		// update the manager
		manager->update();

		// clear the display
        window->clear();

		// draw whatever the manager has to draw
		manager->draw();

		// draw the display
        window->display();
    }

    return 0;
*/