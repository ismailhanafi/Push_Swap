/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-sofy <hes-sofy>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:18:55 by hes-sofy          #+#    #+#             */
/*   Updated: 2026/11/26 13:25:14 by hes-sofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	ft_eval(va_list *list, char spec, int fd)
{
	int	check;

	check = 0;
	if (spec == 'c')
		check = ft_print_char(va_arg(*list, int), fd);
	else if (spec == 's')
		check = ft_print_string(va_arg(*list, char *), fd);
	else if (spec == 'p')
		check = ft_print_pointer(va_arg(*list, void *), fd);
	else if (spec == 'd' || spec == 'i')
		check = ft_print_signed(va_arg(*list, int), fd);
	else if (spec == 'u')
		check = ft_print_unsigned(va_arg(*list, unsigned int), fd);
	else if (spec == 'x' || spec == 'X')
		check = ft_print_hex(va_arg(*list, unsigned int), spec, fd);
	else if (spec == '%')
		check = ft_print_char('%', fd);
	return (check);
}

static int	ft_norm_loop(va_list *list, const char *format, int fd)
{
	int	i;
	int	len;
	int	check;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			check = ft_eval(list, format[++i], fd);
		else
			check = ft_print_char(format[i], fd);
		if (check == -1)
			return (-1);
		len += check;
		i++;
	}
	return (len);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	list;
	int		len;

	if (!format)
		return (-1);
	va_start(list, format);
	len = ft_norm_loop(&list, format, fd);
	va_end(list);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		len;

	if (!format)
		return (-1);
	va_start(list, format);
	len = ft_norm_loop(&list, format, 1);
	va_end(list);
	return (len);
}
