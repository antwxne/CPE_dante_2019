/*
** EPITECH PROJECT, 2020
** solver
** File description:
** load_maze
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "solveur.h"
#include "struct.h"

static char *read_maze(char const *filepath)
{
    struct stat s;
    int fd = open(filepath, O_RDONLY);
    char *buff;
    int size;

    if (fd == -1) {
        close(fd);
        return (NULL);
    }
    stat(filepath, &s);
    buff = malloc(sizeof(char) * (s.st_size + 1));
    if (buff == NULL)
        return (NULL);
    size = read(fd, buff, s.st_size);
    close(fd);
    if (size == -1)
        return (NULL);
    buff[size] = '\0';
    return (buff);
}

static unsigned int custom_len(char const *str, char const c)
{
    unsigned int count = 0;

    for (unsigned int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count += 1;
    return (count + 1);
}

static char **tab_maze(char *buff)
{
    unsigned int len = custom_len(buff, '\n');
    char **maze = malloc(sizeof(char *) * (len + 2));
    unsigned int i = 1;
    char *line;

    if (maze == NULL)
        return (NULL);
    line = strtok(buff, "\n");
    maze[0] = line;
    for (; line != NULL; i++) {
        line = strtok(NULL, "\n");
        maze[i] = line;
    }
    maze[i] = NULL;
    return (maze);
}

static pos_t get_size(char const **maze)
{
    unsigned int lines = 0;
    unsigned int cols = 0;

    if (maze == NULL)
        return ((pos_t) {0, 0});
    cols = strlen(maze[0]);
    for (; maze[lines] != NULL; lines++);
    return ((pos_t) {lines, cols});
}

int start(char const *filepath)
{
    char *buff = read_maze(filepath);
    char **maze;
    pos_t size;

    if (buff == NULL)
        return (84);
    maze = tab_maze(buff);
    if (maze == NULL) {
        free(buff);
        return (84);
    }
    size = get_size((char const **) maze);
    maze = algo(maze, size);
    display((char const **) maze);
    free(maze);
    free(buff);
    return (0);
}