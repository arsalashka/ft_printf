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

void	ft_atoi_width(const char *format, t_data *container)
{
	int		i;
	int		morethan_int;

	morethan_int = 0;
	if (ft_isdigit(format[container->count]))
		i = 0;
	else
		i = -1;
	while (ft_isdigit(format[container->count]))
	{
		if (i > INT32_MAX / 10 || (i == INT32_MAX / 10 &&
												format[container->count] > '7'))
			morethan_int = 1;
		i = i * 10 + format[container->count++] - '0';
	}
	if (morethan_int)
		container->width = INT32_MAX;
	else
		container->width = i;
}

int		ft_width(const char *format, t_data *container, va_list *ap)
{
	if (format[container->count] == '*')
	{
		container->width = va_arg(*ap, int);
		if (container->width < 0)
		{
			container->minus = 1;
			container->zero = 0;
			container->width = container->width * -1;
		}
		container->count++;
	}
	else
		ft_atoi_width(format, container);
	if (container->width == INT32_MAX || container->width == INT32_MIN)
		return (0);
	return (1);
}
