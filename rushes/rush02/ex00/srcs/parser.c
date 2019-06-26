/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:19:51 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 23:35:40 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void		select_range(int id, t_dict *larousse, t_num *tmp)
{
	if (id >= UNIT_MIN && id <= UNIT_MAX)
		add_to_dict(&larousse->unit, tmp);
	if (id >= TEEN_MIN && id <= TEEN_MAX)
		add_to_dict(&larousse->teen, tmp);
	if (id == TENS_EXEP || (id >= TENS_MIN && id <= TENS_MAX))
		add_to_dict(&larousse->tens, tmp);
	if (id == HUNDRED_EXEP)
		add_to_dict(&larousse->hundred, tmp);
	if (id >= BIGNUM_EXEP)
		add_to_dict(&larousse->bignum, tmp);
}

int			check_line(char *s)
{
	int		i;
	int		found;

	i = -1;
	if (!s || !(*s) || *s == CHAR_SEP)
		return (FAILURE);
	while (s[++i] != CHAR_SPACE && s[i] != CHAR_SEP && (found = 1))
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (FAILURE);
	while (s[i] == CHAR_SPACE)
		i++;
	if (!found || s[i++] != CHAR_SEP)
		return (FAILURE);
	while (s[i] == CHAR_SPACE)
		i++;
	if (!s[i])
		return (FAILURE);
	while (s[++i])
		if (!(s[i] >= 32 && s[i] <= 126))
			return (FAILURE);
	return (SUCCESS);
}

int			dict_parser(t_all *all, char *file)
{
	char	**split;
	int		i;
	t_num	*tmp;

	if (!(all->larousse = try_malloc(sizeof(t_dict))))
		return (FAILURE);
	split = ft_split(file, "\n");
	i = -1;
	while (split[++i])
	{
		if (check_line(split[i]) == SUCCESS)
		{
			if (!(tmp = line_to_node(split[i])))
				return (FAILURE);
			select_range(tmp->id, all->larousse, tmp);
		}
		free(split[i]);
	}
	free(split);
	return (SUCCESS);
}

int			init_dict(t_all *all, char *filename)
{
	char	*file;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (FAILURE);
	if (!(file = get_file(fd)))
		return (FAILURE);
	close(fd);
	if ((dict_parser(all, file)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
