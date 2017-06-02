/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:47:15 by aemilien          #+#    #+#             */
/*   Updated: 2017/06/02 10:01:21 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int n, int pow)
{
	if (!pow)
		return (n);
	return (n * ft_pow(n, pow - 1));
}

static int	set_value(char *str, int base)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i]) | ft_isalpha(str[i]))
		i++;
	return (ft_pow(base, i - 1));
}

int			ft_atoi_base(char *str, int base)
{
	int		nbr;
	int		signe;
	int		d;

	nbr = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		signe = (base == 10 && *str == '-') ? -1 : 1;
		str++;
	}
	d = set_value(str, base);
	while (ft_isalpha(*str) || ft_isdigit(*str))
	{
		if (ft_isdigit(*str))
			nbr += (*str - '0') * d;
		else if (*str < 123 && *str > 96)
			nbr += (*str - 'a' + 10) * d;
		else if (*str < 91 && *str > 64)
			nbr += (*str - 'A' + 10) * d;
		d /= base;
		str++;
	}
	return (nbr * signe);
}
