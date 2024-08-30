/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ifvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:22:40 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/26 22:25:51 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"
#include "../Includes/get_next_line.h"

int	sorted(t_data	*stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value >= stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	is_number(char *str)
{
	while (*str == 32)
		str++;
	if (*str == 45 || *str == 43)
		str++;
	while (*str && *str >= 48 && *str <= 57)
	{
		str++;
		if (!(*str))
			return (1);
	}
	return (0);
}

int	check_duplicates(t_data *stack_a)
{
	t_data	*temp;

	while (stack_a->next != NULL)
	{
		temp = stack_a;
		while (temp->next != NULL)
		{
			if (stack_a->value == temp->next->value)
				return (0);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_ifvalid_bonus(char **argv)
{
	long	nbr;
	int		nb_count;

	nb_count = 0;
	while (*argv)
	{
		if (!(is_number(*argv)))
			return (0);
		nbr = ft_atoi_long_bonus(*argv);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		argv++;
		nb_count++;
	}
	if (nb_count == 1)
		exit(1);
	return (1);
}
