#pragma once

#include "fun.h"
#include <GL\freeglut.h>
#include <string>
#include <stdio.h>

class Label
{
public:
	Label();
	~Label();
public:
	float X, Y, H, W;
	int Count;
	void Init();
private:
};

int Save(int*);

int Open(int*);

int Rsave(int = 0);

int Ropen(int = 0);