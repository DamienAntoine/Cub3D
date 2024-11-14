/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:24:45 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/22 18:01:42 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (0);
		if (!s1)
			return (-1);
		if (!s2)
			return (1);
	}
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (((unsigned char)(*s1) - (unsigned char)(*s2)));
}
