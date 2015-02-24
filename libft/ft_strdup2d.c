/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:31:41 by scaussin          #+#    #+#             */
/*   Updated: 2013/12/26 11:32:28 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup2d(char **dest, char **src)
{
	int		i;

	i = 0;
	if (src)
	{
		while (src[i])
			i++;
		dest = (char **)malloc((sizeof(char *) * i) + 1);
		if (dest == NULL)
			ft_putendl_fd("Malloc env fail", 2);
		i = 0;
		while (src[i])
		{
			dest[i] = ft_strdup(src[i]);
			i++;
		}
		return (dest);
	}
	return (NULL);
}
