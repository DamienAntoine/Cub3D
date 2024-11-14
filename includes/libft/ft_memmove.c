/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:07:41 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/19 12:14:57 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (dst == src)
		return (dst);
	else if (s < d)
	{
		s += num;
		d += num;
		while (num--)
		{
			*(--d) = *(--s);
		}
	}
	else
	{
		while (num--)
		{
			*(d++) = *(s++);
		}
	}
	return (dst);
}
