/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:58:38 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 12:00:59 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	c;
	int		res;

	c = '8';
	res = ft_isascii(c);
	if (res == 1)
	{
		printf("\"%c\" is ascii", c);
	}
	else
	{
		printf("\"%c\" is not ascii", c);
	}
	return (0);
}
*/