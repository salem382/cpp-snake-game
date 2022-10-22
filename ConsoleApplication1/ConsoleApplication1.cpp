#include <iostream>
#include<ctime>
#include<conio.h>
#include <windows.h>
using namespace std;
#include "Snake.h"
int main()
{
	Snake s;
	while (!s.getGameOver())
	{
		s.Draw();
		s.Input();
		s.Logic();
		Sleep(50);
	}
}
