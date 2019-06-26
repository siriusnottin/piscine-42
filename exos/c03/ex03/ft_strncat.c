/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:46:12 by snottin           #+#    #+#             */
/*   Updated: 2019/06/26 19:11:29 by snottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int dest_len;

	i = 0;
	while (dest[i] != '\0')
	{
		dest_len = i;
		i++;
	}
	i = 0;
	while (src[i] != '\0' && i < nb - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	while (dest[i] < nb)
	{
		dest[dest_len + i] = '\0';
	}
	return (dest);
}
