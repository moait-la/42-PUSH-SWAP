/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:04:58 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/26 20:38:38 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static char	**ft_free(char **res, int i)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
	return (NULL);
}

static int	ft_words_num(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_insert_word(char *res, char const *s, int len, int j)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		res[i] = s[j - len];
		i++;
		len--;
	}
	res[i] = '\0';
}

static char	**ft_insert(char **res, char const *s, char c, int words_num)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	res[0] = (char *)malloc(1);
	if (!res[0])
		return (ft_free(res, 0));
	res[0][0] = '\0';
	while (i < words_num)
	{
		len = j;
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j] != c && s[j] != '\0')
			j++;
		res[i + 1] = (char *)malloc(sizeof(char) * (j - len + 1));
		if (!res[i + 1])
			return (ft_free(res, i + 1));
		ft_insert_word(res[i + 1], s, j - len, j);
		i++;
	}
	res[i + 1] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		words_num;
	int		i;
	char	**res;

	i = 0;
	if (!s)
		return (NULL);
	words_num = ft_words_num(s, c);
	res = (char **)malloc(sizeof(char *) * (words_num + 2) * 8);
	if (!res)
		return (NULL);
	res = ft_insert(res, s, c, words_num);
	return (res);
}
