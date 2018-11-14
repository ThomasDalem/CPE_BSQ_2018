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
#include <stdio.h>

int my_put_nbr(int nb);
int my_getnbr(char const *str);

int get_first_line_nbr(char const *filepath, int fd)
{
    char buffer[100];
    int nb_rows = 0;

    read(fd, buffer, 100);
    nb_rows = my_getnbr(buffer);
    return (nb_rows);
}

int get_file_size(char const *filepath, int fd, int *nb_rows, int *nb_cols)
{
    struct stat sb;
    int file_size = 0;

    *nb_rows = get_first_line_nbr(filepath, fd);
    if (stat(filepath, &sb) == -1) {
        write(1, "Error stat", 10);
        exit(84);
    }
    file_size = sb.st_size;
    *nb_cols = file_size / *nb_rows - 1;
    my_put_nbr(*nb_rows);
    write(1, "\n", 1);
    my_put_nbr(*nb_cols);
    return (*nb_rows);
}

char **load_2d_arr_from_file(char const *filepath, int *nb_rows, int *nb_cols)
{
    char **arr;
    char *buffer;
    int fd = 0;
    int size = 0;
    int z = 0;

    fd = open(filepath, O_RDONLY);
    if (fd <= 0)
        write(1, "Error ", 7);
    get_file_size(filepath, fd, nb_rows, nb_cols);
    arr = malloc(sizeof(char *) * *nb_rows);
    buffer = malloc(sizeof(char) * *nb_cols * *nb_rows + *nb_cols);
    for (int i = 0; i < *nb_rows; i++)
        arr[i] = malloc(sizeof(char) * *nb_cols);
    size = read(fd, buffer, *nb_cols * *nb_rows + *nb_cols);
    for (int i = 0; i < *nb_rows; i++) {
        for (int y = 0; y < *nb_cols; y++) {
            arr[i][y] = buffer[z];
            z++;
        }
        z++;
    }
    close(fd);
    free(buffer);
    return (arr);
}
