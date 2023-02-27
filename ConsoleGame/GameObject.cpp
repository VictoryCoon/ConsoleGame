#include "pch.h"
#include "GameObject.h"

vector<GameObject*> GameObject::gameObjects;
vector<GameObject*> GameObject::standbyObjects;

GameObject::GameObject()
{
	position.x = 0;
	position.y = 0;
	speed = 10.f;
	shape = nullptr;
	destroyFlag = false;

	//gameObjects.push_back(this);
	standbyObjects.push_back(this);
}

GameObject::~GameObject()
{
	
}

/*
void GameObject::Update()
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

	Vector2::Normalize(direction);
	// 다음위치 = 현재위치 + 방향 * 속도 * 시간
	position += direction * speed * Time::DeltaTime();
}
*/

void GameObject::Render()
{
	if (shape == nullptr)
	{
		return;
	}
	int roundX = Float::Round(position.x);
	int roundY = Float::Round(position.y);
	Renderer::Draw(roundX, roundY, shape);
}

Vector2& GameObject::GetPosition()
{
	return position;
}

void GameObject::SetPosition(Vector2 pos)
{
	position = pos;
}

void GameObject::SetShape(Shape* shape)
{
	this->shape = shape;
}

void GameObject::Destory()
{
	destroyFlag = true;
}

void GameObject::UpdateAll()
{
	auto iter = gameObjects.begin();
	auto end = gameObjects.end();
	for (; iter < end; ++iter)
	{
		GameObject* obj = *iter;
		obj->Update();
	}
}

void GameObject::RenderAll()
{
	auto iter = gameObjects.begin();
	auto end = gameObjects.end();
	for (; iter < end; ++iter)
	{
		GameObject* obj = *iter;
		obj->Render();
	}
}

void GameObject::StartAll()
{
	auto iter = standbyObjects.begin();
	auto end = standbyObjects.end();
	for (; iter < end; ++iter)
	{
		GameObject* obj = *iter;
		gameObjects.push_back(obj);
	}
	standbyObjects.clear();
}

void GameObject::GarbageCollect()
{
	auto iter = gameObjects.begin();
	auto end = gameObjects.end();
	for (; iter < end;)
	{
		GameObject* obj = *iter;
		if (obj->destroyFlag)
		{
			delete obj;
			iter = gameObjects.erase(iter);
			end = gameObjects.end();
		}
		else
		{
			++iter;
		}
	}
}