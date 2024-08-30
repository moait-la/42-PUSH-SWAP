/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:50:28 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/25 16:10:11 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a)
	{
		temp = (*stack_a);
		(*stack_a) = temp->next;
		if (!(*stack_b))
		{
			temp->next = NULL;
			(*stack_b) = temp;
		}
		else
		{
			temp->next = (*stack_b);
			(*stack_b) = temp;
		}
	}
	ft_putstr("pb\n");
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*temp;

	if (*stack_b)
	{
		temp = (*stack_b);
		(*stack_b) = temp->next;
		if (!(*stack_a))
		{
			temp->next = NULL;
			(*stack_a) = temp;
		}
		else
		{
			temp->next = (*stack_a);
			(*stack_a) = temp;
		}
	}
	ft_putstr("pa\n");
}
