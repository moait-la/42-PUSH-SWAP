/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:07:19 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/30 20:25:21 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"

char	**join_args(int argc, char **argv)
{
	char	*str;
	char	**res;
	int		i;

	i = 1;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		if (!str)
			return (NULL);
		i++;
	}
	res = ft_split(str, ' ');
	if (!res)
		return (NULL);
	free(str);
	return (res);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static char	*ft_skip_zero(const char *str)
{
	while (*str && *str == '0')
		str++;
	return ((char *)str);
}

long	ft_atoix(const char *str)
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
		ft_error();
	return (total * sign);
}
