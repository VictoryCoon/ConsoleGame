#pragma once

enum class ObjectType
{
	Player
	,Bullet
};

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update() = 0;
	void Render();

	Vector2& GetPosition();
	void SetPosition(Vector2 pos);

	void SetShape(Shape* shape);

	void Destory();

public:
	static void UpdateAll();
	static void RenderAll();
	static void StartAll();
	static void GarbageCollect();

protected:
	Vector2 position;
	float speed;
	Shape* shape;
	bool destroyFlag;

private:
	static vector<GameObject*> gameObjects;
	static vector<GameObject*> standbyObjects;
};

