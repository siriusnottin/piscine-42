/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:58:56 by snottin           #+#    #+#             */
/*   Updated: 2019/06/26 22:00:19 by snottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	j--;
	dest[i] = '\0';
	return (dest);
}

int		main(void)
{
	char b[100] = "wrnfgioerhgihg";
	char a[100] = "test";

	printf("%s vraie\n", strcat(b, a));
	printf("%s fausse\n", ft_strcat(b, a));
	return 0;
}
