/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:00:51 by aguyon            #+#    #+#             */
/*   Updated: 2023/10/12 16:02:23 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static	size_t	get_nb_len(__int128_t nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		count++;
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

int	print_base(int fd, __int128_t nb, unsigned int base)
{
	char			buffer[129];
	register size_t	i;
	const size_t	nb_len = get_nb_len(nb);

	i = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
		buffer[i++] = '-';
	i += nb_len - 1;
	while (nb)
	{
		buffer[i] = nb % 10;
		nb /= 10;
	}
	buffer[nb_len] = 0;
	return (write(1, buffer, nb_len));
}
