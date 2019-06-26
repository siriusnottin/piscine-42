/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:45:36 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 23:33:24 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	print_res(t_all *all)
{
	t_num	*tmp;

	tmp = all->result;
	while (tmp)
	{
		ft_putstr(tmp->str);
		ft_putstr(" ");
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_all		*all;

	if (ac < 2)
		return (SUCCESS);
	if (!(all = try_malloc(sizeof(t_all))))
		return (FAILURE);
	if (init_dict(all, DICT_PATH) == FAILURE)
		return (FAILURE);
	param_handle(all, ac, av);
	print_res(all);
	return (SUCCESS);
}
