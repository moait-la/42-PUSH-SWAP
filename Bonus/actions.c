/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:04:15 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/31 20:58:26 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"
#include "../Includes/get_next_line.h"

void	swap_action(t_data **stack_x)
{
	int	temp;

	if (stack_len_bonus(*stack_x) >= 2)
	{
		temp = (*stack_x)->value;
		(*stack_x)->value = (*stack_x)->next->value;
		(*stack_x)->next->value = temp;
	}
}

void	rotate_action(t_data **stack_x)
{
	t_data	*temp;
	t_data	*temp_2;

	if (stack_len_bonus(*stack_x) >= 2)
	{
		temp = *stack_x;
		temp_2 = *stack_x;
		*stack_x = temp->next;
		while (temp->next != NULL)
			temp = temp->next;
		temp_2->next = NULL;
		temp->next = temp_2;
	}
}

void	reverse_rotate_action(t_data **stack_x)
{
	t_data	*temp;
	t_data	*temp_2;

	if (stack_len_bonus(*stack_x) >= 2)
	{
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
}

void	pb_action(t_data **stack_a, t_data **stack_b)
{
	t_data	*temp;

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
}

void	pa_action(t_data **stack_b, t_data **stack_a)
{
	t_data	*temp;

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
}
