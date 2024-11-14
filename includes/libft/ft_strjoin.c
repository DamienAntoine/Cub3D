/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:00:40 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/22 12:27:03 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	size1;
	size_t	size2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	new = ft_strnew(size1 + size2);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, size1 + 1);
	ft_strlcat(new, s2, size1 + size2 + 1);
	return (new);
}
/*
#include <stdio.h>

int main(void) {
    char *s = ft_strjoin("tripouille", "42");
    char *str1 = ft_strnew(10);
    if (!str1) {
        fprintf(stderr, "Memory allocation failed for ft_strnew.\n");
        return 1;
    }
    printf("ft_strnew result: %s\n", str1);
    free(str1);

    const char *s1 = "Hello, ";
    const char *s2 = "world!";
    char *result = ft_strjoin(s1, s2);
    if (!result) {
        fprintf(stderr, "Memory allocation failed for ft_strjoin.\n");
        return 1;
    }
    printf("test: %s\n", s);
    printf("ft_strjoin result: %s\n", result);
    free(result);

    return 0;
}
*/
