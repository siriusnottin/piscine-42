/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:32:11 by snottin           #+#    #+#             */
/*   Updated: 2019/06/19 16:27:47 by snottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	return_result(int nbr)
{
	int frst_nbr;
	int sec_nbr;

	if (nbr > 9)
	{
		frst_nbr = nbr / 10;
		sec_nbr = nbr % 10;
	}
	else
	{
		frst_nbr = 0;
		sec_nbr = nbr;
	}
	ft_putchar(frst_nbr + 48);
	ft_putchar(sec_nbr + 48);
}

void	ft_print_comb2(void)
{
	int count_1;
	int count_2;

	count_1 = 0;
	while (count_1 <= 99)
	{
		count_2 = count_1 + 1;
		while (count_2 <= 99)
		{
			return_result(count_1);
			ft_putchar(' ');
			return_result(count_2);
			if (count_1 < 98 || count_2 < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			count_2++;
		}
		count_1++;
	}
}
