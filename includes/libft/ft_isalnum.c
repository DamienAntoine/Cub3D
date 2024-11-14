/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:29:38 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 11:57:47 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
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

	c = 'j';
	res = ft_isalnum(c);
	if (res == 1)
	{
		printf("\"%c\" is alnum", c);
	}
	else
	{
		printf("\"%c\" is not alnum", c);
	}
	return (0);
}
*/