#include "fun.h"

using namespace std;

void PrintArr(int* arr) 
{
	system("cls");
	printf("\n\n\n%9d%4d%4d%4d\n", arr[0], arr[1], arr[2], arr[3]);
	printf("\n%9d%4d%4d%4d\n", arr[4], arr[5], arr[6], arr[7]);
	printf("\n%9d%4d%4d%4d\n", arr[8], arr[9], arr[10], arr[11]);
	printf("\n%9d%4d%4d%4d\n\n\n", arr[12], arr[13], arr[14], arr[15]);
	printf("\n%9d%13d\n", arr[16], arr[17]);

	std::cout << "     q - exit.     r - restart. >";
};

void Randin(int* arr)
{
	int run;
	do {
		run = rand() % 17 - 0;
	} while (arr[run] != 0);
	arr[run] = 2;
}

void Restart(int* arr, int size) 
{
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

void Restart2(int* arr, int size)
{
	for (int i = 0; i < size; i += 4)
		arr[i] = 0;
}

int ShiftL(int* arr, int cikl)
{
	if (!cikl)return 0;
	int temp[5];
	Restart(temp, 5);
	int i, j, stu(0), stu2(0);

	for (int k = 0; k < 3; k++)
		if (arr[k] == 0 && arr[k + 1] > 0)
			stu = 1;

	for (i = 0, j = 0; i < 4; i++)
	{
		if (!(arr[i]))
			continue;
		if (arr[i] == temp[j])
		{
			temp[j] = 2 * arr[i];
			stu = 2 * arr[i];
		}
		else
		{
			temp[j + 1] = arr[i];
		}
		j++;
	};

	Restart(arr, 4);

	for (i = 0, j = 0; i < 5; i++)
	{
		if (!(temp[i]))
			continue;
		arr[j] = temp[i];
		j++;
	};

	stu2 = ShiftL(arr + 4, cikl - 1);

	if (stu > 2 && stu2 > 2) return stu + stu2;
	if (stu < 2 && stu2 > 2) return stu2;
	if (stu > 2 && stu2 < 2) return stu;
	return (stu || stu2);
}

int ShiftR(int* arr, int cikl)
{
	if (!cikl)return 0;
	int temp[5];
	Restart(temp, 5);
	int i, j, stu(0), stu2(0);

	for (int k = 0; k < 3; k++)
		if (arr[k + 1] == 0 && arr[k] > 0)
			stu = 1;


	for (i = 3, j = 0; i >= 0; i--)
	{
		if (!(arr[i]))
			continue;
		if (arr[i] == temp[j])
		{
			temp[j] = 2 * arr[i];
			stu = 2 * arr[i];
		}
		else
		{
			temp[j + 1] = arr[i];
		}
		j++;
	};
	Restart(arr, 4);

	for (i = 0, j = 3; i < 5; i++)
	{
		if (!(temp[i]))
			continue;
		arr[j] = temp[i];
		j--;
	};

	stu2 = ShiftR(arr + 4, cikl - 1);

	if (stu > 2 && stu2 > 2) return stu + stu2;
	if (stu < 2 && stu2 > 2)return stu2;
	if (stu > 2 && stu2 < 2)return stu;
	return (stu || stu2);
}

int ShiftU(int* arr, int cikl)
{
	if (!cikl)return 0;
	int temp[5];
	Restart(temp, 5);
	int i, j, stu(0), stu2(0);

	for (int k = 0; k < 12; k += 4)
		if (arr[k] == 0 && arr[k + 4] > 0)
			stu = 1;

	for (i = 0, j = 0; i < 16; i += 4)
	{
		if (!(arr[i]))
			continue;
		if (arr[i] == temp[j])
		{
			temp[j] = 2 * arr[i];
			stu = 2 * arr[i];
		}
		else
		{
			temp[j + 1] = arr[i];
		}
		j++;
	};

	Restart2(arr, 16);

	for (i = 0, j = 0; i < 5; i++)
	{
		if (!(temp[i]))
			continue;
		arr[j] = temp[i];
		j += 4;
	};

	stu2 = ShiftU((arr + 1), cikl - 1);

	if (stu > 2 && stu2 > 2) return stu + stu2;
	if (stu < 2 && stu2 > 2)return stu2;
	if (stu > 2 && stu2 < 2)return stu;
	return (stu || stu2);
}

int ShiftD(int* arr, int cikl)
{
	if (!cikl)return 0;
	int temp[5];
	Restart(temp, 5);
	int i, j, stu(0), stu2(0);

	for (int k = 0; k < 12; k += 4)
		if (arr[k + 4] == 0 && arr[k] > 0)
			stu = 1;


	for (i = 12, j = 0; i >= 0; i -= 4)
	{
		if (!(arr[i]))
			continue;
		if (arr[i] == temp[j])
		{
			temp[j] = 2 * arr[i];
			stu = 2 * arr[i];
		}
		else
		{
			temp[j + 1] = arr[i];
		}
		j++;
	};
	Restart2(arr, 16);

	for (i = 0, j = 12; i < 5; i++)
	{
		if (!(temp[i]))
			continue;
		arr[j] = temp[i];
		j -= 4;
	};

	stu2 = ShiftD((arr + 1), cikl - 1);

	if (stu > 2 && stu2 > 2) return stu + stu2;
	if (stu < 2 && stu2 > 2)return stu2;
	if (stu > 2 && stu2 < 2)return stu;
	return (stu || stu2);
}

int EndOfGame(int* arr)
{
	int i(0);

	while (i < 16) {
		if (arr[i] == 0)
			return 0;
		i++;
	}

	for (i = 0; i < 15; i++)
	{
		if (i == 3 || i == 7 || i == 11)
			i++;
		if (arr[i] == arr[i + 1])
			return 0;
	}

	for (i = 0; i < 11; i++)
		if (arr[i] == arr[i + 4])
			return 0;

	return 1;
}