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

static void	ft_print_sleft(t_data *container, char *str, int *size)
{
	int		len;

	len = ft_strlen(str);
	if (container->precision >= 0 && container->precision < len)
		len = container->precision;
	*size += write(1, str, len);
	*size += ft_print_symbol(' ', container->width - len);
}

static void	ft_print_sright(t_data *container, char *str, int *size)
{
	char	filler;
	int		len;

	len = ft_strlen(str);
	filler = container->minus ? '0' : ' ';
	if (container->precision >= 0 && container->precision < len)
		len = container->precision;
	*size += ft_print_symbol(filler, container->width - len);
	*size += write(1, str, len);
}

void		ft_print_s(t_data *container, va_list *ap, int *size)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	if (container->minus)
		ft_print_sleft(container, str, size);
	else
		ft_print_sright(container, str, size);
}
