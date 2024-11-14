/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:25:23 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 16:05:29 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		ptr++;
	}
	if (*ptr == '\0' && c == '\0')
	{
		return (ptr);
	}
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
	char s[] = "test";
	char *res;
	
	res = ft_strchr(s, 't' + 256);
	printf("return value: %s\n", res);
	printf("Output string: %s\n", s);
	return (0);
}
*/