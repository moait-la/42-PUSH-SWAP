/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:55:22 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/31 20:37:26 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*res;

	size = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, size);
	res[size] = '\0';
	return (res);
}
