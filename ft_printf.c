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

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			size;
	int			count;
	int			var;

	size = 0;
	count = 0;
	va_start(ap, format);
	while (format[count] != '\0')
	{
		if (format[count] != '%')
			size += write(1, &format[count++], 1);
		else
		{
			if (!(var = ft_parser(&format[++count], &size, &ap)))
				return (-1);
			count += var;
		}
	}
	va_end(ap);
	return (size);
}
