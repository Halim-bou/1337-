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
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

/* Linked liste structer */
typedef struct s_list
{
	void			*content;
	long int		num;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

//function helpers
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t number, size_t size);
long	ft_atoil(const char *n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
int	ft_isdigit(int c);

// function check valide data
int	check_chars(t_list *lst);
int	check_dup(t_list *lst);
int	check_int(long int num);
int	validation(t_list **lst);
void	free_split(t_list **lst);
#endif
