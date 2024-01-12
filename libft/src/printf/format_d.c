/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:21:03 by ntairatt          #+#    #+#             */
/*   Updated: 2023/03/29 23:32:41 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_d(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		format_s("-2147483648", len);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		format_c('-', len);
	}
	if (nbr >= 10)
	{
		format_d(nbr / 10, len);
		format_d(nbr % 10, len);
	}
	else
		format_c(nbr + '0', len);
}
