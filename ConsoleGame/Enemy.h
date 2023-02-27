#pragma once
class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(const Player& rhs);
	virtual ~Enemy();
	virtual void Update() override;
};