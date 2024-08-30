/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ifvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:09:21 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/30 20:25:27 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"

int	is_sorted(t_stack *stack_a)
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

int	check_for_duplicates(t_stack *stack_a)
{
	t_stack	*temp;

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

int	check_ifvalid(char **argv)
{
	long	nbr;

	while (*argv)
	{
		if (!(is_number(*argv)))
			return (0);
		nbr = ft_atoix(*argv);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		argv++;
	}
	return (1);
}
