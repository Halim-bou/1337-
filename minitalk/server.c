/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 14:07:22 by abelboua          #+#    #+#             */
/*   Updated: 2025-02-14 14:07:22 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/mini_talk.h"

void	sig_handel(int sig, siginfo_t *info, __attribute__((unused))void *data)
{
	static char		c;
	static int		bit;
	static pid_t	last_pid;
	pid_t			current_pid;

	current_pid = info->si_pid;
	if (last_pid != 0 && last_pid != current_pid)
	{
		c = 0;
		bit = 0;
	}
	last_pid = current_pid;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			return ;
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(int argc, __attribute__((unused))char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		write(1, "Error: Server acctept no arguments!!\n", 36);
		return (-1);
	}
	write(1, "Server <PID>: ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = sig_handel;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
