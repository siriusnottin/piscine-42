/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:05:37 by tharchen          #+#    #+#             */
/*   Updated: 2019/06/23 23:37:44 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

int		ft_atoi(const char *str);
void	*ft_bzero(void *s, int n);
void	ft_putstr(char *s);
int		ft_strfind(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strsub(char *s, int start, int len);
void	*try_malloc(size_t size);
char	*ft_strdup(char *src);
char	**ft_split(char *str, char *sep);
#endif
