/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:03:02 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/12 16:59:44 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	print_hexa_lower(int fd, va_list ap)
{
	const unsigned int	x = va_arg(ap, unsigned int);

	if (write(fd, "0x", 2) < 0)
		return (-1);
	return (print_base(fd, x, 16));
}

int	print_hexa_upper(int fd, va_list ap)
{
	const unsigned int	x = va_arg(ap, unsigned int);

	if (write(fd, "0X", 2) < 0)
		return (-1);
	return (print_base(fd, x, 16));
}
