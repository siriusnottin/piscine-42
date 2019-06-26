/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:38:46 by snottin           #+#    #+#             */
/*   Updated: 2019/06/26 09:58:22 by snottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int ret_nb;

	i = 0;
	sign = 0;
	while ((str[i] == ' ')
			|| (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * sign - 1;
		i++;
	}
	ret_nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret_nb *= 10;
		ret_nb += str[i] - '0';
		i++;
	}
	if (sign)
		return (-ret_nb);
	return (ret_nb);
}
