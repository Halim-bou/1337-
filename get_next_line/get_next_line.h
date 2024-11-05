/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-05 13:02:59 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-05 13:02:59 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024

#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	char	*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
#endif
#endif
