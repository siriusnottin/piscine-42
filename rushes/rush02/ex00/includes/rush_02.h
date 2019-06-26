/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:37:21 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 23:36:38 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H
# define SUCCESS		0
# define FAILURE		1
# define BUFF_SIZE		65535
# define CHAR_SEP		':'
# define CHAR_SPACE		' '
# define BIGNUM_MAGIC	1000
# define DICT_PATH		"data/dictionary_en"
# define UNIT_MIN		0
# define UNIT_MAX		9
# define TEEN_MIN		11
# define TEEN_MAX		19
# define TENS_EXEP		10
# define TENS_MIN		20
# define TENS_MAX		90
# define HUNDRED_EXEP	100
# define BIGNUM_EXEP	1000
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct				s_num
{
	int						id;
	char					*str;
	struct s_num			*next;
}							t_num;
typedef struct				s_dict
{
	t_num					*unit;
	t_num					*teen;
	t_num					*tens;
	t_num					*hundred;
	t_num					*bignum;
}							t_dict;
typedef struct				s_num_param
{
	int						id;
	int						thousands;
	struct s_num_param		*next;
}							t_num_param;
typedef struct				s_all
{
	t_dict					*larousse;
	t_num_param				*num_param;
	t_num					*result;
}							t_all;
int							parser(t_all *all, int fd);
int							init_dict(t_all *all, char *filename);
void						add_to_dict(t_num **list, t_num *new);
int							add_to_param(t_num_param **list, t_num_param *new);
int							add_to_result(t_num **list, t_num *new);
void						merge_list_num(t_num *first, t_num *second);
int							param_handle(t_all *all, int ac, char **av);
void						*error(void);
t_num						*check_all_list(int to_find, t_dict *dict);
char						*get_file(int fd);
int							ft_nbrlen(char *line);
char						*get_numstr(char *line);
t_num						*line_to_node(char *line);
t_num_param					*new_num_param(char *id, int thousands);
int							cut_word(t_all *all, char *num);
#endif
