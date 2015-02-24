/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_fnct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:57:44 by scaussin          #+#    #+#             */
/*   Updated: 2013/12/27 19:57:45 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_x_va(va_list ap)
{
	return (ft_printf_x(va_arg(ap, unsigned int)));
}

int		ft_printf_xx_va(va_list ap)
{
	return (ft_printf_xx(va_arg(ap, unsigned int)));
}

int		ft_printf_d_va(va_list ap)
{
	return (ft_printf_d(va_arg(ap, int)));
}

int		ft_printf_per100_va(va_list ap)
{
	ap = ap + 0;
	return (ft_printf_c('%'));
}
