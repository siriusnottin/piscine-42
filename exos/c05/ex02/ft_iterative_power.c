/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:28:18 by snottin           #+#    #+#             */
/*   Updated: 2019/06/26 18:44:03 by snottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_power(int nb, int power)
{
	if (power < 0)
		return (0);
	int i;

	i = 1;
	while (i <= power)
	{
		nb *= power;
		i++;
	}
	return (nb);
}

int		main(void)
{
	printf("%d", ft_iterative_power(5, 6));
	return 0;
}
