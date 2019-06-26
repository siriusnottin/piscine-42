/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:04:08 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 23:33:57 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

t_num		*check_in_list(int to_find, t_num *list)
{
	t_num *tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->id == to_find)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_num		*check_all_list(int to_find, t_dict *dict)
{
	t_num	*ret;

	if ((ret = check_in_list(to_find, dict->unit)))
		return (ret);
	if ((ret = check_in_list(to_find, dict->teen)))
		return (ret);
	if ((ret = check_in_list(to_find, dict->tens)))
		return (ret);
	if ((ret = check_in_list(to_find, dict->hundred)))
		return (ret);
	if ((ret = check_in_list(to_find, dict->bignum)))
		return (ret);
	return (NULL);
}
