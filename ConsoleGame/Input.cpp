#include "pch.h"
#include "Input.h"

short Input::keyStates[256] = { 0, };

bool Input::GetKey(Keys key)
{
	return keyStates[(int)key];	//���� ����
}

void Input::Update()
{
	//keyState
	for (int i = 0; i < 256; i++)
	{
		keyStates[i] = GetAsyncKeyState(i);
	}
}