#include "pch.h"
#include "Player.h"

Player::Player()
{
	Shape* shape = Shape::LoadShape(L"player.dat");
	SetShape(shape);
}

Player::Player(const Player& rhs)
{
}

Player::~Player()
{
}

void Player::Update()
{
	Vector2 direction = Vector2::zero;

	if (Input::GetKey(Keys::ArrowUp))
	{
		direction += Vector2::down;
	}
	if (Input::GetKey(Keys::ArrowDn))
	{
		direction += Vector2::up;
	}
	if (Input::GetKey(Keys::ArrowRt))
	{
		direction += Vector2::right;
	}
	if (Input::GetKey(Keys::ArrowLt))
	{
		direction += Vector2::left;
	}

	if (Input::GetKey(Keys::SpaceBar))
	{
		Bullet* bullet = new Bullet();
		bullet->SetPosition(shape->GetCenter()+position);
	}

	Vector2::Normalize(direction);
	// 다음위치 = 현재위치 + 방향 * 속도 * 시간
	position += direction * speed * Time::DeltaTime();
}