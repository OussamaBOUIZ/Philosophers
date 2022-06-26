/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:19:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/26 15:36:40 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	out_of_range(void)
{
	printf("OUT OF RANGE ❌\n");
	return (-1);
}

int	check(const char *str)
{
	int					i;
	unsigned long long	num;
	int					sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		num = num * 10 + str[i] - '0';
		if ((num >= 2147483648 && sign == 1) || \
		(num > 2147483648 && sign == -1))
			return (out_of_range());
		i++;
	}
	return (num * sign);
}

int	check_range(char **nums, int n)
{
	int	i;

	i = 0;
	while (++i < n)
		if (check(nums[i]) == -1)
			return (1);
	return (0);
}
