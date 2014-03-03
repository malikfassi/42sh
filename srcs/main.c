/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 19:31:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 16:29:37 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell.h"

static void	print_prompt(char **envp)
{
	char	*path;

	path = *find(envp, "PWD=") + 4;
	ft_printf(BLUE "(%s) %s" RESET, path, PROMPT);
	// ft_putstr("\x1B[37m(\x1B[0m");
	// ft_putstr("\x1B[36m");
	// ft_putstr(path);
	// ft_putstr("\x1B[0m");
	// ft_putstr("\x1B[37m)\x1B[0m");
	// ft_putstr("\x1B[31m$>\x1B[0m");
}

static char	*get_path(char **envp, char **cmd)
{
	char	**paths;
	char	*part_path;
	char	*path;

	paths = ft_strsplit(envp[0] + 5, ':');
	part_path = ft_strjoin(search_path(paths, cmd[0]), "/");
	path = ft_strjoin(part_path, cmd[0]);
	ft_strdel(&part_path);
	free_arr(&paths);
	return (path);
}

static char	**get_cmd(void)
{
	char	*line;
	char	**cmd;

	line = get_line();
	if (ft_strlen(line) == 0)
	{
		ft_strdel(&line);
		return (NULL);
	}
	cmd = ft_strsplit(line, ' ');
	ft_strdel(&line);
	return (cmd);
}

static int		implemented_function(char **cmd, char ***envp)
{
	if (!cmd)
		return (1);
	if (ft_strcmp(cmd[0], "exit") == 0)
	{
		free_arr(&cmd);
		return (-1);
	}
	else if (ft_strcmp(cmd[0], "env") == 0)
		sh_env(*envp, cmd);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		sh_cd(cmd, *envp);
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		*envp = sh_setenv(cmd, *envp);
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		*envp = sh_unsetenv(cmd, *envp);
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv, char **envp)
{
	char	**cmd;
	pid_t	pid;
	int		ret;

	while (argc == 1 && argv)
	{
		print_prompt(envp);
		cmd = get_cmd();
		ret = implemented_function(cmd, &envp);
		if (ret == -1)
			exit(0);
		else if (ret == 1)
			continue ;
		pid = fork();
		if (pid == 0 && execve(get_path(envp, cmd), cmd, envp) == -1)
			ft_quit(E_CMD, cmd[0]);
		if (pid < 0)
			ft_putstr(E_FORK);
		wait(0);
	}
	return (0);
}
