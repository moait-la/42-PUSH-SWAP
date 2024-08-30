/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:26:55 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/26 23:41:10 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	swap(t_stack **stack_x)
{
	int	temp;

	if (stack_len(*stack_x) >= 2)
	{
		temp = (*stack_x)->value;
		(*stack_x)->value = (*stack_x)->next->value;
		(*stack_x)->next->value = temp;
	}
}

void	sa(t_stack *stack_a)
{
	swap(&stack_a);
	ft_putstr("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(&stack_b);
	ft_putstr("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
