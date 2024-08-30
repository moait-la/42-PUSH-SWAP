/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:26:17 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/31 20:03:32 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"
#include "../Includes/get_next_line.h"

void	ft_free_bonus(t_data *stack_a, t_data *stack_b)
{
	t_data	*temp;
	t_data	*temp_2;

	if (stack_a)
	{
		while (stack_a != NULL)
		{
			temp = stack_a->next;
			free(stack_a);
			stack_a = temp;
		}
	}
	if (stack_b)
	{
		while (stack_b != NULL)
		{
			temp_2 = stack_b->next;
			free(stack_b);
			stack_b = temp_2;
		}
	}
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
