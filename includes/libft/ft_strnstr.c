/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:03:33 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/22 11:46:03 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = ft_strlen(little);
	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *) big);
	while (*big && i <= len)
	{
		if (*big == *little && ft_strncmp(big, little, i) == 0)
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
    const char *haystack = "Hello, world! This is a test.";
    const char *needle = "world";
    size_t len = 15;

    char *result = ft_strnstr(haystack, needle, len);

    if (result)
    {
        printf("Needle found at position: %ld\n", result - haystack);
    }
    else
    {
        printf("Needle not found.\n");
    }

    return 0;
}
*/
/*
#include <stdio.h>

int main(void)
{
    char * empty = (char*)"";

    char *result = ft_strnstr(empty, "", 0);

    if (result)
    {
        printf("Needle found at position: %ld\n", result - empty);
    }
    else
    {
        printf("Needle not found.\n");
    }

    return 0;
}
*/
