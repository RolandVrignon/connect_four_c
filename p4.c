#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void display(int sx, int sy)
{
	int x;
	int y;

	x = -1;
	while(x <= sx* 2)
	{
		y = 0;
		while (y < sy)
		{
			if (x == -1 || x == sx * 2)
				printf("===");
			else if (x % 2)
				printf("|  ");
			else
				printf("___");
			y++;
		}
		printf("\n");
		x++;
	}
}

int **creatGrid(int sx, int sy)
{
	int x;
	int y;
	int **tmp;

	tmp = malloc(sizeof(int) * sx);
	x = 0;
	while (x < sx)
	{
		tmp[x] = malloc(sizeof(int) * sy);
		y = 0;
		while (y < sy)
		{
			tmp[x][y] = 0;
			y++;
		}
		x++;
	}
	return (tmp);
}

void ft_displayGrid(int **lst, int sx, int sy)
{
	int x;
	int y;

	x = 0;
	while (x <= sx)
	{
		y = 0;
		while (y < sy)
		{
			if (x == sx)
			{
				printf("%d ", y);
			}
			else
			{
				if (lst[x][y] == 1)
					printf("\033[0;36m");
				else
					printf("\033[0;37m");
				printf("%d ", lst[x][y]);
			}
			y++;
		}
		printf("\n");
		x++;
	}
}

int getPos(int **grid, int pos)
{
	int x;

	x = 0;
	while (x < 6 && grid[x][pos] == 0)
	{
		x++;
	}

	return x - 1;
}

int **play(int **grid)
{
	char c[1];
	int pos;
	printf("que voulez vous jouer?\n");
	read(0, c, 1);
	pos = c[0] - '0';
	grid[getPos(grid, pos)][pos] = 1;
	return grid;
}

int  main()
{
	int **game;
	char *c[1];
	
	game = creatGrid(6,7);
	
	ft_displayGrid(game, 6,7);
	game = play(game);
	system("clear");
	ft_displayGrid(game, 6,7);
	
	

	//game = display(7,6);
	
	//printf("%s", c);
	return (0);
}