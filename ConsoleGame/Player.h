#pragma once
class Player : public GameObject
{
public:
	Player();
	Player(const Player& rhs);
	virtual ~Player();

	virtual void Update() override;
};