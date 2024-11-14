/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantoine <dantoine@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:58:52 by dantoine          #+#    #+#             */
/*   Updated: 2024/02/21 16:53:14 by dantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	*teststring1;
	char	*teststring2;
	char	*teststring3;
	int		test1;
	int		test2;
	int		test3;

	teststring1 = "-123";
	teststring2 = "-2147483648";
	teststring3 = "   +++-2147483648";
	test1 = ft_atoi(teststring1);
	test2 = ft_atoi(teststring2);
	test3 = ft_atoi(teststring3);
	printf("\n**********\nft_atoi: \n");
	printf("str 1: %d\n", test1);
	printf("str 2: %d\n", test2);
	printf("str 3: %d\n", test3);

    const char *input = "-123";
	const char *input2 = "-2147483648";
	const char *input3 = "   +++-2147483648";
    int result = atoi(input);
	int result2 = atoi(input2);
	int result3 = atoi(input3);
	printf("\n**********\nstd_atoi: \n");
    printf("Result: %d\n", result);
	printf("Result: %d\n", result2);
	printf("Result: %d\n", result3);

    return 0;
}
*/
