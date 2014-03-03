/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 17:14:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/27 19:19:59 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "sh_utils.h"

char	**sh_unsetenv(char **cmd, char **envp)
{
	char	**field;
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	if (len_arr(cmd) != 2)
		ft_putstr("Usage : unsetenv <enVar1>\n");
	if (!*(field = find(envp, cmd[1])) || len_arr(cmd) != 2)
		return (envp);
	tmp = (char **)ft_memalloc(sizeof(char *) * (len_arr(envp)));
	while (i < len_arr(envp))
	{
		cmd[1] = ft_strtoupper(cmd[1]);
		if (ft_strncmp(cmd[1], envp[i], ft_strlen(cmd[1])))
		{
			tmp[j] = envp[i];
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	return (tmp);
}
