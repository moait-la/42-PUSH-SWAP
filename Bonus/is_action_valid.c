/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_action_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:54:33 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/31 20:15:45 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"
#include "../Includes/get_next_line.h"

int	is_action_valid(char *action, t_data *stack_a, t_data *stack_b)
{
	if (!ft_strncmp(action, "pa\n", 3))
		return (1);
	else if (!ft_strncmp(action, "pb\n", 3))
		return (1);
	else if (!ft_strncmp(action, "sa\n", 3))
		return (1);
	else if (!ft_strncmp(action, "sb\n", 3))
		return (1);
	else if (!ft_strncmp(action, "ra\n", 3))
		return (1);
	else if (!ft_strncmp(action, "rb\n", 3))
		return (1);
	else if (!ft_strncmp(action, "rra\n", 4))
		return (1);
	else if (!ft_strncmp(action, "rrb\n", 4))
		return (1);
	else if (!ft_strncmp(action, "rrr\n", 4))
		return (1);
	else if (!ft_strncmp(action, "rr\n", 3))
		return (1);
	else if (!ft_strncmp(action, "ss\n", 3))
		return (1);
	ft_free_bonus(stack_a, stack_b);
	error();
	return (0);
}
