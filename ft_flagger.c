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

void	ft_falgger(const char *format, t_data *container)
{
	while (format[container->count] == '-' || format[container->count] == '0')
	{
		if (format[container->count++] == '-')
		{
			container->minus = 1;
			container->zero = 0;
		}
		else if (!container->minus)
			container->zero = 1;
	}
}
