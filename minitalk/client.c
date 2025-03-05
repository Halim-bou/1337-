/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 14:07:36 by abelboua          #+#    #+#             */
/*   Updated: 2025-02-14 14:07:36 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/mini_talk.h"
#include <signal.h>

void	send_signal(char *str, int pid)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = 7;
		while(j>= 0)
		{
			if ((str[i]>>j)&1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(500);
		}
		i++;
	}
	j = 7;
	while(j >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(500);
		j--;
	}
}

int main(int argc, char **argv)
{
	int	pid;
	char	*str;

	if (argc != 3)
		return EXIT_FAILURE;
	pid = atoi(argv[1]);
	str = argv[2];
	send_signal(str, pid);
	return EXIT_SUCCESS;
}
