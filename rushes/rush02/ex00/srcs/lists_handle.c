/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:46:55 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 23:35:00 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void		add_to_dict(t_num **list, t_num *new)
{
	t_num	*tmp;

	if (!(*list))
		*list = new;
	else
	{
		if ((*list)->id > new->id)
		{
			new->next = *list;
			*list = new;
		}
		else
		{
			tmp = *list;
			while (tmp->next && tmp->next->id < new->id)
				tmp = tmp->next;
			if (!(tmp->next))
				tmp->next = new;
			else
			{
				new->next = tmp->next;
				tmp->next = new;
			}
		}
	}
}

int			add_to_param(t_num_param **list, t_num_param *new)
{
	t_num_param	*tmp;

	if (!new)
		return (FAILURE);
	if (!(*list))
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (SUCCESS);
}

int			add_to_result(t_num **list, t_num *new)
{
	t_num	*tmp;

	if (!new)
		return (FAILURE);
	if (!(*list))
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (SUCCESS);
}

void		merge_list_num(t_num *first, t_num *second)
{
	t_num	*tmp;

	if (first)
	{
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = second;
	}
}
