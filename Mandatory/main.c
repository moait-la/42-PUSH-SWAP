/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 07:43:49 by moait-la          #+#    #+#             */
/*   Updated: 2024/05/29 17:41:33 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../libft/libft.h"


int	main(int argc, char *argv[])
{
	char	**nbr_list;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	nbr_list = join_args(argc, argv);
	if (!nbr_list)
		return (1);
	if (!(check_ifvalid(nbr_list + 1)))
		ft_error();
	set_stack_a(nbr_list + 1, &stack_a);
	ft_free_argv(nbr_list);
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
