/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:06:10 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 12:20:25 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char	c;

	c = 'T';
	printf("Before tolower: %c\n", c);
	c = ft_tolower(c);
	printf("After tolower: %c", c);
	return 0;
}
*/