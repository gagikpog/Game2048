#include "GL.h"

#define BUFFER 8192

Label::Label()
{
	Count = 0;
	X = Y = 10;
	W = H = 120;
}

Label::~Label(){}

void Label::Init()
{
	char Text[] = "Game over R - to restart:";
	int text_size(0);

	glBegin(GL_POLYGON);
	
	switch (Count)
	{
	case 0:
		Text[0] = '\0';
		glColor3f(0.9f, 0.9f, 0.9f);
		break;
	case 2:
		glColor3f(1.0f, 1.0f, 1.0f);
		break;
	case 4:
		glColor3f(1.0f, 1.0f, 0.9f);
		break;
	case 8:
		glColor3f(0.4f, 0.9f, 0.1f);
		break;
	case 16:
		glColor3f(0.8f, 0.5f, 0.2f);
		break;
	case 32:
		glColor3f(1.0f, 0.6f, 0.6f);
		break;
	case 64:
		glColor3f(1.0f, 0.3f, 0.3f);
		break;
	case 128:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case 256:
		glColor3f(1.0f, 1.0f, 0.0f);
		break;
	case 512:
		glColor3f(0.6f, 1.0f, 0.1f);
		break;
	case 1024:
		glColor3f(0.5f, 0.5f, 0.7f);
		break;
	case 2048:
		glColor3f(0.60f, 0.85f, 0.80f);
		break;
	case 4096:
		glColor3f(0.60f, 0.25f, 0.20f);
		break;
	case 8192:
		glColor3f(0.30f, 0.45f, 0.70f);
		break;
	case 16384:
		glColor3f(0.80f, 0.5f, 0.40f);
		break;
	case 32768:
		glColor3f(0.60f, 0.5f, 0.60f);
		break;
	case (65536):
		glColor3f(1.0f, 0.4f, 0.4f);
		break;
	default:
		glColor3f(0.40f, 1.0f, 0.80f);
		break;
	}
	
	glVertex2f(X, Y + H*0.1f);
	glVertex2f(X + W*0.03f, Y + H*0.03f);
	glVertex2f(X + W*0.1f, Y);

	glVertex2f(X + W*0.9f, Y);
	glVertex2f(X + W*0.97f, Y + H*0.03f);
	glVertex2f(X + W, Y + H*0.1f);

	glVertex2f(X + W, Y + H*0.9f);
	glVertex2f(X + W*0.97f, Y + H*0.97f);
	glVertex2f(X + W*0.9f, Y + H);

	glVertex2f(X + W*0.1f, Y + H);
	glVertex2f(X + W*0.03f, Y + H*0.97f);
	glVertex2f(X, Y + H*0.9f);

	glEnd();

	if (Count > 0)
		sprintf_s(Text, "%d", Count);

	glColor3f(0, 0, 0);
	
	text_size = strlen(Text);
	glRasterPos2f(X + W / 2 - text_size * 6, Y + H / 2 - 9);
	for (int i = 0; i < text_size; i++)
	{
		glutBitmapCharacter((void*)0x0005, Text[i]);
	}
}

int Rsave(int par)
{
	const TCHAR Bajin[] = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\2048.exe";
	TCHAR szTestString[] = ("dfgdfgdfgdfg");
	sprintf_s(szTestString, "%d", par);
	HKEY hKey;//= HKEY_LOCAL_MACHINE;

	if (RegCreateKeyEx(HKEY_CURRENT_USER, Bajin, NULL, NULL, REG_OPTION_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) != ERROR_SUCCESS)
	{
		return 0;
	}

	if (RegSetValueEx(hKey, ("param"), NULL, REG_SZ, (BYTE*)szTestString, sizeof(szTestString)) != ERROR_SUCCESS)
	{
		return 0;
	}

	if (RegCloseKey(hKey) != ERROR_SUCCESS)
	{
		return 0;
	}
	return 1;
}

int Ropen(int par)
{
	int ppp(0);
	const TCHAR Bajin[61] = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\2048.exe";
	HKEY hKey = HKEY_CURRENT_USER;
	char value[225];
	DWORD BufferSize = BUFFER;

	if (RegGetValue(HKEY_CURRENT_USER, Bajin, ("param"), RRF_RT_REG_SZ, NULL, (PVOID)&value, &BufferSize) != ERROR_SUCCESS)
	{
		return 0;
	}

	for (int k = 0; k < 30; k++)
	{
		if (value[k] == '\0')
			break;
		ppp = ppp * 10 + value[k] - 48;
	}

	return ppp;
}

int Save(int*dasa)
{
	unsigned int tem(0);
	char tt[] = "JSDJDFIUHIASDAHJLLLJMMBXCZXQWEWRTWIEPOWMJASDABNVZCZCMZLAKDOPQWEUIQUQUHJSBDNADADAGSDYGADBANDA";
	std::ofstream fout;
	fout.open("Gs2.div");
	if (!fout.is_open())
		return 0;

	for (int j = 0; j < 16; j++)
	{
		if (dasa[j] != 0)
			tem = (unsigned int)(log2(dasa[j])) * 200;
		else tem = 17 * 200;

		for (int i = 0; i < 90; i++)
		{
			if (!(tem >= 36 && tem <= 126)) {
				tem -= tt[i];
				fout << tt[i];
			}
			else {
				fout << (char)tem << "#";
				break;
			}
		}
	}
	fout << dasa[16] << " " << dasa[17] << " " << dasa[18];
	return 1;
}

int Open(int*dasa)
{
	int error(0);
	std::ifstream fin;
	fin.open("Gs2.div");
	if (!fin.is_open())
		return 0;

	int tem(0);
	char T;

	for (int j = 0; j < 16; j++)
	{
		for (int i = 0; i < 90; i++)
		{
			fin >> T;
			if (T == '#')
				break;
			else tem += (int)T;
		}
		if (tem % 200) { error = 1; }

		if (tem / 200 == 17)	dasa[j] = 0;
		else	dasa[j] = (int)pow(2, tem / 200);
		tem = 0;
	}
	fin >> dasa[16] >> dasa[17] >> dasa[18];

	if (error)
	{
		Restart(dasa, 17);
		return 0;
	}
	return 1;
}