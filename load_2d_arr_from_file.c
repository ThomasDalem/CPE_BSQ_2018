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

int my_put_nbr(int nb);
int my_getnbr(char const *str);
void display_map(char **map, int nb_rows, int nb_cols);

int get_tab_size(char const *buffer, int *nb_rows, int *nb_cols, int file_size)
{
    int i = 0;

    if (buffer[0] < '0' || buffer[0] > '9' || buffer == NULL) {
        write(1, "Error with file format\n", 23);
        exit(84);
    }
    while (buffer[i] >= '0' && buffer[i] <= '9' && buffer[i] != '\n')
        i++;
    *nb_rows = my_getnbr(buffer);
    *nb_cols = file_size / *nb_rows - 1;
    return (i + 2);
}

int get_file_size(char const *filepath)
{
    struct stat sb;
    int file_size = 0;

    if (stat(filepath, &sb) == -1) {
      write(1, "Error stat", 10);
      exit(84);
    }
    file_size = sb.st_size;
    return (file_size);
}

char **load_2d_arr_from_file(char const *filepath, int *nb_rows, int *nb_cols)
{
    char **arr;
    char *buffer;
    int fd = 0;
    int size = 0;
    int z = 0;
    int file_size = 0;

    fd = open(filepath, O_RDONLY);
    file_size = get_file_size(filepath);
    buffer = malloc(sizeof(char) * file_size);
    if (buffer == NULL)
        return (NULL);
    size = read(fd, buffer, file_size);
    z = get_tab_size(buffer, nb_rows, nb_cols, file_size) - 1;
    arr = malloc(sizeof(char *) * *nb_rows);
    for (int i = 0; i < *nb_rows; i++) {
        arr[i] = malloc(sizeof(char) * *nb_cols);
        if (arr[i] == NULL)
            return (NULL);
    }
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
