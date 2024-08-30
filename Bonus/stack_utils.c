/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:43:59 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/30 20:51:14 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	stack_len_bonus(t_data *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	set_stack(char **argv, t_data **stack_a)
{
	t_data	*temp;

	temp = (t_data *)malloc(sizeof(t_data));
	if (!temp)
		exit(1);
	(*stack_a) = temp;
	while (*argv)
	{
		temp->value = ft_atoi(*argv);
		if (*(argv + 1))
		{
			temp->next = (t_data *)malloc(sizeof(t_data));
			if (!(temp->next))
				exit(1);
			temp = temp->next;
		}
		else
			temp->next = NULL;
		argv++;
	}
	if (!check_duplicates(*stack_a))
		error();
}
