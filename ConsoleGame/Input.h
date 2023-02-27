#pragma once
#include "pch.h"

enum class Keys
{
	ESC = 0x18	//VK_ESCAPE
	, SpaceBar = 0x20
	, ArrowLt  = 0x25
	, ArrowUp  = 0x26
	, ArrowDn  = 0x28
	, ArrowRt  = 0x27
};

class Input
{
public:
	static bool GetKey(Keys key);

	static void Update();

private:
	static short keyStates[256];
};
