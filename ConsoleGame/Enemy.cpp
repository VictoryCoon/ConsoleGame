#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
	Shape* shape = Shape::LoadShape(L"enemy.dat");
	SetShape(shape);
}

Enemy::Enemy(const Player& rhs)
{
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	Vector2 direction = Vector2::zero;

	Vector2::Normalize(direction);
	position += direction * speed * Time::DeltaTime();
}
