#include "GL.h"

using namespace std;

int Win_H_W = 600;
int arr[19];
Label Table[18];

void Initialize();

void Display()
{
	glutReshapeWindow(Win_H_W, Win_H_W);
	glClearColor(0.0f, 0.9f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (EndOfGame(arr))
	{
		Label lab;
		lab.H = 30;
		lab.W = 500;
		lab.X = 50;
		lab.Y = 560;
		lab.Count = -1;
		lab.Init();
	}

	for (int i = 0; i < 18; i++)
		Table[i].Init();

	glutSwapBuffers();
}

void keys(int key, int x, int y)
{
	int score(0);
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (score = ShiftL(arr))
			Randin(arr);
		break;
	case GLUT_KEY_RIGHT:
		if (score = ShiftR(arr))
			Randin(arr);
		break;
	case GLUT_KEY_UP:
		if (score = ShiftD(arr))
			Randin(arr);
		break;
	case GLUT_KEY_DOWN:
		if (score = ShiftU(arr))
			Randin(arr);
		break;
	}

	if (score > 2)
		arr[16] += score;

	if (arr[16] >= arr[17])
		arr[17] = arr[16];

	for (int i = 0; i < 18; i++)
		Table[i].Count = arr[i];
	glutPostRedisplay();
	Save(arr);
}

void keys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		Restart(arr, 17);
		Randin(arr);
		Randin(arr);
		for (int i = 0; i < 18; i++)
			Table[i].Count = arr[i];
		Save(arr);
		glutPostRedisplay();
		break; 
	}
}

int main(int argc, char** argv)
{
	HANDLE _hMutex;
	_hMutex = CreateMutex(NULL, TRUE, "2048");
	if (!_hMutex)
		return FALSE;

	if (GetLastError() == ERROR_ALREADY_EXISTS)
		return FALSE;

	if (!Open(arr))
	{
		arr[18] = 1;
		Rsave(arr[18]);
		Randin(arr);
		Randin(arr);
		Save(arr);
	}
	else 
	{
		if (arr[18] != Ropen())
		{
			Restart(arr, 19);
			arr[18] = 1;
			Rsave(arr[18]);
			Randin(arr);
			Randin(arr);
			Save(arr);
		}
		else 
		{
			arr[18]++;
			Rsave(arr[18]);
			Save(arr);
		}
	}

	for (int i = 0; i < 18; i++)
		Table[i].Count = arr[i];

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(Win_H_W, Win_H_W);
	glutCreateWindow("2048");

	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Win_H_W, 0, Win_H_W);
	Initialize();


	glutPostRedisplay();
	glutSpecialFunc(keys);
	glutKeyboardFunc(keys);
	glutDisplayFunc(Display);
	glutMainLoop();

	return 0;
}

void Initialize()
{
	int j(0), k(0);
	for (int i = 0; i < 16; i++)
	{
		Table[i].X = (j * Table[i].H + j) + Win_H_W / 2 - Table[i].H * 2;
		Table[i].Y = (k * Table[i].H + k) + Win_H_W / 2 - Table[i].H * 2;
		if (j == 3)
		{
			j = 0;
			k++;
		}
		else
		{
			j++;
		}
	}

	Table[16].H = 40;
	Table[16].W = 150;
	Table[16].X = 60;
	Table[16].Y = 10;

	Table[17].H = 40;
	Table[17].W = 150;
	Table[17].X = 390;
	Table[17].Y = 10;
}