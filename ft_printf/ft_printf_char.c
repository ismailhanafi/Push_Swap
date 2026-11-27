/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-sofy <hes-sofy>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:18:31 by hes-sofy          #+#    #+#             */
/*   Updated: 2026/11/24 07:33:39 by hes-sofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c, int fd)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (write(fd, &ch, 1) != 1)
		return (-1);
	return (1);
}

int	ft_print_string(const char *s, int fd)
{
	size_t	i;
	size_t	len;
	int		check;

	len = 0;
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		check = ft_print_char((int)s[i], fd);
		if (check == -1)
			return (-1);
		len += check;
		i++;
	}
	return (len);
}
