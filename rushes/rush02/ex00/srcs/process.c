/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:52:26 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 23:35:15 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int			check_param(char *s)
{
	int			i;

	i = -1;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (FAILURE);
	return (SUCCESS);
}

void		free_num_param(t_all *all)
{
	t_num_param	*tmp;
	t_num_param	*next;

	tmp = all->num_param;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	all->num_param = NULL;
}

int			param_handle(t_all *all, int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (check_param(av[i]) == FAILURE)
		{
			error();
			continue ;
		}
		if (all->num_param)
			free_num_param(all);
		if ((cut_word(all, av[i])) == FAILURE)
		{
			error();
			continue ;
		}
		break ;
	}
	return (SUCCESS);
}

void		num_cutter(t_all *all, int n, int deep)
{
	t_num	*ret;

	if ((ret = check_all_list(n, all->larousse)) == NULL)
	{
		num_cutter(all, n / deep, deep / 10);
		num_cutter(all, n % deep, deep / 10);
	}
	else
		add_to_result(&all->result, ret);
}

void		process(t_all *all)
{
	t_num_param *tmp;

	tmp = all->num_param;
	while (tmp)
	{
		num_cutter(all, tmp->id, 100);
		tmp = tmp->next;
	}
}
