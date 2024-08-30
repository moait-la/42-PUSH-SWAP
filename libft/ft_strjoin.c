/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:45:45 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/26 22:37:31 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	ft_combine_str(char *s1, char *s2, char *res)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s1[k] != '\0')
	{
		res[i] = s1[k];
		i++;
		k++;
	}
	res[i] = ' ';
	i++;
	k = 0;
	while (s2[k] != '\0')
	{
		res[i] = s2[k];
		k++;
		i++;
	}
	res[i] = ' ';
	i++;
	res[i] = '\0';
	free((void *)s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 3));
	if (!res)
		return (NULL);
	ft_combine_str(s1, s2, res);
	return (res);
}
