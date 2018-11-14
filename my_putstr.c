/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Prints one by one the characters of a string
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
