/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:56:30 by scaussin          #+#    #+#             */
/*   Updated: 2013/12/28 10:52:50 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;

	ret = 0;
	va_start(ap, str);
	ret = ft_manage((char *)str, ap);
	va_end(ap);
	return (ret);
}

t_fct	*ft_init_fun_tab(void)
{
	t_fct		*tab;

	tab = (t_fct *)malloc(sizeof(t_fct) * SIZE_TAB_FNCT);
	tab[0].c = 'd';
	tab[1].c = 'i';
	tab[2].c = 'u';
	tab[3].c = 'o';
	tab[4].c = 's';
	tab[5].c = 'c';
	tab[6].c = 'x';
	tab[7].c = 'p';
	tab[8].c = 'X';
	tab[9].c = '%';
	tab[0].fnct = ft_printf_d_va;
	tab[1].fnct = ft_printf_d_va;
	tab[2].fnct = ft_printf_u_va;
	tab[3].fnct = ft_printf_o_va;
	tab[4].fnct = ft_printf_s_va;
	tab[5].fnct = ft_printf_c_va;
	tab[6].fnct = ft_printf_x_va;
	tab[7].fnct = ft_printf_p_va;
	tab[8].fnct = ft_printf_xx_va;
	tab[9].fnct = ft_printf_per100_va;
	return (tab);
}

int		ft_manage(char *str, va_list ap)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret = ft_match_fnct(str[i + 1], ap) + ret;
			i = i + 2;
		}
		if (str[i] != '\0' && str[i] != '%')
		{
			ft_putchar(str[i]);
			ret++;
			i++;
		}
	}
	return (ret);
}

int		ft_match_fnct(char c, va_list ap)
{
	t_fct	*tab_fnct;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	tab_fnct = ft_init_fun_tab();
	while (i < SIZE_TAB_FNCT && tab_fnct[i].c != c)
		i++;
	if (i < SIZE_TAB_FNCT)
		ret = tab_fnct[i].fnct(ap);
	else
	{
		ft_putchar(c);
		ret++;
	}
	return (ret);
}
