/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:10:22 by moait-la          #+#    #+#             */
/*   Updated: 2024/08/28 02:22:25 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"

t_stack	*get_smallest(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*smallest;
	int		best_match;

	best_match = INT_MAX;
	temp = stack;
	while (temp)
	{
		if (temp->value <= best_match)
		{
			best_match = temp->value;
			smallest = temp;
		}
		temp = temp->next;
	}
	return (smallest);
}

void	sort_three(t_stack **stack_x)
{
	int	biggest_v;

	biggest_v = find_biggest(*stack_x);
	if ((*stack_x)->value == biggest_v)
		ra(stack_x, (*stack_x)->next);
	else if ((*stack_x)->next->value == biggest_v)
		rra(stack_x, (*stack_x)->next);
	if ((*stack_x)->value > (*stack_x)->next->value)
		sa(*stack_x);
}

void	set_values(t_stack *stack_a, t_stack *stack_b)
{
	set_target(stack_a, stack_b);
	set_index(stack_a);
	set_index(stack_b);
	set_cost(stack_a, stack_b);
}

static void	sort_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;
	int		mid;

	//mid = 5
	//10 25 32 5 37 / 2 18
	
	mid = (find_smallest(*stack_a) + find_biggest(*stack_a)) / 2;
	while (stack_len(*stack_a) > 3)
	{
		pb(stack_a, stack_b);
		if ((*stack_b)->value > mid && stack_len(*stack_b) > 1)
			rb(stack_b, *stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_values(*stack_a, *stack_b);
		push_back(stack_a, stack_b);
	}
	set_index(*stack_a);
	smallest = get_smallest(*stack_a);
	while (*stack_a != smallest)
	{
		if (smallest->index <= (stack_len(*stack_a) / 2))
			ra(stack_a, smallest);
		else
			rra(stack_a, smallest);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_len(*stack_a) == 2)
		sa(*stack_a);
	else if (stack_len(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_algo(stack_a, stack_b);
}
