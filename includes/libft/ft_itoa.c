/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:22:59 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 12:02:03 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getsize(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_fillstr(int size, int n, char *str)
{
	if (n == 0)
		str[0] = '0';
	else
	{
		while (n != 0)
		{
			str[--size] = '0' + n % 10;
			n = n / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_getsize(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	ft_fillstr(size, n, str);
	str[size] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	printf("\n**********\nft_itoa: \n");
	char *result = ft_itoa(-54684);
	char *result2 = ft_itoa(-2147483648);
	char *result3 = ft_itoa(0002);
	printf("%s", result);
	printf("%s", result2);
	printf("%s", result3);
}
*/