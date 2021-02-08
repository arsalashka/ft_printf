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

int		ft_parser(const char *format, int *size, va_list *ap)
{
	t_data		container;

	if (*format == '\0')
		return (0);
	ft_strnew(&container, sizeof(container));
	container.width = -1;
	container.precision = -1;
	ft_falgger(format, &container);
	if (!ft_width(format, &container, ap))
		return (0);
	if (!ft_prec(format, &container, ap))
		return (0);
	if (!ft_type(format, &container))
		return (0);
	if (!ft_toprint(&container, ap, size))
		return (0);
	return (container.count);
}
