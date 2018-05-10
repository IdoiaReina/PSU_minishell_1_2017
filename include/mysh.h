/*
** EPITECH PROJECT, 2018
** .h
** File description:
** .H
*/


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int my_strlen(char const *str);
char *get_next_line(int fd);
void my_putstr(char *str);
char *get_the_line(int ac, char **av, char **env);
int main(int ac, char **av, char **env);
char *get_progr(char *line);
char **get_arg(char *line);
int exec_prog(char *line, char **env);
char *get_where(char **env);
void prompt(char **env);
pid_t create_process(void);
int child_proc(char *line, char **env);
void parent_proc(pid_t pid, char **env);