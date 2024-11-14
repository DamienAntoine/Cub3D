/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:23:03 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 14:07:25 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *str, int searched)
{
	char	*ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == (unsigned char)searched)
			ptr = (char *)str;
		str++;
	}
	if (searched == 0)
		return ((char *)str);
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str;
	char	*result;
	int		searched;

	str = "Test String";
	searched = 'S';
	result = ft_strrchr(str, searched);
	
	printf("Result: %s\n", result);
	return (0);
}
*/