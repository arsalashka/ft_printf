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

size_t		ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

void		ft_strnew(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i++] = 0;
	}
}

static int	ft_getsize(unsigned int n)
{
	int	res;

	res = 1;
	while (n >= 10)
	{
		n /= 10;
		++res;
	}
	return (res);
}

char		*ft_itoa(long int n)
{
	unsigned int	value;
	unsigned int	size;
	char			*str;

	if (n < 0)
		value = (unsigned int)(n * -1);
	else
		value = (unsigned int)n;
	size = ft_getsize(value);
	str = (char *)malloc(sizeof(char) * (n < 0 ? (size += 2) : (++size)));
	if (NULL == str)
		return (NULL);
	str[--size] = '\0';
	(n < 0) ? (str[0] = '-') : 0;
	while (value >= 10)
	{
		str[--size] = value % 10 + '0';
		value /= 10;
	}
	str[--size] = value % 10 + '0';
	return (str);
}

char		*ft_uitoa(unsigned int n)
{
	unsigned int	value;
	unsigned int	size;
	char			*str;

	if (n < 0)
		value = (unsigned int)(n * -1);
	else
		value = (unsigned int)n;
	size = ft_getsize(value);
	str = (char *)malloc(sizeof(char) * (n < 0 ? (size += 2) : (++size)));
	if (NULL == str)
		return (NULL);
	str[--size] = '\0';
	(n < 0) ? (str[0] = '-') : 0;
	while (value >= 10)
	{
		str[--size] = value % 10 + '0';
		value /= 10;
	}
	str[--size] = value % 10 + '0';
	return (str);
}
