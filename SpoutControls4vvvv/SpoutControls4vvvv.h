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

extern "C" { __declspec(dllexport) void InitializeControls(char *sendername, int *numControls, char** names, int *types, double* floats, double* toggles, double* press, char** text); }
//extern "C" { __declspec(dllexport) void InitializeControls(MYCONTROLS* myC); }
extern "C" { __declspec(dllexport) bool UpdateControls(const char** text, double *floats, double *toggles, double *press, int *numControls); }
extern "C" { __declspec(dllexport) void  UpdateFloatControls(int *numControls, double * floats); }
extern "C" { __declspec(dllexport) void CloseControls(); }
//
extern "C" __declspec(dllexport) int ReleaseMemory(double *pArray)
{
	delete[] pArray;
	//delete[] Usize;
	return 0;
};


