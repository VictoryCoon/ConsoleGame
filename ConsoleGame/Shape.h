#pragma once
class Shape
{
public:
	Shape();
	Shape(const Shape& rhs);
	~Shape();

	static Shape* LoadShape(const wstring& fileName);

	Vector2 GetCenter();
	int GetWidth();
	int GetHeight();
	WCHAR* GetBuffer();

private:
	int width;
	int height;
	WCHAR* buffer;
};

