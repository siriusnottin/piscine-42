/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:06:05 by retang            #+#    #+#             */
/*   Updated: 2019/06/08 13:16:01 by retang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	condition_debut(int compteur_x, int x)
{
	char debut;
	char centre;
	char fin;

	debut = 'A';
	centre = 'B';
	fin = 'C';
	if (compteur_x == 0)
	{
		ft_putchar(debut);
	}
	else if (compteur_x != 0 && compteur_x != x)
	{
		ft_putchar(centre);
	}
	else
	{
		ft_putchar(fin);
	}
}

void	condition_centre(int compteur_x, int x)
{
	char debut;
	char centre;
	char fin;

	debut = 'B';
	centre = ' ';
	fin = 'B';
	if (compteur_x == 0)
	{
		ft_putchar(debut);
	}
	else if (compteur_x != 0 && compteur_x != x)
	{
		ft_putchar(centre);
	}
	else
	{
		ft_putchar(fin);
	}
}

void	condition_fin(int compteur_x, int x)
{
	char debut;
	char centre;
	char fin;

	debut = 'A';
	centre = 'B';
	fin = 'C';
	if (compteur_x == 0)
	{
		ft_putchar(debut);
	}
	else if (compteur_x != 0 && compteur_x != x)
	{
		ft_putchar(centre);
	}
	else
	{
		ft_putchar(fin);
	}
}

void	rush(int x, int y)
{
	int compteur_x;
	int compteur_y;

	compteur_y = 0;
	while (compteur_y != y && y > 0 && x > 0)
	{
		compteur_x = 0;
		while (compteur_x != x)
		{
			if (compteur_y == 0)
				condition_debut(compteur_x, x - 1);
			else if (compteur_y != 0 && compteur_y != y - 1)
				condition_centre(compteur_x, x - 1);
			else
				condition_fin(compteur_x, x - 1);
			compteur_x++;
		}
		if (x > 0 && y > 0)
		{
			ft_putchar('\n');
		}
		compteur_y++;
	}
}
