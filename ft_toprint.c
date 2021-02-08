/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:09:25 by maearly           #+#    #+#             */
/*   Updated: 2021/01/27 18:10:56 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_toprint(t_data *container, va_list *ap, int *size)
{
	if (container->type == 'c')
		ft_print_c(container, ap, size);
	else if (container->type == '%')
		ft_print_percent(container, size);
	else if (container->type == 's')
		ft_print_s(container, ap, size);
	else if (container->type == 'd' || container->type == 'i')
		ft_print_d(container, ap, size);
	else if (container->type == 'u')
		ft_print_u(container, ap, size);
	else if (container->type == 'x' || container->type == 'X')
		ft_print_x(container, ap, size);
	else if (container->type == 'p')
		ft_print_p(container, ap, size);
	else
		return (0);
	return (1);
}
