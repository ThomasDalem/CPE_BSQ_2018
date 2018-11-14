/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** Bootstrap for BSQ
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void add_x(char **map, int pos_x, int pos_y, int square_size)
{
    for (int i = 0; i < square_size; i++) {
        for (int y = 0; y < square_size; y++)
            map[pos_x + i][pos_y + y] = 'X';
    }
}

int check_line(char *line, int col, int square_size)
{
    int i = 0;

    while (i < square_size) {
        if (line[col + i] != '.')
            return (0);
        i++;
    }
    return (1);
}

int is_square_of_size(char **map, int row, int col, int square_size, int nb_rows)
{
    for (int i = 0; i < square_size; i++) {
        if (row + i >= nb_rows)
            return (0);
        else if (check_line(map[row + i], col, square_size) == 0)
            return (0);
    }
    return (1);
}
