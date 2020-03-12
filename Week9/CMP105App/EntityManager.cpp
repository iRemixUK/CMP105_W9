#include "EntityManager.h"
#include <iostream>
using namespace std;

EntityManager::EntityManager()
{
	//spawnPoint = sf::Vector2f(rand(), -50);
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

EntityManager::~EntityManager()
{

}

void EntityManager::spawn(float posx, float posy)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			spawnPoint = sf::Vector2f(posx, posy);
			balls[i].setAlive(true);
			balls[i].setVelocity(200, 0);
			balls[i].setPosition(spawnPoint);
			cout << balls.size();
			return;
			
		}
	}
	
}

void EntityManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y > 675)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void EntityManager::update(float dt)
{
	// call update on all ALIVE balls
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void EntityManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}