/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:16:18 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/12/30 15:50:45 by fmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*ret;

	count = 0;
	ret = NULL;
	if ((char) c == '\0')
	{
		return ((char *) (s + ft_strlen(s)));
	}
	while (*(s + count) != '\0')
	{
		if (*(s + count) == (char) c)
		{
			ret = (char *) (s + count);
		}
		count++;
	}
	return (ret);
}
