/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:29:00 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 23:34:41 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

t_num_param		*new_num_param(char *id, int thousands)
{
	t_num_param	*new;

	if (!(new = try_malloc(sizeof(t_num_param))))
		return (NULL);
	new->id = ft_atoi(id);
	new->thousands = thousands;
	return (new);
}

int				cut_word(t_all *all, char *num)
{
	int			i;
	int			j;
	int			thousands;

	i = ft_strlen(num);
	thousands = 0;
	while (i)
	{
		j = i;
		while (i - j < 3 && j > 0)
			j--;
		if ((add_to_param(&all->num_param, new_num_param(
			ft_strsub(num, j, i - j), thousands))) == FAILURE)
			return (FAILURE);
		thousands++;
		i = j;
	}
	return (SUCCESS);
}
