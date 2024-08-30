/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:45:24 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/31 18:13:14 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	set_stack_a(char **nbr_list, t_stack **stack_a)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		exit(1);
	(*stack_a) = temp;
	while (*nbr_list)
	{
		temp->value = (int)ft_atoix(*nbr_list);
		if (*(nbr_list + 1))
		{
			temp->next = (t_stack *)malloc(sizeof(t_stack));
			if (!(temp->next))
				exit(1);
			temp = temp->next;
		}
		else
			temp->next = NULL;
		nbr_list++;
	}
	if (!check_for_duplicates(*stack_a))
		ft_error();
}

int	find_biggest(t_stack *stack_x)
{
	int	n;

	n = stack_x->value;
	while (stack_x)
	{
		if ((stack_x->value) > n)
			n = stack_x->value;
		stack_x = stack_x->next;
	}
	return (n);
}

int	find_smallest(t_stack *stack_x)
{
	int	n;

	n = stack_x->value;
	while (stack_x)
	{
		if ((stack_x->value) < n)
			n = stack_x->value;
		stack_x = stack_x->next;
	}
	return (n);
}
