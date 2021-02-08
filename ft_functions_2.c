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

int			ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

static int	ft_xlen(unsigned long i)
{
	int xlen;

	xlen = 1;
	while ((i /= 16))
		++xlen;
	return (xlen);
}

char		*ft_itox(t_data *container, unsigned int i)
{
	char	*str;
	char	*alpha;
	int		xlen;

	xlen = ft_xlen(i);
	alpha = container->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (!(str = (char *)malloc(sizeof(char) * xlen + 1)))
		return (NULL);
	str[xlen--] = '\0';
	while (xlen >= 0)
	{
		str[xlen--] = alpha[i % 16];
		i /= 16;
	}
	return (str);
}

char		*ft_itox_p(t_data *container, unsigned long i)
{
	char	*str;
	char	*alpha;
	int		xlen;

	xlen = ft_xlen(i);
	alpha = container->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (!(str = (char *)malloc(sizeof(char) * xlen + 1)))
		return (NULL);
	str[xlen--] = '\0';
	while (xlen >= 0)
	{
		str[xlen--] = alpha[i % 16];
		i /= 16;
	}
	return (str);
}
