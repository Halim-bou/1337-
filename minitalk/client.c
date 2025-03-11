/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-11 00:32:56 by abelboua          #+#    #+#             */
/*   Updated: 2025-03-11 00:32:56 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/mini_talk.h"

typedef struct s_data {
	char	*message;
	int		server_pid;
	int		bit_position;
	int		char_index;
} t_data;

t_data g_data;

void	send_kill(int sig)
{
	if (kill(g_data.server_pid, sig) == -1)
	{
		write(2, "Error: Failed to send bit to server\n", 36);
		exit(1);
	}
}

void send_bit(void)
{
	int current_char;

	current_char = (unsigned char)g_data.message[g_data.char_index];
	if (current_char == '\0' && g_data.bit_position == 7)
	{
		send_kill(SIGUSR2);
		return;
	}
	if ((current_char >> g_data.bit_position) & 1)
		send_kill(SIGUSR1);
	else
		send_kill(SIGUSR2);
}

void sig_handler(int sig)
{
    if (sig == SIGUSR2)
    {
        write(1, "\nMessage was send successfuly\n", 31);
        exit(0);
    }
	else if (g_data.bit_position == 0)
	{
		g_data.bit_position = 7;
		g_data.char_index++;
        if (g_data.message[g_data.char_index -1] == '\0')
            exit(0);
	}
	else
		g_data.bit_position--;
	send_bit();
}

int main(int argc, char **argv)
{
	struct sigaction    sa_usr;

	if (argc != 3)
	{
		write(2, "Error: Usage: ./client <SERVER_PID> <MESSAGE>\n", 46);
		return (1);
	}
	g_data.message = argv[2];
	g_data.server_pid = ft_atoi(argv[1]);
	g_data.bit_position = 7;
	g_data.char_index = 0;
	g_data.message_complete = 0;
	if (g_data.server_pid <= 0 || kill(g_data.server_pid, 0) == -1)
	{
		write(2, "Error: Invalid server PID\n", 26);
		return (1);
    }
	sa_usr.sa_handler = sig_handler;
	sigemptyset(&sa_usr.sa_mask);
	sa_usr.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa_usr, NULL) == -1
		|| sigaction(SIGUSR2, &sa_usr, NULL) == -1)
	{
		write(2, "Error: Failed to set up signal handlers\n", 39);
		return (1);
	}
	send_bit();
	while (1)
		pause();
	return (0);
}
