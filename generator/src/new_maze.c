/*
** EPITECH PROJECT, 2020
** generator
** File description:
** new_maze
*/

#include <stdlib.h>
#include <stdio.h>

void display_maze(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        printf("%s\n", maze[i]);
}

char *line_fil(int l)
{
    char *dest = malloc(sizeof(char)*(l + 1));
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; i < l; i++)
        dest[i] = 'X';
    dest[i] = '\0';
    return (dest);
}

char *line1(int l)
{
    char *dest = malloc(sizeof(char)*(l + 1));
    int i = 0;

    // printf("1======>>>>\n");
    if (dest == NULL)
        return (NULL);
    for (; i < l; i++) {
        if ((i % 2) == 1)
            dest[i] = 'X';
        else
            dest[i] = '*';
    }
    dest[i] = 0;
    return (dest);
}

char **new_maze(int l, int h)
{
    char **maze = malloc(sizeof(char *)*(h + 1));
    int i = 0;

    if (maze == NULL)
        return (NULL);
    for (; i < h; i++) {
        if ((i % 2) == 1)
            maze[i] = line_fil(l);
        else
            maze[i] = line1(l);
        // printf("caca ===>> %s\n", maze[i]);
    }
    maze[i - 1][strlen(maze[i - 1]) - 1] = '*';
    maze[i] = NULL;
    return (maze);
}

int main(int ac, char **av)
{
    char **maze;

    if (ac != 3)
        return (84);
    maze = new_maze(atoi(av[1]), atoi(av[2]));
    display_maze(maze);
    return (0);
}
