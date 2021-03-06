/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:28:26 by salibert          #+#    #+#             */
/*   Updated: 2016/11/09 10:24:59 by salibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab(char **s)
{
	size_t x;

	x = 0;
	while (s[x])
	{
		ft_putendl(s[x]);
		x++;
	}
}
