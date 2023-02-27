#pragma once
class Renderer
{
public:
	static void Initialize(int width, int height);
	static void Render();
	static void Clear();

	static void Draw(int x, int y, Shape* shape);

private:
	static WCHAR* buffer;
};