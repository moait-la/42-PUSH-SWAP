/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:07:18 by moait-la          #+#    #+#             */
/*   Updated: 2024/05/29 17:41:13 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"
#include "../Includes/get_next_line.h"

void	ft_free_argv_bonus(char **argv)
{
	int	i;

	if (argv == NULL)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	read_actions(t_data **stack_a, t_data **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		excute_actions(stack_a, stack_b, line);
		free(line);
	}
}

void fun(){system("leaks checker");}

int	main(int argc, char **argv)
{
	atexit(fun);
	char	**nbr_list;
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	nbr_list = join_args_bonus(argc, argv);
	if (!check_ifvalid_bonus(nbr_list + 1))
		error();
	set_stack(nbr_list + 1, &stack_a);
	read_actions(&stack_a, &stack_b);
	ft_free_argv_bonus(nbr_list);
	if (sorted(stack_a) && stack_len_bonus(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_bonus(stack_a, stack_b);
	return (0);
}
