#pragma once

#include "include\SpoutControls.h"

typedef struct MYCONTROLS
{
	char* senderName;
	int* numControls;
	char** names;
	char** types;
	double* floats;
	double* toggles;
	double* press;
	char** text;

} MYCONTROLS;

typedef struct MYSTRINGS
{
	char** names;
	char** types;
	char** text;

} MYSTRINGS;

extern "C" { __declspec(dllexport) void InitializeControls(char *sendername, int *numControls, char** names, int *types, float* floats, float* toggles, float* press, char** text); }
//extern "C" { __declspec(dllexport) void InitializeControls(MYCONTROLS* myC); }
extern "C" { __declspec(dllexport) bool UpdateControls(const char** text, float *floats, float *toggles, float *press, int *numControls); }
extern "C" { __declspec(dllexport) void  UpdateFloatControls(int *numControls, float * floats); }
extern "C" { __declspec(dllexport) void CloseControls(); }
//
extern "C" __declspec(dllexport) int ReleaseMemory(float *pArray)
{
	delete[] pArray;
	//delete[] Usize;
	return 0;
};


