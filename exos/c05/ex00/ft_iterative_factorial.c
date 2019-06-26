/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:37:45 by snottin           #+#    #+#             */
/*   Updated: 2019/06/26 18:06:05 by snottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int i;
	int fact;

	i = 1;
	fact = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		fact *= i;
		i++;
	}
	printf("%d", fact);
	return (nb);
}

int		main(void)
{
	ft_iterative_factorial(5);
	return (0);
}
