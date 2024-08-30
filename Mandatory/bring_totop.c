/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_totop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:05:39 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/27 19:39:04 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"

static void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *to_push)
{
	while (*stack_a != to_push->target)
	{
		if (*stack_a == to_push->target && *stack_b != to_push)
			rb(stack_b, to_push);
		else if (*stack_a != to_push->target && *stack_b == to_push)
			ra(stack_a, to_push);
		else
			rr(stack_a, stack_b, to_push);
	}
	while (*stack_b != to_push)
	{
		if (*stack_a == to_push->target && *stack_b != to_push)
			rb(stack_b, to_push);
		else if (*stack_a != to_push->target && *stack_b == to_push)
			ra(stack_a, to_push);
		else
			rr(stack_a, stack_b, to_push);
	}
}

void	r_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *to_push)
{
	while (*stack_a != to_push->target)
	{
		if (*stack_a == to_push->target && *stack_b != to_push)
			rrb(stack_b, to_push);
		else if (*stack_a != to_push->target && *stack_b == to_push)
			rra(stack_a, to_push);
		else
			rrr(stack_a, stack_b, to_push);
	}
	while (*stack_b != to_push)
	{
		if (*stack_a == to_push->target && *stack_b != to_push)
			rrb(stack_b, to_push);
		else if (*stack_a != to_push->target && *stack_b == to_push)
			rra(stack_a, to_push);
		else
			rrr(stack_a, stack_b, to_push);
	}
}

static void	bring_totop(t_stack **stack_a, t_stack **stack_b, t_stack *to_push)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(*stack_a);
	len_b = stack_len(*stack_b);
	while (*stack_a != to_push->target)
	{
		if (to_push->target->index <= (len_a / 2))
			ra(stack_a, to_push);
		else
			rra(stack_a, to_push);
	}
	while (*stack_b != to_push)
	{
		if (to_push->index <= (len_b / 2))
			rb(stack_b, to_push);
		else
			rrb(stack_b, to_push);
	}
}

static void	*which_topush(t_stack *stack)
{
	int		best_res;
	t_stack	*the_one;

	best_res = INT_MAX;
	while (stack)
	{
		if (stack->cost < best_res)
		{
			best_res = stack->cost;
			the_one = stack;
		}
		stack = stack->next;
	}
	return (the_one);
}

void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*to_push;
	int		len_b;
	int		len_a;

	len_b = stack_len(*stack_b) / 2;
	len_a = stack_len(*stack_a) / 2;
	to_push = which_topush(*stack_b);
	if (to_push->index <= len_b && to_push->target->index <= len_a)
		rotate_both(stack_a, stack_b, to_push);
	else if (to_push->index > len_b && to_push->target->index > len_a)
		r_rotate_both(stack_a, stack_b, to_push);
	else
		bring_totop(stack_a, stack_b, to_push);
	pa(stack_b, stack_a);
}
