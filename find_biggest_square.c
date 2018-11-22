/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** Finds the biggest square
*/
#include <stdlib.h>
#include <unistd.h>

int is_sqr_of_size(char **map, int row, int col, int square_size, int nb_rows);
char **load_2d_array_from_file(char const *filepath, int nb_rows, int nb_cols);
int my_put_nbr(int nb);
void add_x(char **map, int pos_x, int pos_y, int square_size);

void display_map(char **map, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++) {
        write(1, map[i], nb_cols);
        write(1, "\n", 1);
    }
}

int get_biggest_square(char **map, int pos_x, int pos_y, int nb_rows)
{
    int square_size = 1;

    while (is_sqr_of_size(map, pos_x, pos_y, square_size, nb_rows) == 1)
    return (square_size - 1);
}

void find_biggest_square(char **map, int nb_rows, int nb_cols)
{
    int biggest_square_size = 0;
    int biggest_square_col = 0;
    int biggest_square_row = 0;
    int square_size = 0;

    for (int y = 0; y < nb_rows; y++) {
        for (int i = 0; i < nb_cols; i++) {
            square_size = get_biggest_square(map, y, i, nb_rows);
            if (square_size > biggest_square_size) {
                biggest_square_size = square_size;
                biggest_square_col = i;
                biggest_square_row = y;
            }
        }
    }
    add_x(map, biggest_square_row, biggest_square_col, biggest_square_size);
    display_map(map, nb_rows, nb_cols);
}
