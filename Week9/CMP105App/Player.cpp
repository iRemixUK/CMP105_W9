#include "Player.h"

Player::Player()
{
	speedx = 0.f;
	speedy = 0.f;
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W)) // Up
	{
		speedy = -200.f;
	}
	else if (input->isKeyDown(sf::Keyboard::S)) // Down
	{
		speedy = 200.f;
	}
	else
	{
		speedy = 0;
	}

	if (input->isKeyDown(sf::Keyboard::A)) // Left
	{
		speedx = -200.f;
	}
	else if (input->isKeyDown(sf::Keyboard::D)) // Right
	{
		speedx = 200.f;
	}
	else
	{
		speedx = 0;
	}
}

float Player::getSpeedX()
{
	return speedx;
}

float Player::getSpeedY()
{
	return speedy;
}