/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:17:47 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/22 12:18:29 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (size - start < len)
		len = size - start;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	size_t	len;
	char	*new;

	str = "test string 123456";
	len = ft_strlen(str);
	if (new)
	{
		new = ft_substr(str, 12, 6);
		printf("Original: %s\n", str);
		printf("New: %s", new);
	}
	else
		printf("Failed");
	return (0);
}
*/
