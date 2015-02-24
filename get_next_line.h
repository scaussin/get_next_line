/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:06:16 by scaussin          #+#    #+#             */
/*   Updated: 2015/02/20 10:54:09 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4096
# define FD_MAX 64

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_gnl
{
	char		buf[BUFF_SIZE];
	int			i;
	int			r;
	int			s;
}				t_gnl;

typedef struct	s_norme
{
	int			f;
	char		*n;
	int			l;
	int			t;
}				t_norme;

int				get_next_line(int const fd, char **line);
char			*ft_strndup(const char *s1, int n, int *size_line);
char			*ft_strnjoin(char *s1, char *s2, int n, int *size_line);

#endif
