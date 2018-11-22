/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** Find the biggest square possible in a map
*/
#include <unistd.h>

char **load_2d_arr_from_file(char const *filepath, int *nb_rows, int *nb_cols);
int is_square_of_size(char **map, int row, int col, int square_size);
int find_biggest_square(char **map, int nb_rows, int nb_cols);

int main(int ac, char **av)
{
    int nb_cols = 0;
    int nb_rows = 0;
    char **map;

    if (ac != 2) {
        write(1, "Wrong number of arguments\n", 26);
        write(1, "Usage : /bsq <directory/map.txt>\n", 34);
        return (84);
    }
    map = load_2d_arr_from_file(av[1], &nb_rows, &nb_cols);
    find_biggest_square(map, nb_rows, nb_cols);
    return (0);
}
