/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "../include/mysh.h"

char *get_progr(char *line)
{
	char *str = malloc(sizeof(char) * 1000);
	char bin[] = "/bin/";
	int i = 0;
	int j = 0;

	while (bin[i] != '\0') {
		str[i] = bin[i];
		i += 1;
	}
	while (line[j] != ' ' && line[j] != '\0' && line[j] != '\n') {
		str[i] = line[j];
		i += 1;
		j += 1;
	}
	str[i] = '\0';
	return (str);
}

char **get_arg(char *line)
{
	char **arg = malloc(sizeof(char *) * my_strlen(line));
	int i = 0;
	int x = 0;
	int y = 1;

	while (line[i] != '\0') {
		arg[y] = malloc(sizeof(char) * my_strlen(line));
		x = 0;
		while (line[i] != ' ' && line[i] != '\0' && line[i] != '\n') {
			arg[y][x] = line[i];
			i += 1;
			x += 1;
		}
		arg[y][x] = '\0';
		i += 1;
		y += 1;
	}
	arg[y] = 0;
	return (arg);
}

pid_t create_process(void)
{
	pid_t pid;

	pid = fork();
	return (pid);
}

int child_proc(char *line, char **env)
{
	char *str = get_progr(line);
	char **av = get_arg(line);

	av += 1;
	if (execve(str, av, env) == -1) {
		return (84);
	}
	return (0);
}

void parent_proc(pid_t pid, char **env)
{
	int wstatus = 0;

	waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
	prompt(env);
}
