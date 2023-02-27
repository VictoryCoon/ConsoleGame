#pragma once
class Time
{
public:
	static void Initialize();
	static void Update();

	static float DeltaTime();

private:
	static LARGE_INTEGER frequency;
	static LARGE_INTEGER begin;
	static LARGE_INTEGER end;

	static float deltaTime;

	static int frameCount;
	static float tick;
};