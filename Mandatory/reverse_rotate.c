/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:35:39 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/31 18:37:22 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	reverse_rotate(t_stack **stack_x)
{
	t_stack	*temp;
	t_stack	*temp_2;

	temp = *stack_x;
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
			temp_2 = temp;
		temp = temp->next;
	}
	temp->next = *stack_x;
	temp_2->next = NULL;
	(*stack_x) = temp;
}

void	rra(t_stack **stack_a, t_stack *to_push)
{
	if (*stack_a != to_push)
	{
		reverse_rotate(stack_a);
		ft_putstr("rra\n");
	}
}

void	rrb(t_stack **stack_b, t_stack *to_push)
{
	if (*stack_b != to_push)
	{
		reverse_rotate(stack_b);
		ft_putstr("rrb\n");
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_stack *to_push)
{
	if (*stack_a != to_push->target && *stack_b != to_push)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_putstr("rrr\n");
	}
}
