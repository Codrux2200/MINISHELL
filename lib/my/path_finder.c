/*
** EPITECH PROJECT, 2021
** B-PSU-101-TLS-1-1-minishell1-saad.berrada-master
** File description:
** path_finder
*/
#include "my.h"

int path_finder(char **envp, char *nbr, int i)
{
    int fd = -1;
    int index = 0;

    while (fd == -1){
        if (str_to_world_array2(envp[i])[index] != NULL){
            fd = open(my_strcat(str_to_world_array2(envp[i])[index], nbr),
            O_RDONLY);
            index++;
        } else {
            for (int i = 0; nbr[i] != '\0'; i++, write(2, &nbr[i], 1));
            write(2, " : error command not found\n", 28);
            return 84;
        }
    }
    return (index);
}