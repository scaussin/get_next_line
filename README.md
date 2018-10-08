| Language | Field           | Project | Grade |
| :------: |:---------------:| :------:|:-----:|
| C      | UNIX | Solo     |113/125|

# get_next_line()
The challenge of this program is to implement get_next_line() as optimized and short as possible.
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 09:17:32 by scaussin          #+#    #+#             */
/*   Updated: 2015/02/19 15:26:09 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd_const, char **line)
{
	static	t_gnl	gnl[FD_MAX] = {{{0}, 0, 0, 0}};
	t_norme			n;

	if (!(n.n = NULL) && (!line || fd_const < 0))
		return (-1);
	n.f = fd_const % FD_MAX;
	*line = NULL;
	while (!n.n)
	{
		if (gnl[n.f].i == gnl[n.f].r && !(gnl[n.f].i = 0))
		{
			if ((gnl[n.f].r = read(fd_const, gnl[n.f].buf, BUFF_SIZE)) <= 0)
			{
				n.t = gnl[n.f].r;
				gnl[n.f].r = 0;
				return (*line ? 1 : n.t);
			}
		}
		n.n = ft_memchr(&gnl[n.f].buf[gnl[n.f].i], 10, gnl[n.f].r - gnl[n.f].i);
		n.l = (n.n) ? n.n - &gnl[n.f].buf[gnl[n.f].i] : gnl[n.f].r - gnl[n.f].i;
		*line = (*line) ? ft_strnjoin(*line, &gnl[n.f].buf[gnl[n.f].i], n.l,
		&gnl[n.f].s) : ft_strndup(&gnl[n.f].buf[gnl[n.f].i], n.l, &gnl[n.f].s);
		gnl[n.f].i = (n.n) ? gnl[n.f].i + n.l + 1 : gnl[n.f].r;
	}
	return (1);
}
```
