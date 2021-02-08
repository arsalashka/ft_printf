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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_data
{
	int			zero;
	int			minus;
	int			width;
	int			precision;
	char		type;
	int			count;
}				t_data;

int				ft_printf(const char *format, ...);
int				ft_parser(const char *format, int *size, va_list *ap);
int				ft_isdigit(int c);
void			ft_strnew(void *s, size_t n);
void			ft_falgger(const char *format, t_data *container);
int				ft_width(const char *format, t_data *container, va_list *ap);
int				ft_prec(const char *format, t_data *container, va_list *ap);
int				ft_type(const char *format, t_data *container);
int				ft_toprint(t_data *container, va_list *ap, int *size);
void			ft_print_c(t_data *container, va_list *ap, int *size);
int				ft_print_symbol(char c, int len);
void			ft_print_percent(t_data *container, int *size);
void			ft_print_s(t_data *container, va_list *ap, int *size);
size_t			ft_strlen(const char *s);
void			ft_print_d(t_data *container, va_list *ap, int *size);
char			*ft_itoa(long int n);
void			ft_print_u(t_data *container, va_list *ap, int *size);
char			*ft_uitoa(unsigned int n);
void			ft_print_x(t_data *container, va_list *ap, int *size);
char			*ft_itox(t_data *container, unsigned int i);
void			ft_print_p(t_data *container, va_list *ap, int *size);
char			*ft_itox_p(t_data *container, unsigned long i);

#endif
