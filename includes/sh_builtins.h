/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:33:18 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 16:08:25 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTINS_H
# define SH_BUILTINS_H

# include <unistd.h>
# include "libft.h"
# include "sh_utils.h"

void	sh_cd(char **cmd, char **envp);
void	cd_tild(char **pwd, char **old_pwd, char **home);
int 	len_last_dir(char **pwd);

#endif /* !SH_BUILTINS_H */
