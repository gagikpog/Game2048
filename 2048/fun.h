#ifndef _FUN_H
#define _FUN_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <ctime>

int ShiftL(int*, int = 4);

int ShiftR(int*, int = 4);

int ShiftU(int*, int = 4);

int ShiftD(int*, int = 4);

void PrintArr(int*);

void Randin(int*);

void Restart(int*, int);

void Restart2(int*, int);

int EndOfGame(int*);

#endif // !_FUN_H