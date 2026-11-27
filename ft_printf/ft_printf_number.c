/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-sofy <hes-sofy>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:18:46 by hes-sofy          #+#    #+#             */
/*   Updated: 2026/11/24 07:17:55 by hes-sofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_digits(long nbr, int fd)
{
	char	str[11];
	int		i;
	int		len;
	int		check;

	len = 0;
	i = 0;
	while (nbr > 0)
	{
		str[i++] = nbr % 10 + 48;
		nbr /= 10;
	}
	while (i-- > 0)
	{
		check = ft_print_char(str[i], fd);
		if (check == -1)
			return (-1);
		len += check;
	}
	return (len);
}

int	ft_print_signed(int n, int fd)
{
	long	nbr;
	int		len;
	int		check;

	len = 0;
	nbr = n;
	if (nbr == 0)
		return (ft_print_char('0', fd));
	if (nbr < 0)
	{
		check = ft_print_char('-', fd);
		if (check == -1)
			return (-1);
		len += check;
		nbr *= -1;
	}
	check = ft_print_digits(nbr, fd);
	if (check == -1)
		return (-1);
	return (len + check);
}

int	ft_print_unsigned(unsigned int n, int fd)
{
	int	len;

	if (n == 0)
		return (ft_print_char('0', fd));
	len = ft_print_digits((long)n, fd);
	return (len);
}
