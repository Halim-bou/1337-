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

void	sig_handel(int sig)
{
	static char	c = 0;
	static int	b = 0;

	if (sig == SIGUSR1)
		c |= (1 << (7 - b));
	b++;
	if (b == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		fflush(stdout);
		c = 0;
		b = 0;
	}
}

int main(void)
{
	struct sigaction sa;

	sa.sa_handler = sig_handel;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || (sigaction(SIGUSR2, &sa, NULL) == -1))
	{
		perror("sigaction failed");
		return EXIT_FAILURE;
	}
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
