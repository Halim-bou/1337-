/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 10:46:33 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-10 10:46:33 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				rank;
	struct s_stack	*next;
}					t_stack;

// parsing helper functions
void				ft_free_str_array(char **ars);
int					ft_isdigit(char c);
int					ft_isspace(char c);
int					ft_str_array_len(char **arr);
char				*ft_strcat(char *dest, char *src);
size_t				ft_strlen(char *str);
int					has_duplicates(int *tab, size_t size);
int					is_valid_input(char *str);
void				free_stack(t_stack *head);
void				calculate_ranks(t_stack *head);
int					check_for_empty_argument(int ac, char **av);

// parsing
char				**ft_split_whitespace(char *s);
int					*handle_input(int ac, char **av, int *argnum);
char				*join_args(int ac, char **av);
int					*process_2d_array(char **array, int *error,
						int num_strings);
int					safe_ft_atoi(char *str, int *error);
t_stack				*initialize_stack(int *arr, int size);

// list operations
t_stack				*create_node(int nb);
void				free_stack(t_stack *head);
void				free_stacks(t_stack *head_a, t_stack *head_b);

// operations
int					sa(t_stack **stack_a);
int					sb(t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);
int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);
int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);
int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_a, t_stack **stack_b);

// algo
int					is_sorted(t_stack *stack);
void				small_sort(t_stack **stack_a, t_stack **stack_b, int size);
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
int					find_index(int target, t_stack *stack);
void				sort_three(t_stack **stack_a);
void				radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
void				move_min_to_top(t_stack **stack, int distance, int size);

#endif
