/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 07:43:53 by moait-la          #+#    #+#             */
/*   Updated: 2024/01/31 20:44:43 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int				value;
	struct s_data	*next;
}					t_data;

//errors
void	ft_free_stack(t_stack *stack);
void	ft_free_argv(char **argv);
void	ft_error(void);

//utils
void	ft_putstr(char *str);
long	ft_atoix(const char *str);
void	set_cost(t_stack *stack_a, t_stack *stack_b);
char	**join_args(int argc, char **argv);

//stack utils
int		find_smallest(t_stack *stack_x);
int		find_biggest(t_stack *stack_x);
int		stack_len(t_stack *stack);

//input check
int		check_ifvalid(char **argv);
int		check_for_duplicates(t_stack *stack_a);
int		is_sorted(t_stack *stack_a);
int		is_number(char *str);

//actions
void	rotate(t_stack **stack_x);
void	ra(t_stack **stack_a, t_stack *to_push);
void	rb(t_stack **stack_b, t_stack *to_push);
void	rr(t_stack **stack_a, t_stack **stack_b, t_stack *to_push);

void	swap(t_stack **stack_x);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate(t_stack **stack_x);
void	rra(t_stack **stack_a, t_stack *to_push);
void	rrb(t_stack **stack_b, t_stack *to_push);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_stack *to_push);

void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);

//algorith type shiit
void	set_target(t_stack *stack_a, t_stack *stack_b);
void	set_index(t_stack *stack_x);
void	set_stack_a(char **argv, t_stack **stack_a);

//sort
void	sort(t_stack **stack_a, t_stack **stack_b);

//push back
void	push_back(t_stack **stack_a, t_stack **stack_b);

//bonus
int		check_duplicates(t_data *stack_a);
int		sorted(t_data	*stack_a);
int		stack_len_bonus(t_data *stack);
int		check_ifvalid_bonus(char **argv);
int		ft_atoi(char *str);
long	ft_atoi_long_bonus(const char *str);
char	**join_args_bonus(int argc, char **argv);
void	error(void);
void	ft_free_bonus(t_data *stack_a, t_data *stack_b);
void	set_stack(char **argv, t_data	**stack_a);
void	excute_actions(t_data **stack_a, t_data **stack_b, char *action);

//bonus actions
void	swap_action(t_data **stack_x);
void	rotate_action(t_data **stack_x);
void	reverse_rotate_action(t_data **stack_x);
void	pb_action(t_data **stack_a, t_data **stack_b);
void	pa_action(t_data **stack_b, t_data **stack_a);

#endif