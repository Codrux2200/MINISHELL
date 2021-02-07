/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
typedef struct chiffre chiffre;
struct chiffre{
    int chiffre;
    int st_block;
};
void total_calcul(char *str, chiffre *chiffre);
char *ctime_format(char *str);
void print(chiffre *chiffre);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char *str);
void add(int ac, char **av);
char *str_concat(char *str1, char *str2);
void R_flag(char *str);
int classic2(char *dir);
int classic(char *dir);
void l_flag(char *str);
void suite(char *str, chiffre *chiffre);
void sb_space(char *str, chiffre *chiffre);
int intlen(int nbr);
void stat_recup(char *str, int dir, chiffre *chiffre);
void my_ls(int ac, char **av);
int dir(char *path);
int my_putstr_err(char const *str);
int cd_valid(char *stream, int size);
int exit_c(char *str, int read);
int ls_valid(char *stream, char **env);
char  *cleaner(char *str);
char **str_to_world_array(char *str);
int chr(char **envp, char **foo);
void mysh(char *stream, char *stream_clean, size_t lenth, char **env);
int h_m_s(char *space);
int program_exect(char **env, char **foo);
char *create_stream_clean(char *stream);
char **str_to_world_array2(char *str);
char *my_strcat(char *str1, char *str2);
int exect(char **envp, int i, int index, char *nbr, char **foo);
int path_finder(char **envp, char *nbr, int i);
#endif /* !MY_H_ */
