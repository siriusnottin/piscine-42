/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:02:30 by snottin           #+#    #+#             */
/*   Updated: 2019/06/26 11:07:41 by snottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		arg;
	char	*arg_temp;
	int		letter;

	(void)ac;
	arg = 0;
	while (av[++arg])
	{
		if (av[arg][0] > av[arg + 1][0])
		{
			letter = 0;
			while (av[arg][++letter])
			{
				arg_temp[letter] = av[arg][letter];
				av[arg][letter] = av[arg + 1][letter];
				av[arg + 1][letter] = arg_temp[letter];
			}
		}
		ft_putstr(av[arg]);
		ft_putchar('\n');
	}
}
