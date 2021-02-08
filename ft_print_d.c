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

static void	ft_print_dleft(t_data *container, char *str, int *size, int sign)
{
	int		printed;
	int		len;

	printed = 0;
	len = ft_strlen(str);
	if (container->precision > len)
		printed = container->precision;
	else
		printed = len;
	if (sign == -1)
	{
		*size += write(1, "-", 1);
		printed++;
	}
	*size += ft_print_symbol('0', container->precision - len);
	*size += write(1, str, len);
	*size += ft_print_symbol(' ', container->width - printed);
}

static void	ft_print_dright(t_data *container, char *str, int *size, int sign)
{
	int		printed;
	int		len;

	printed = 0;
	len = ft_strlen(str);
	container->zero = container->precision == -1 ? container->zero : 0;
	printed = container->precision > len ? container->precision : len;
	printed = sign == -1 ? printed + 1 : printed;
	if (container->zero)
	{
		if (sign == -1)
			*size += write(1, "-", 1);
		*size += ft_print_symbol('0', container->width - printed);
	}
	else
	{
		*size += ft_print_symbol(' ', container->width - printed);
		if (sign == -1)
			*size += write(1, "-", 1);
	}
	*size += ft_print_symbol('0', container->precision - len);
	*size += write(1, str, len);
}

void		ft_print_d(t_data *container, va_list *ap, int *size)
{
	long int		i;
	char			*str;
	int				sign;

	i = va_arg(*ap, int);
	if (i < 0)
	{
		sign = -1;
		i *= -1;
	}
	else
		sign = 1;
	str = ft_itoa(i);
	if (i == 0 && container->precision == 0)
		str[0] = '\0';
	if (container->minus)
		ft_print_dleft(container, str, size, sign);
	else
		ft_print_dright(container, str, size, sign);
	free(str);
}
