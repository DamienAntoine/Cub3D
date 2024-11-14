/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:30:13 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/22 11:32:33 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	void	*ptr;

	if (elementcount && elementsize && elementcount > (UINT_MAX / elementsize))
		return (NULL);
	ptr = malloc(elementcount * elementsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, elementcount * elementsize);
	return (ptr);
}
/*
int	main(void)
{
	size_t	count = 5;
	size_t	size = 15;
	int	*ptr;
	int		i;

	ptr = (int *)ft_calloc(count, size);
	if (!ptr)
	{
		printf("allocation failed\n");
		return 1;
	}

	i = 0;
	while (i < count * size / sizeof(int))
	{
		printf("%d", ptr[i]);
		i++;
	}

	free(ptr);
	return 0;
}
*/
