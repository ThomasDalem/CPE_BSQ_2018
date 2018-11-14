/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** Bootstrap for BSQ
*/
#include <unistd.h>

int is_square_of_size(char **map, int row, int col, int square_size, int nb_rows);
char **load_2d_array_from_file(char const *filepath, int nb_rows, int nb_cols);
int my_put_nbr(int nb);
int my_strlen(char const *str);
void add_x(char **map, int pos_x, int pos_y, int square_size);

void display_map(char **map, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++)
        write(1, map[i], nb_rows);
}

int get_biggest_square(char **map, int pos_x, int pos_y, int nb_rows)
{
    int square_size = 1;

    while (is_square_of_size(map, pos_x, pos_y, square_size, nb_rows) == 1)
        square_size++;
    return (square_size - 1);
}

int find_biggest_square(char **map, int nb_rows, int nb_cols)
{
    int biggest_square_size = 0;
    int biggest_square_pos_x = 0;
    int biggest_square_pos_y = 0;
    int square_size = 0;

    for (int y = 0; y < nb_rows; y++) {
        for (int i = 0; i < nb_cols; i++) {
            square_size = get_biggest_square(map, y, i, nb_rows);
            if (square_size > biggest_square_size) {
                biggest_square_size = square_size;
                biggest_square_pos_x = i;
                biggest_square_pos_y = y;
            }
        }
    }
    add_x(map, biggest_square_pos_y, biggest_square_pos_x, biggest_square_size);
    display_map(map, nb_rows, nb_cols);
    return (biggest_square_size);
}
