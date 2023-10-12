/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:03:12 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/12 16:59:58 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	print_unsigned_decimal(int fd, va_list ap)
{
	const unsigned int	u = va_arg(ap, unsigned int);

	return (print_base(fd, u, 10));
}
