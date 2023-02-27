#include "pch.h"
#include "Bullet.h"

Bullet::Bullet()
{
	Shape* shape = Shape::LoadShape(L"bullet.dat");
	SetShape(shape);
	speed = 20.f;
}

Bullet::Bullet(const Bullet& rhs)
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	Vector2 direction = Vector2::down;
	position += direction * speed * Time::DeltaTime();

	tick += Time::DeltaTime();
	if (tick > delay)
	{
		tick = 0.f;
		Destory();
	}
}