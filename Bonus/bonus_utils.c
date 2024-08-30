/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:19:43 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/31 20:38:41 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"
#include "../Includes/get_next_line.h"

char	*ft_strdup_bonus(char *s1)
{
	int		size;
	int		i;
	char	*res;

	i = 0;
	size = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	while (i < size)
	{
		res[i] = s1[i];
		i++;
	}
	res[size] = '\0';
	return (res);
}

static char	*ft_skip_zero(const char *str)
{
	while (*str && *str == '0')
		str++;
	return ((char *)str);
}

long	ft_atoi_long_bonus(const char *str)
{
	int					sign;
	int					nbr_len;
	unsigned long		total;

	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	total = 0;
	nbr_len = 0;
	str = ft_skip_zero(str);
	while (ft_isdigit(*str))
	{
		total = (total * 10) + (*str - '0');
		str++;
		nbr_len++;
	}
	if (nbr_len >= 20)
		error();
	return (total * sign);
}
