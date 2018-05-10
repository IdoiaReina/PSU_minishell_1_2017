/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** getline
*/

#include "../include/mysh.h"

int verif_string(char *one, char *two)
{
	int i = 0;
	int len_one = my_strlen(one);
	int len_two = my_strlen(two);

	if (len_one != len_two)
		return (1);
	while (one[i] != '\0') {
		if (two[i] != one[i])
			return (1);
		i += 1;
	}
	return (0);
}

char *get_the_line(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1) {
		if (verif_string(line, "exit\n") == 0)
			exit(0);
		if (line[0] == '\n') {
			prompt(env);
			get_the_line(ac, av, env);
		}
		else
			exec_prog(line, env);
	}
	return (line);
}
