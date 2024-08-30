/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:21:47 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/26 22:11:41 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	rotate(t_stack **stack_x)
{
	t_stack	*temp;
	t_stack	*temp_2;

	temp = *stack_x;
	temp_2 = *stack_x;
	*stack_x = temp->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp_2->next = NULL;
	temp->next = temp_2;
}

void	ra(t_stack **stack_a, t_stack *to_push)
{
	if (*stack_a != to_push)
	{
		rotate(stack_a);
		ft_putstr("ra\n");
	}
}

void	rb(t_stack **stack_b, t_stack *to_push)
{
	if ((*stack_b) != to_push)
	{
		rotate(stack_b);
		ft_putstr("rb\n");
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_stack *to_push)
{
	if (*stack_a != to_push->target && *stack_b != to_push)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_putstr("rr\n");
	}
}
