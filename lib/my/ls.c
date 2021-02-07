/*
** EPITECH PROJECT, 2021
** MiniShell
** File description:
** ls
*/
#include "my.h"

char *cleaner(char *str)
{
    int r;
    int s = 0;
    int v;
    char *clean_str = malloc(my_strlen(str) * sizeof(char *));

    for (r = 0; str[r] == ' '; r++);
    for (v = my_strlen(str); str[v] == ' '; v--);
    if (str[v - 1] == ' ')  v--;
    for (int i = r; i != (v);) {
        if (str[i] == '\n')
            i++;
        if (str[i] == ' ' && str[i + 1] == ' ') i++;
        else {
            clean_str[s] = str[i];
            i++;
            s++;
        }
    }
    clean_str[s] = '\0';
    return (clean_str);
}

char **str_to_world_array(char *str)
{
    int s = 0;
    char **tab = malloc((my_strlen(str) + 1) * sizeof(char **));
    char *str_cat = malloc(my_strlen(str) * sizeof(char *));

    for (int i = 0, n = 0; i <= my_strlen(str); i++){
        if (str[i] == ' ' || str[i] == '\0'){
            tab[s] = str_cat;
            str_cat = malloc(my_strlen(str) * sizeof(char *));
            s++;
            n = 0;
        } else {
            str_cat[n] = str[i];
            n++;
        }
    }
    return tab;
}

int my_strcmp(char *str, char *str2)
{
    if (my_strlen(str) == my_strlen(str2)){
        for (int i = 0; str[i] != '\0'; i++){
            if (str[i] != str2[i])
                return 0;
        }
        return 1;
    } else
        return 0;
}

char **str_to_world_array2(char *str)
{
    int s = 0;
    int index = 0;
    char **tab = malloc((my_strlen(str) + 1) * sizeof(char **));
    char *str_cat = malloc(my_strlen(str) * sizeof(char *));

    for (index = 0; str[index] != '/'; index++);
    for (int i = index, n = 0; i <= my_strlen(str); i++){
        if (str[i] == ':' || str[i] == '\0'){
            str_cat[n] = '\0';
            tab[s] = str_cat;
            str_cat = malloc(my_strlen(str) * sizeof(char *));
            s++;
            n = 0;
        } else {
            str_cat[n] = str[i];
            n++;
        }
    }
    tab[s] = NULL;
    free(str_cat);
    return tab;
}

char *my_strcat(char *str1, char *str2)
{
    char *rendu = malloc((my_strlen(str1) + my_strlen(str2)) * sizeof(char *));
    int index;
    rendu = str1;
    for (index = 0; rendu[index] != '\0'; index++);
    for (int i = 0; i <= my_strlen(str2); i++){
        rendu[i + index] = str2[i];
    }
    return rendu;
}

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
