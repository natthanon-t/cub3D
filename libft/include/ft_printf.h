/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:52:29 by ntairatt          #+#    #+#             */
/*   Updated: 2023/05/29 12:10:21 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	format_c(int c, int *len);
void	format_s(char *str, int *len);
void	format_d(int nbr, int *len);
void	format_u(unsigned int nbr, int *len);
void	format_p(unsigned long nbr, int *len);
void	format_x(unsigned int nbr, int *len, char c);

#endif
