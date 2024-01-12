/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:30:14 by ntairatt          #+#    #+#             */
/*   Updated: 2023/03/22 08:22:21 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_u(unsigned int nbr, int *len)
{
	if (nbr >= 10)
	{
		format_d(nbr / 10, len);
		format_d(nbr % 10, len);
	}
	else
		format_c(nbr + '0', len);
}
