#include "pch.h"
#include "Time.h"

LARGE_INTEGER Time::frequency;
LARGE_INTEGER Time::begin;
LARGE_INTEGER Time::end;
float Time::deltaTime;
int Time::frameCount;
float Time::tick;

void Time::Initialize()
{
	begin.QuadPart = 0;
	end.QuadPart = 0;
	frameCount = 0;
	tick = 0.f;
	QueryPerformanceFrequency(&frequency);
}

void Time::Update()
{
	if (begin.QuadPart == 0)
	{
		QueryPerformanceCounter(&begin);
		return;
	}

	QueryPerformanceCounter(&end);
	__int64 cpuTick = (end.QuadPart - begin.QuadPart);
	deltaTime = cpuTick * 0.0000001f;

	begin = end;

	if (tick >= 1.f)
	{
		tick = 0.f;
		string text = "FPS : " + to_string(frameCount);
		SetConsoleTitleA(text.c_str());
		frameCount = 0;
	}

	tick += deltaTime;
	frameCount++;
}

float Time::DeltaTime()
{
	return deltaTime;
}
