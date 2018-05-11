#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int get_directionkey()
{
	int key;
	key = _getch();
	if (key == 224)
	{
		return _getch();
	}
	return 0;
}

void show_puzzle(int puzzle[][3])
{
	int r, c; //��� ����
	system("cls");
	for (r = 0; r < 3; r++)
	{
		for (c = 0; c < 3; c++)
		{
			if (puzzle[r][c])
			{
				printf("%3d", puzzle[r][c]);
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");//��� 3X3 ����� �������� �����
		}
	}
int end(int puzzle[][3])
{
	int r, c;

	for (r = 0; r < 3; r++)
	{
		for (c = 0; c < 3; c++)
		{
			if (puzzle[r][c] != r + c)
			{
				return r && c;
			}
		}
	}
}
int main(void)
{
	int puzzle[3][3] = {{1,5,7},{3,8,6},{2,4,0}};
	int row = 2; //��
	int col = 2;//��
	int key = 0; //Ű����

	while (!end(puzzle))
	{
		show_puzzle(puzzle);
		printf("����Ű�� ��Ʈ�� \n");
		key = get_directionkey();

		switch (key)
		{
		case RIGHT:
			if (col > 0)
			{
				puzzle[row][col] = puzzle[row][col - 1];
				puzzle[row][col - 1] = 0;
				col--;
			}
			break;
		case LEFT:
			if (col < 3 - 1)
			{
				puzzle[row][col] = puzzle[row][col + 1];
				puzzle[row][col + 1] = 0;
				col++;
			}
			break;
		case DOWN:
			if (row > 0)
			{
				puzzle[row][col] = puzzle[row - 1][col];
				puzzle[row - 1][col] = 0;
				row--;
			}
			break;
		case UP:
			if (row < 3 - 1)
			{
				puzzle[row][col] = puzzle[row + 1][col];
				puzzle[row + 1][col] = 0;
				row++;
			}
			break;
		}
	}
	return 0;
}
		 
