/*
** EPITECH PROJECT, 2021
** MiniShell
** File description:
** main
*/
#include "./lib/my/my.h"

int main(int ac, char **av, char **env)
{
    size_t lenth = 14;
    char *stream = malloc(120 * sizeof(char *));
    char *stream_clean = NULL;
    int cd = 0;

    mysh(stream, stream_clean, lenth, env);
    return 0;
}

void mysh(char *stream, char *stream_clean, size_t lenth, char **env)
{
    int read = 0;

    while(1){
        if (isatty(0) == 1)
            write(1, "$> ", 4);
        read = getline(&stream, &lenth, stdin);
        if (my_strlen(stream) == (h_m_s(stream) + 1))
            stream[0] = '{';
        stream_clean = create_stream_clean(stream);
        if (exit_c(cleaner(stream_clean), read) == 1)
            break;
        else if (cleaner(stream_clean)[0] == '.'
        && cleaner(stream_clean)[1] == '/' )
            program_exect(env , str_to_world_array(cleaner(stream_clean)));
        else if (cd_valid(cleaner(stream_clean), read) == 1
        && stream_clean[0] != '{' && my_strlen(stream) != 1)
            chr(env, str_to_world_array(cleaner(stream_clean)));
        free(stream_clean);
    }
}

int program_exect(char **env, char **foo)
{
    int pid = fork();

    if (pid == 0){
        int red = execve(foo[0], foo, env);
        if (red == -1){
            my_putstr_err("bash: ");
            my_putstr_err(foo[0]);
            my_putstr_err(": No file or folder of this type\n");
        }
    } else
        wait(NULL);
}

int chr(char **envp, char **foo)
{
    int index = 0;
    int ret;
    int i = 0;
    int impl = 0;
    char *nbr = malloc((my_strlen(foo[0]) + 3) * sizeof(char *));
    int pid;

    nbr[0] = '/';
    for (impl = 1; foo[0][impl - 1] != '\0'; impl++)
        nbr[impl] = foo[0][impl - 1];
    nbr[impl] = '\0';
    for (i = 0; envp[i] != NULL; i++){
      if (envp[i][0] == 'P' &&
      envp[i][1] == 'A' && envp[i][2] == 'T')
          break;
    }
    index = path_finder(envp, nbr, i);
    if (index != -1)
        index --;
    exect(envp, i, index, nbr, foo);
}

int exect(char **envp, int i, int index, char *nbr, char **foo)
{
    int pid = fork();
    int ret;

    if (pid == 0){
        if (index != -1){
            ret = execve(my_strcat(str_to_world_array2(envp[i])[index], nbr),
            foo, envp);
            free(nbr);
            free(foo);
            return 0;
        } else
            return 84;
    } else
        wait (NULL);
}