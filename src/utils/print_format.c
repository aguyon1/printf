/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:03:00 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/12 16:59:17 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int (*const	g_print_functions[])(int fd, va_list ap)
	= {
	print_char,
	print_str,
	print_memory,
	print_decimal,
	print_unsigned_decimal,
	print_hexa_lower,
	print_hexa_upper,
	print_percent,
};

static const char	g_conversions[] = "cspdiuxX%";

static int	get_print_functions_key(char conversion)
{
	char *const	conversion_ptr = ft_strchr(g_conversions, conversion);

	if (conversion_ptr == NULL)
		return (-1);
	return (conversion_ptr - g_conversions);
}

int	print_format(int fd, const char *format, va_list ap)
{
	int	count;
	int	print_function_key;

	count = 0;
	while (*format)
	{
		if (format[0] == '%' && format[1])
		{
			print_function_key = get_print_functions_key(format[0]);
			if (print_function_key != -1)
				count += g_print_functions[print_function_key](fd, ap);
			format += 2;
		}
		else
		{
			count += write(1, format, 1);
			format += 1;
		}
	}
	return (count);
}
