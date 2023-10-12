/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:59:07 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/12 17:00:14 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/inc/libft.h"
# include <stdarg.h>

/* FUNCTIONS */
int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);

/* UTILS */
int	print_format(int fd, const char *format, va_list ap);
int	print_base(int fd, __int128_t nb, unsigned int base);
int	print_char(int fd, va_list ap);
int	print_decimal(int fd, va_list ap);
int	print_hexa_lower(int fd, va_list ap);
int	print_hexa_upper(int fd, va_list ap);
int	print_memory(int fd, va_list ap);
int	print_percent(int fd, va_list ap);
int	print_str(int fd, va_list ap);
int	print_unsigned_decimal(int fd, va_list ap);

#endif /* FT_PRINTF_H */
