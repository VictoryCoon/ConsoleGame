#pragma once
#include "GameObject.h"
class Bullet :
    public GameObject
{
public:
	Bullet();
	Bullet(const Bullet& rhs);
	virtual ~Bullet();

	virtual void Update() override;
private:
	float tick = 0.f;
	float delay = 5.f;
};

