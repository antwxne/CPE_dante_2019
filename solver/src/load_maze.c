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

static inline void display(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        printf("%s\n", maze[i]);
}

static inline char *read_maze(char *filepath)
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

static inline int custom_len(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count += 1;
    return (count + 1);
}

static inline char **tab_maze(char *buff)
{
    int len = custom_len(buff, '\n');
    char **maze = malloc(sizeof(char *) * (len + 2));
    int i = 1;
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

int solving(char *filepath)
{
    char **maze;
    char *buff;

    buff = read_maze(filepath);
    if (buff == NULL)
        return (84);
    maze = tab_maze(buff);
    if (maze == NULL)
        return (84);
    display(maze);
    free(maze);
    free(buff);
    return (0);
}