/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:15:45 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/19 10:59:22 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numblen(int numb)
{
	int	i;

	i = 0;
	if (!numb)
		i++;
	if (numb < 0)
	{
		i++;
		numb *= -1;
	}
	while (numb)
	{
		numb /= 10;
		i++;
	}
	return (i);
}

static void	ft_cal(char *str, int len, int n)
{
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numblen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	ft_cal(str, len, n);
	return (str);
}
