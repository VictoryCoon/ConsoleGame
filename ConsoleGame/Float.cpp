#include "pch.h"
#include "Float.h"

int Float::Round(float value)
{
	/*
	int num = (int)value;
	float rest = value - num;
	if (rest > 0.5f) {
		rest = 1;
	}
	else {
		rest = 0;
	}
	return num+rest;
	*/
	return value + 0.5f;
}
