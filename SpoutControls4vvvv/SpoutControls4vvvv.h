#pragma once

#include "include\SpoutControls.h"

extern "C" { __declspec(dllexport) void InitializeControls(char *sendername, int *numControls, char** names, int *types, float* floats, float* toggles, float* press, char** text); }
extern "C" { __declspec(dllexport) bool UpdateControls(const char** text, float *floats, float *toggles, float *press, int *numControls); }
extern "C" { __declspec(dllexport) void CloseControls(); }
extern "C" __declspec(dllexport) int ReleaseMemory(float *pArray)
{
	delete[] pArray;
	return 0;
};


