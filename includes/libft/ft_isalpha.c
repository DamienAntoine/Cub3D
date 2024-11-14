/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:29:13 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 12:01:00 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	res = ft_isalpha(c);
	if (res == 1)
	{
		printf("\"%c\" is alpha", c);
	}
	else
	{
		printf("\"%c\" is not alpha", c);
	}
	return (0);
}
*/