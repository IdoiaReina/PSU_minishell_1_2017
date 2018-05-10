/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** main
*/

#include "../include/mysh.h"

int compare_str(char *str1, char *str2, int nb)
{
	int i = 0;

	while (i < nb) {
		if (str1[i] != str2[i])
			return (1);
		i += 1;
	}
	return (0);
}

int get_where_untill_path(char **env, int j, int i)
{
	while (env[i][j] != '\0')
		j += 1;
	return (j);
}

char *get_where(char **env)
{
	char *pwd = "PWD=";
	int i = 0;
	int j = 0;
	int k = 0;
	char *str = malloc (sizeof(char) * my_strlen(env[2]));

	while (compare_str(pwd, env[i], my_strlen(pwd)) != 0) {
		if (compare_str(pwd, env[i], my_strlen(pwd)) != 0)
			i += 1;
	}
	j = get_where_untill_path(env, j, i);
	while (env[i][j - 1] != '/')
		j -= 1;
	while (env[i][j] != '\0') {
		str[k] = env[i][j];
		j += 1;
		k += 1;
	}
	str[k] = '\0';
	return (str);
}

void prompt(char **env)
{
	char *pwd = get_where(env);

	my_putstr("[!A!][");
	my_putstr(pwd);
	my_putstr("]> ");
	free(pwd);
}

int main(int ac, char **av, char **env)
{
	prompt(env);
	get_the_line(ac, av, env);
}
