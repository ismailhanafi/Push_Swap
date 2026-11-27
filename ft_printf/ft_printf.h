/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-sofy <hes-sofy>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:19:03 by hes-sofy          #+#    #+#             */
/*   Updated: 2026/11/26 13:35:17 by hes-sofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_dprintf(int fd, const char *format, ...);

int	ft_printf(const char *format, ...);

int	ft_print_char(int c, int fd);
int	ft_print_string(const char *s, int fd);

int	ft_print_signed(int n, int fd);
int	ft_print_unsigned(unsigned int n, int fd);

int	ft_print_pointer(void *ptr, int fd);

int	ft_print_hex(unsigned int n, char specifier, int fd);

#endif