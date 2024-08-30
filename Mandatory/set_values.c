/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:55:45 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/26 20:38:06 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"

void	set_index(t_stack *stack_x)
{
	int	position;

	position = 0;
	while (stack_x)
	{
		stack_x->index = position;
		stack_x = stack_x->next;
		position++;
	}
}

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	target_cost;
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b)
	{
		if (stack_b->target->index <= (len_a / 2))
			target_cost = stack_b->target->index;
		else
			target_cost = len_a - stack_b->target->index;
		if (stack_b->index <= (len_b / 2))
			stack_b->cost = target_cost + stack_b->index;
		else
			stack_b->cost = target_cost + (len_b - stack_b->index);
		stack_b = stack_b->next;
	}
}

static t_stack	*smallest_value(t_stack *stack_a)
{
	long	smallest_value;
	t_stack	*smallest_target_value;

	while (stack_a)
	{
		if (stack_a->value < smallest_value)
		{
			smallest_value = stack_a->value;
			smallest_target_value = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (smallest_target_value);
}

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	t_stack	*target;
	long	target_value;

	while (stack_b)
	{
		temp = stack_a;
		target_value = LONG_MAX;
		while (temp)
		{
			if (temp->value > stack_b->value && temp->value < target_value)
			{
				target = temp;
				target_value = temp->value;
			}
			temp = temp->next;
		}
		if (target_value == LONG_MAX)
			target = smallest_value(stack_a);
		stack_b->target = target;
		stack_b = stack_b->next;
	}
}
