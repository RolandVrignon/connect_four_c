#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
	while (x < sx)
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
					printf("\033[0;41m");
				else if(lst[x][y] == 2)
					printf("\033[0;44m");
				else if(lst[x][y] == 3)
					printf("\033[0;43m");
				else if(lst[x][y] == 4)
					printf("\033[0;42m");
				else if(lst[x][y] == 5)
					printf("\033[0;45m");
				else if(lst[x][y] == 6)
					printf("\033[0;46m");
				else if(lst[x][y] == 7)
					printf("\033[0;48m");
				else if(lst[x][y] == 8)
					printf("\033[0;47m");
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
	while (x < 6 || grid[x][pos] == 0)
	{
		//write(1, ".", 1);
		x++;
	}

	return (x - 1);
}

int getPos2(int **grid, int y)
{
	int x;

	x = 0;
	while (x < 6)
	{
		//printf("rien en %d %d\n", x, y);
		if (grid[x][y] != 0)
			return (x - 1);
		x++;
	}

	return (x - 1);
}


int ft_checkpos3(int **grid)
{
	int i;
	int old;
	int new;
	int c;
	int x;

	x = -4;
	c = 0;
	old = 0;
	while (x < 6)
	{
		i = 0;
		while(i < 6)
		{
			new = grid[i][x + i];

			if (old == new && grid[i][x + i] != 0)
				c++;
			else
				c = 0;
			if (c == 3)
				return (old);
			//write(1, "-", 1);
			//printf("\n%d %d %d\n", i, x, c);
			old = new;
			i++;
		}
		c = 0;
		x++;
	}
	return 0;
}
int ft_checkpos4(int **grid)
{
	int i;
	int old;
	int new;
	int c;
	int x;

	x = -4;
	c = 0;
	old = 0;
	while (x < 10)
	{
		i = 0;
		while(i < 6)
		{
			new = grid[i][x - i];

			if (old == new && grid[i][x - i] != 0)
				c++;
			else
				c = 0;
			if (c == 3)
				return (old);
			//write(1, "-", 1);
			//printf("\n%d %d %d\n", i, x, c);
			old = new;
			i++;
		}
		c = 0;
		x++;
	}
	return 0;
}


int ft_checkpos2(int **grid)
{
	int i;
	int old;
	int new;
	int c;
	int x;

	x = 0;
	c = 0;
	old = 0;
	while (x < 6)
	{
		i = 0;
		while(i < 6)
		{
			new = grid[i][x];

			if (old == new && grid[i][x] != 0)
				c++;
			else
				c = 0;
			if (c == 3)
				return (old);
			//write(1, "-", 1);
			//printf("\n%d %d %d\n", i, x, c);
			old = new;
			i++;
		}
		c = 0;
		x++;
	}
	return 0;
}

int ft_checkpos1(int **grid)
{
	int i;
	int old;
	int new;
	int c;
	int x;

	c = 0;
	i = 0;
	old = 0;
	while (i < 6)
	{
		x = 0;
		while(x < 6)
		{
			new = grid[i][x];

			if (old == new && grid[i][x] != 0)
				c++;
			else
				c = 0;
			if (c == 3)
				return (old);
			//write(1, "-", 1);
			//printf("\n%d %d %d\n", i, x, c);
			old = new;
			x++;
		}
		c = 0;
		i++;
	}
	return 0;
}

int **play(int **grid, int player, int *win)
{
	char c[1];
	int pos;
	int y;

	c[0] = 'a';
	printf("que voulez vous jouer?\n :");
	read(0, c, 1);
	pos = c[0] - '0';
	//printf("pos : %d", pos);
	if (pos > 0)
	{
		y = getPos2(grid, pos - 1);
		grid[y][pos - 1] = player;
		*win = ft_checkpos1(grid);
		if (*win !=  0)
			return (grid);
		*win = ft_checkpos2(grid);
		printf("\nwin : %d", *win);
		if (*win !=  0)
			return (grid);
		*win = ft_checkpos3(grid);
		printf("\nwin : %d", *win);
		if (*win !=  0)
			return (grid);
		*win = ft_checkpos4(grid);
		printf("\nwin : %d", *win);
		if (*win !=  0)
			return (grid);
		printf("\nwin : %d\n", *win);
	}
	pos = -10;
	c[0] = (char)2;
	return grid;
}


int  main(int argc, char **argv)
{
	int **game;
	int player;
	int player_c;
	int win;
	(void)argc;
	if (argc == 2)
		player = atoi(argv[1]) - 1;
	else
		player = 1;
	player_c = 1;
	win = 0;
	
	game = creatGrid(6,6);
	
	system("clear");
	
	while(win == 0)
	{	
		player_c = player_c + 1;
		printf("\n\nplayer (%d) (%d)\n", player_c / 2, win);
		game = play(game, player_c / 2, &win);
		system("clear");
		if (player_c / 2 > player)
			player_c = 0;
		ft_displayGrid(game, 6,6);

	}
	system("clear");
	ft_displayGrid(game, 6,6);
	printf("player %d a gagner", win);
	

	//game = display(7,6);
	
	//printf("%s", c);
	return (0);
}