/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:42:02 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/11 03:01:08 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/mini_talk.h"

void	check_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		write(2, "\nError: Failed to send acknowledgment 1\n", 38);
		exit(1);
	}
}

void	sig_handler(int sig, siginfo_t *info, __attribute__((unused))void *data)
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
			check_kill(current_pid, SIGUSR2);
		else
			write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	check_kill(current_pid, SIGUSR1);
}

int	main(int argc, __attribute__((unused))char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		write(2, "Error: Server accepts no arguments!\n", 36);
		return (1);
	}
	write(1, "Server <PID>: ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1)
		|| (sigaction(SIGUSR2, &sa, NULL) == -1))
	{
		write(2, "Error: Failed to set up signal handlers\n", 39);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
