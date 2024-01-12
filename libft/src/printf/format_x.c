/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:16:14 by ntairatt          #+#    #+#             */
/*   Updated: 2023/03/22 08:27:10 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_x(unsigned int nbr, int *len, char c)
{
	if (nbr >= 16)
	{
		format_x(nbr / 16, len, c);
		format_x(nbr % 16, len, c);
	}
	else
	{
		if (nbr <= 9)
			format_c(nbr + '0', len);
		else if (nbr >= 10 && nbr <= 15 && c == 'x')
			format_c((nbr - 10) + 'a', len);
		else if (nbr >= 10 && nbr <= 15 && c == 'X')
			format_c((nbr - 10) + 'A', len);
	}
}
