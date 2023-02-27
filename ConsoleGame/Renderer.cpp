#include "pch.h"
#include "Renderer.h"

WCHAR* Renderer::buffer = nullptr;

int localWidth;
int localHeight;

void Renderer::Initialize(int width, int height)
{
	/*
	SMALL_RECT sr;
	sr.Top = 0;
	sr.Left = 0;
	sr.Right = width;
	sr.Bottom = height;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &sr);
	*/
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ä¿¼­ ±½±â (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	buffer = new WCHAR[width * height];
	localWidth = width;
	localHeight = height;
	Clear();
}

void Renderer::Render()
{
	Clear();
	GameObject::RenderAll();

	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	//printf("%s",buffer);
	//wprintf(buffer);	//´À·Á¼­ ¾È¾¸

	DWORD count;	// ¿ªÂüÁ¶
	WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), buffer, lstrlenW(buffer), &count, NULL);

}

void Renderer::Clear()
{
	for (int i = 0;i< localHeight;i++)
	{
		for (int j = 0; j < localWidth; j++)
		{
			int index = i * localWidth + j;
			if (j == localWidth - 1)
			{
				if (i == localHeight - 1)
				{
					buffer[index] = L'\0';
					continue;
				}
				buffer[index] = L'\n';
				continue;
			}
			buffer[index] = L'¡¡';
			
		}
	}
}

void Renderer::Draw(int x, int y, Shape* shape)
{
	int shapeWidth = shape->GetWidth();
	int shapeHeight = shape->GetHeight();
	WCHAR* shapeBuffer = shape->GetBuffer();

	for (int i = 0; i < shapeHeight; i++)
	{
		for (int j = 0; j < shapeWidth; j++)
		{
			int dstX = x + j;
			int dstY = y + i;
			if (dstX < 0 || dstX >= localWidth - 1 || dstY < 0 || dstY > localHeight - 1)
			{
				continue;
			}
			int srcIndex = i * shapeWidth + j;
			int dstIndex = dstY * localWidth + dstX;
			buffer[dstIndex] = shapeBuffer[srcIndex];
		}
	}
}