/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:45:17 by ntairatt          #+#    #+#             */
/*   Updated: 2023/03/30 12:44:57 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_s(char *str, int *len)
{
	if (str == NULL)
		format_s("(null)", len);
	else
		while (*str)
			format_c(*str++, len);
}
