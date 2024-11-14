/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:23:51 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 14:57:09 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int	main(void)
{
	char *dest;
	char *src;
	size_t size;
	size_t res;

	size = 3;
	src = "test string";
	dest = (char *)malloc((sizeof(char) * size) + 1);
	res = ft_strlcpy(dest, src, size);

	printf("Return value: %zu\n", res);
	printf("Destination string: %s\n", dest);
	return (0);
}
*/