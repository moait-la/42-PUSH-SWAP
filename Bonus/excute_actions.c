/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:18:51 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/31 20:08:14 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"
#include "../Includes/get_next_line.h"

void	continue_excuting(t_data **stack_a, t_data **stack_b, char *action)
{
	if (!ft_strncmp(action, "rra\n", 4))
		reverse_rotate_action(stack_a);
	else if (!ft_strncmp(action, "rrb\n", 4))
		reverse_rotate_action(stack_b);
	else if (!ft_strncmp(action, "rrr\n", 4))
	{
		reverse_rotate_action(stack_a);
		reverse_rotate_action(stack_b);
	}
	else if (!ft_strncmp(action, "rr\n", 3))
	{
		rotate_action(stack_a);
		rotate_action(stack_b);
	}
	else if (!ft_strncmp(action, "ss\n", 3))
	{
		swap_action(stack_a);
		swap_action(stack_b);
	}
	else
	{
		ft_free_bonus(*stack_a, *stack_b);
		error();
	}
}

void	excute_actions(t_data **stack_a, t_data **stack_b, char *action)
{
	if (!ft_strncmp(action, "pa\n", 3))
		pa_action(stack_b, stack_a);
	else if (!ft_strncmp(action, "pb\n", 3))
		pb_action(stack_a, stack_b);
	else if (!ft_strncmp(action, "sa\n", 3))
		swap_action(stack_a);
	else if (!ft_strncmp(action, "sb\n", 3))
		swap_action(stack_b);
	else if (!ft_strncmp(action, "ra\n", 3))
		rotate_action(stack_a);
	else if (!ft_strncmp(action, "rb\n", 3))
		rotate_action(stack_b);
	else
		continue_excuting(stack_a, stack_b, action);
}
