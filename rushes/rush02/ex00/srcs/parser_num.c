/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:27:26 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 23:35:30 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char		*get_file(int fd)
{
	char	*file;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	file = (char *)malloc(sizeof(char));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		tmp = ft_strjoin(file, buf);
		free(file);
		file = tmp;
	}
	return (file);
}

int			ft_nbrlen(char *line)
{
	int		i;

	i = -1;
	while (line[++i] && line[i] >= '0' && line[i] <= '9')
		;
	return (i);
}

char		*get_numstr(char *line)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (line[++i] != CHAR_SEP)
		;
	while (line[++i] == CHAR_SPACE)
		;
	j = i;
	k = 0;
	while (line[j])
	{
		k += line[j] != CHAR_SPACE ? 1 : 0;
		j++;
	}
	if (!(new = try_malloc(sizeof(char) * (k + 1))))
		return (NULL);
	j = -1;
	while (line[i + (++j)])
		new[j] = line[i + j];
	return (new);
}

t_num		*line_to_node(char *line)
{
	t_num	*new;

	if (!(new = try_malloc(sizeof(t_num))))
		return (NULL);
	if (ft_nbrlen(line) < 4)
		new->id = ft_atoi(line);
	else
		new->id = ft_nbrlen(line) + BIGNUM_MAGIC;
	new->str = get_numstr(line);
	return (new);
}
