/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:24:38 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 15:27:56 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src) + 1;
	new = (char *)malloc(len);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, src, len);
	return (new);
}
