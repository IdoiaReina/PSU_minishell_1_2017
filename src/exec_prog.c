/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "../include/mysh.h"

int exec_prog(char *line, char **env)
{
	char *str = get_progr(line);
	char **argv = get_arg(line);
	pid_t pid = create_process();

	if (pid == - 1) {
		perror("fork");
		return (84);
	}
	else if (pid == 0) {
		child_proc(line, env);
		prompt(env);
	}
	else {
		parent_proc(pid, env);
	}
	free(str);
	free(argv);
	return (0);
}
