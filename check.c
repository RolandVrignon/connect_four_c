#include <unistd.h>

int check_right(char **board, int i, int j, int player)
{
    int size;

    size = 0;
    while (board[i][j] == player)
    {
        j++;
        size++;
    }

    if (size >= 4)
        return (1);
    return (0); 
}

int check_left(int **board, int i, int j, int player)
{
    int size;

    size = 0;
    while (board[i][j] == player)
    {
        j--;
        size++;
    }

    if (size >= 4)
        return (1);
    return (0); 
}

int check_top(int **board, int i, int j, int player)
{
    int size;

    size = 0;
    while (board[i][j] == player)
    {
        i++;
        size++;
    }

    if (size >= 4)
        return (1);
    return (0); 
}

int check_diag_right(int **board, int i, int j, int player)
{
    int size;

    size = 0;
    while (board[i][j] == player)
    {
        i++;
        j++;
        size++;
    }

    if (size >= 4)
        return (1);
    return (0); 
}

int check_diag_left(int **board, int i, int j, int player)
{
    int size;

    size = 0;
    while (board[i][j] == player)
    {
        i++;
        j--;
        size++;
    }

    if (size >= 4)
        return (1);
    return (0); 
}

int check_puissance(int **board, int i, int j, int player)
{
    if (check_right(board, i, j, player) || check_left(board, i, j, player) || check_top(board, i, j, player)
        || check_diag_right(board, i, j, player) || check_diag_left(board, i, j, player))
        return (player);
    return (0);
}

int check(int **board)
{
    int player;

    while (board[i])
    {
        while (board[i][j])
        {
            if(board[i][j] != 0)
            {
                player = board[i][j];
                if (check_puissance(board, i, j, player))
                    return (player);
            }
            j++;
        }
        i++;
    }
    return (0);
}