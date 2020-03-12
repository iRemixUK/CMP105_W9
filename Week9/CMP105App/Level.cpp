#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Goomba.png");
	player.setTexture(&texture);
	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(100, 510);
	player.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt)
	/*if (input->isKeyDown(sf::Keyboard::Space))
	{
		manager.spawn();
		input->setKeyUp(sf::Keyboard::Space);
	}*/
}

// Update game objects
void Level::update(float dt)
{
	player.move(player.getSpeedX() * dt, player.getSpeedY() * dt);
	//manager.update(dt);

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(player);
	manager.render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	manager.render(window);
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}