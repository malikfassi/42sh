/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:33:54 by evilsbol          #+#    #+#             */
/*   Updated: 2014/03/03 15:33:55 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>

# include "libft.h"
# include "libprt.h"
# include "libgnl.h"
# include "sh_utils.h"
# include "sh_builtins.h"

# define PROMPT "$> "
# define E_CMD	"[42sh] command not found: "
# define E_FORK "fork failed\n"

char	**sh_setenv(char	**cmd, char **envp);
char	**sh_unsetenv(char **cmd, char **envp);
void	sh_env(char **envp, char **cmd);
void	print_arr(char  **arr);

#endif /* !SHELL_H */