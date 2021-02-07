/*
** EPITECH PROJECT, 2021
** MiniShell
** File description:
** dir
*/
#include "my.h"

int dir(char *path)
{
    char *dir_str = malloc((my_strlen(path) - 3) * sizeof(char *));
    DIR *folder;
    struct dirent *entry;

    for (int i = 3; path[i] != '\0'; i++)
        dir_str[i - 3] = path[i];
    folder = opendir(dir_str);
    if(folder == NULL){
        write (2, "Unable to read directory\n", 26);
        return(84);
    } else
        chdir (dir_str);
    closedir (folder);
    return 0;
}

int cd_valid(char *stream, int size)
{
    if (size >= 4){
        if(stream[0] == 'c' && stream[1] == 'd' && stream[2] == ' ')
            return (dir(stream));
        else
            return 1;
    }
    return 1;
}

int h_m_s(char *space)
{
    int i;
    for (i = 0; space[i] != '\0'; i++){
        if (space[i] != ' ')
            return i;
    }
}

char *create_stream_clean(char *stream)
{
    char *stream_clean = malloc(120 * sizeof(char *));

    for (int i = 0, n = 0; stream[i] != '\0'; i++){
        if (stream[i] != '\n'){
            stream_clean[n] = stream[i];
            n++;
        }
    }
    return stream_clean;
}

int exit_c(char *str, int read)
{
    char exit[4] = "exit";
    if (read == -1){
        if (isatty(0) == 1)
            my_putstr("exit\n");
        return 1;
    }
    if (my_strlen(exit) == my_strlen(str)) {
        for (int i = 0; i != 4; i++){
            if (str[i] != exit[i])
                return 0;
        }
        return 1;
    } else
        return 0;
}