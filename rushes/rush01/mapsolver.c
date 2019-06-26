/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:49:33 by snottin           #+#    #+#             */
/*   Updated: 2019/06/16 19:34:54 by snottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	stock_args(char nbr)
{
	char args_temp[25];
	int i;

	i = 0;
	args_temp[0] = argv[1][0];
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
		{
			args_temp[i] = argv[1][i + 1];
			printf("%c", args_temp[i]);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
