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

static void	ft_print_pleft(t_data *container, char *str, int *size)
{
	int	printed;
	int	len;

	len = ft_strlen(str);
	printed = container->precision > len ? container->precision + 2 : len + 2;
	*size += write(1, "0x", 2);
	*size += ft_print_symbol('0', container->precision - len);
	*size += write(1, str, len);
	*size += ft_print_symbol(' ', container->width - printed);
}

static void	ft_print_pright(t_data *container, char *str, int *size)
{
	int	printed;
	int	len;

	len = ft_strlen(str);
	printed = container->precision > len ? container->precision + 2 : len + 2;
	container->zero = container->precision == -1 ? container->zero : 0;
	if (!container->zero)
		*size += ft_print_symbol(' ', container->width - printed);
	*size += write(1, "0x", 2);
	if (container->zero)
		*size += ft_print_symbol('0', container->width - printed);
	*size += ft_print_symbol('0', container->precision - len);
	*size += write(1, str, len);
}

void		ft_print_p(t_data *container, va_list *ap, int *size)
{
	unsigned long	i;
	char			*str;

	i = (unsigned long)va_arg(*ap, void *);
	str = ft_itox_p(container, i);
	if (i == 0 && container->precision == 0)
		str[0] = '\0';
	if (container->minus)
		ft_print_pleft(container, str, size);
	else
		ft_print_pright(container, str, size);
	free(str);
}
