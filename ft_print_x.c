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

static void	ft_print_xleft(t_data *container, char *str, int *size)
{
	int		printed;
	int		len;

	printed = 0;
	len = ft_strlen(str);
	printed = container->precision > len ? container->precision : len;
	*size += ft_print_symbol('0', container->precision - len);
	*size += write(1, str, len);
	*size += ft_print_symbol(' ', container->width - printed);
}

static void	ft_print_xright(t_data *container, char *str, int *size)
{
	int printed;
	int filler;
	int len;

	printed = 0;
	len = ft_strlen(str);
	container->zero = container->precision == -1 ? container->zero : 0;
	filler = container->zero ? '0' : ' ';
	printed = container->precision > len ? container->precision : len;
	*size += ft_print_symbol(filler, container->width - printed);
	*size += ft_print_symbol('0', container->precision - len);
	*size += write(1, str, len);
}

void		ft_print_x(t_data *container, va_list *ap, int *size)
{
	unsigned int	i;
	char			*str;

	i = va_arg(*ap, unsigned int);
	str = ft_itox(container, i);
	if (i == 0 && container->precision == 0)
		str[0] = '\0';
	if (container->minus)
		ft_print_xleft(container, str, size);
	else
		ft_print_xright(container, str, size);
	free(str);
}
