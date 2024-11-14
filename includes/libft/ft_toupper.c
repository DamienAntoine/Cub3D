/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:17:12 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 12:20:24 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	char	c;

	c = 't';
	printf("Before toupper: %c\n", c);
	c = ft_tolower(c);
	printf("After toupper: %c", c);
	return 0;
}
*/