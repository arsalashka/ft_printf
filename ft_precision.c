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

void	ft_atoi_precision(const char *format, t_data *container)
{
	int	morethan_int;
	int i;

	morethan_int = 0;
	i = 0;
	while (ft_isdigit(format[container->count]))
	{
		if (i > INT32_MAX / 10 ||
						(i == INT32_MAX / 10 && format[container->count] > '7'))
			morethan_int = 1;
		i = i * 10 + format[container->count++] - '0';
	}
	if (morethan_int)
		container->precision = INT32_MAX;
	else
		container->precision = i;
}

int		ft_prec(const char *format, t_data *container, va_list *ap)
{
	if (format[container->count] != '.')
		return (1);
	++container->count;
	container->precision = 0;
	if (format[container->count] == '*')
	{
		container->precision = va_arg(*ap, int);
		container->count++;
	}
	else
		ft_atoi_precision(format, container);
	if (container->precision < 0)
		container->precision = -1;
	if (container->precision == INT32_MAX)
		return (0);
	return (1);
}
