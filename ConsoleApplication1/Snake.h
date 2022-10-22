#pragma once
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;
class Snake
{
private:
	bool GameOver;
	int const height = 20;
	int const width = 40;
	int heady, headx, fruity, fruitx, score, tail_n, taily[50], tailx[50];
	enum direction{top , dwon, left, right};
	direction dir;
public:
	 Snake():heady(10),headx(20),score(0),tail_n(0),GameOver(false)
	{
		srand(time(0));
		fruity = rand() % (19 - 2 + 1) + 2;
		fruitx = rand() % (39 - 2 + 1) + 2;
	}
	 bool getGameOver()
	 {
		 return GameOver;
	 }
	 void shift(int arr[],int size)
	 {
		 for (int i = size - 2; i >= 0 ; i--)
		 {
			 arr[i + 1] = arr[i];
		 }
	 }
	 void Draw()
	{
		system("cls");
		for (int i = 1; i <= height; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				if (i == 1 || i == 20 || j == 1 || j == 40)
				{
					cout << "#";
				}
				else if (i == heady && j == headx)
				{
					cout << "O";
				}
				else if (i == fruity && j == fruitx)
				{
					cout << "$";
				}
				else
				{
					bool print = false;
					for (int k = 0; k < tail_n; k++)
					{
						if (i == taily[k] && j == tailx[k])
						{
							cout << "o";
							print = true;
							break;
						}
					}
					if (!print)
					{
						cout << " ";
					}
				}
			}
			cout << endl;
		}
		cout << "the player score : " << score << endl;
	}
	 void Input()
	{
		char c;
		if (_kbhit())
		{
			c = _getch();
			switch (c)
			{
			case'w':dir = top; break;
			case's':dir = dwon; break;
			case'a':dir = left; break;
			case'd':dir = right; break;
			}
		}
	}
	 void Logic()
	{
		shift(taily, 50);
		shift(tailx, 50);
		taily[0] = heady;
		tailx[0] = headx;
		switch (dir)
		{
		case top:heady--; break;
		case dwon:heady++; break;
		case left:headx--; break;
		case right:headx++; break;
		}
		if (heady == fruity && headx == fruitx)
		{
			srand(time(0));
			fruity = rand() % (19 - 2 + 1) + 2;
			fruitx = rand() % (39 - 2 + 1) + 2;
			score++;
			tail_n++;
		}
		else if (heady ==1)
		{
			heady = 19;
		}
		else if (heady == 20)
		{
			heady = 1;
		}
		else if (headx == 1)
		{
			headx = 39;
		}
		else if (headx ==40)
		{
			headx = 1;
		}
		
		for (int i = 0; i < tail_n; i++)
		{
			if (heady == taily[i] && headx == tailx[i])
			{
				GameOver = true;
			}
		}
	}
};

