/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:28:05 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/19 12:28:48 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *mem, int searched, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)mem;
	searched = (unsigned char)searched;
	while (size && *ptr != searched)
	{
		++ptr;
		--size;
	}
	if (size)
		return ((void *) ptr);
	else
		return (NULL);
}
