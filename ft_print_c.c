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

static void	ft_print_cleft(t_data *container, char c, int *size)
{
	*size += write(1, &c, 1);
	*size += ft_print_symbol(' ', container->width - 1);
}

static void	ft_print_cright(t_data *container, char c, int *size)
{
	char	filler;

	if (container->zero)
		filler = '0';
	else
		filler = ' ';
	*size += ft_print_symbol(filler, container->width - 1);
	*size += write(1, &c, 1);
}

void		ft_print_c(t_data *container, va_list *ap, int *size)
{
	char	c;

	c = va_arg(*ap, int);
	if (container->minus)
		ft_print_cleft(container, c, size);
	else
		ft_print_cright(container, c, size);
}
