/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:36:50 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/26 20:39:30 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*my_dst;
	char		*my_src;
	size_t		i;

	i = 0;
	my_dst = (char *)dst;
	my_src = (char *)src;
	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		my_dst[i] = my_src[i];
		i++;
	}
	return (dst);
}
