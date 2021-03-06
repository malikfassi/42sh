/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 14:28:22 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 16:10:26 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "libprt.h"
# include "libft.h"

char	**find(char **src, char *to_find);
int		findi(char **src, char *to_find);
int		len_arr(char **arr);
char	*ft_strtoupper(char *str);
char	*ft_strnjoin(char const *s1, char const *s2, size_t len_s2);
void	free_arr(char ***arr);
char	*reduce_one_slash_front(char *cmd);
char	*search_path(char **paths, char *cmd);

#endif /* !UTILS_H */
