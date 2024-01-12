/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:52:20 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/11 14:23:18 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_check(va_list args, char conversion, int *len)
{
	if (conversion == 'c')
		format_c(va_arg(args, int), len);
	else if (conversion == 's')
		format_s(va_arg(args, char *), len);
	else if (conversion == 'd' || conversion == 'i')
		format_d(va_arg(args, int), len);
	else if (conversion == 'u')
		format_u(va_arg(args, unsigned int), len);
	else if (conversion == 'p')
	{
		format_s("0x", len);
		format_p(va_arg(args, unsigned long int), len);
	}
	else if (conversion == 'x' || conversion == 'X')
		format_x(va_arg(args, unsigned int), len, conversion);
	else if (conversion == '%')
		format_c('%', len);
	else
	{
		format_c('%', len);
		format_c(conversion, len);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len_print;

	i = 0;
	len_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			conversion_check(args, str[i + 1], &len_print);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			len_print++;
		}
	}
	va_end(args);
	return (len_print);
}
