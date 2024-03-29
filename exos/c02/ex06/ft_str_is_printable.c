/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:47:28 by snottin           #+#    #+#             */
/*   Updated: 2019/06/25 23:32:25 by snottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	while (str[0] != '\0')
	{
		if (str[0] < 32 || str[0] > 126)
			return (0);
		str++;
	}
	return (1);
}
