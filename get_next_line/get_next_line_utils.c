/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:27:57 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/26 22:02:37 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*res;

	size = ft_strlen(s1);
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	check_for_n(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

static void	ft_combine_str(char const *s1, char const *s2, char *res)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		res[i] = s2[k];
		k++;
		i++;
	}
	res[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	ft_combine_str(s1, s2, res);
	free((void *)s1);
	return (res);
}