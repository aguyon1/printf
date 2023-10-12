/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:03:05 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/12 16:05:33 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	print_memory(int fd, va_list ap)
{
	const uintptr_t	address = va_arg(ap, uintptr_t);

	if (!address)
		return (write(fd, "(nil)", 5));
	if (write(1, "0x", 2) < 0)
		return (-1);
	return (print_base(fd, address, 16));
}
