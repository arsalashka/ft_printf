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

static void		ft_print_pctleft(t_data *container, int *size)
{
	*size += write(1, "%", 1);
	*size += ft_print_symbol(' ', container->width - 1);
}

static void		ft_print_pctright(t_data *container, int *size)
{
	char	filler;

	filler = container->zero ? '0' : ' ';
	*size += ft_print_symbol(filler, container->width - 1);
	*size += write(1, "%", 1);
}

void			ft_print_percent(t_data *container, int *size)
{
	if (container->minus)
		ft_print_pctleft(container, size);
	else
		ft_print_pctright(container, size);
}
