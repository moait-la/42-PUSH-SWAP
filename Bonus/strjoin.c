/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:45:16 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/27 17:07:53 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
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
	res[i] = '\0';
	free((void *)s1);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!res)
		return (NULL);
	ft_combine_str(s1, s2, res);
	return (res);
}

char	**join_args_bonus(int argc, char **argv)
{
	char	*str;
	char	**res;
	int		i;

	i = 1;
	str = ft_strdup("");
	while (i < argc)
	{
		str = ft_strjoin_bonus(str, argv[i]);
		i++;
	}
	res = ft_split(str, ' ');
	free(str);
	return (res);
}
