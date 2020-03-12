#pragma once
#include "Framework/GameObject.h"
class Player :
	public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt) override;
	float getSpeedY();
	float getSpeedX();
private:
	float speedx;
	float speedy;
};
