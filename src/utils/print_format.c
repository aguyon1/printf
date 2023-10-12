/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:03:00 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/12 17:13:59 by aguyon           ###   ########.fr       */
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

static int	get_print_function_key(char conversion)
{
	char *const	conversion_ptr = ft_strchr(g_conversions, conversion);

	if (conversion_ptr == NULL)
		return (-1);
	return (conversion_ptr - g_conversions);
}

int	print_format(int fd, const char *format, va_list ap)
{
	int	count;
	int	sub_count;
	int	print_function_key;

	count = 0;
	while (*format)
	{
		if (format[0] == '%' && format[1])
		{
			print_function_key = get_print_function_key(format[1]);
			if (print_function_key != -1)
				sub_count = g_print_functions[print_function_key](fd, ap);
			format += 2;
		}
		else
		{
			sub_count = write(1, format, 1);
			format += 1;
		}
		if (sub_count < 0)
			return (-1);
		count += sub_count;
	}
	return (count);
}
