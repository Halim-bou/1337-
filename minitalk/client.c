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

typedef struct s_data {
    char    *message;
    int     server_pid;
    int     bit_position;
    int     ready_to_send;
    int     char_index;
    int     message_complete;
    int     retries;
} t_data;

t_data g_data;

#define MAX_RETRIES 5
#define USLEEP_TIME 100000  // 100ms

void send_bit(void) {
    int current_char;

    if (g_data.message_complete)
        return;

    current_char = (unsigned char)g_data.message[g_data.char_index];

    // Check if we need to send null terminator
    if (current_char == '\0' && g_data.bit_position == 7) {
        if (kill(g_data.server_pid, SIGUSR2) == -1) {
            write(2, "Error: Failed to send bit to server\n", 36);
            exit(1);
        }
        g_data.message_complete = 1;
        return;
    }

    // Send bit (SIGUSR1 for 1, SIGUSR2 for 0)
    if ((current_char >> g_data.bit_position) & 1) {
        if (kill(g_data.server_pid, SIGUSR1) == -1) {
            write(2, "Error: Failed to send bit to server\n", 36);
            exit(1);
        }
    } else {
        if (kill(g_data.server_pid, SIGUSR2) == -1) {
            write(2, "Error: Failed to send bit to server\n", 36);
            exit(1);
        }
    }

    g_data.ready_to_send = 0;
    g_data.retries = 0;
}

void sig_handler(int sig) {
    if (sig == SIGUSR2) {
        // Message fully received by server
        write(1, "Message delivered successfully\n", 30);
        exit(0);
    }

    // Acknowledgment received, proceed to next bit
    if (g_data.bit_position == 0) {
        g_data.bit_position = 7;
        g_data.char_index++;
    } else {
        g_data.bit_position--;
    }

    g_data.ready_to_send = 1;
    g_data.retries = 0;
    send_bit();
}

int main(int argc, char **argv) {
    struct sigaction sa_usr;

    if (argc != 3) {
        write(2, "Error: Usage: ./client <SERVER_PID> <MESSAGE>\n", 46);
        return (1);
    }

    // Initialize global data structure
    g_data.message = argv[2];
    g_data.server_pid = ft_atoi(argv[1]);
    g_data.bit_position = 7;
    g_data.ready_to_send = 1;
    g_data.char_index = 0;
    g_data.message_complete = 0;
    g_data.retries = 0;

    // Validate server PID
    if (g_data.server_pid <= 0 || kill(g_data.server_pid, 0) == -1) {
        write(2, "Error: Invalid server PID\n", 26);
        return (1);
    }

    // Set up signal handlers
    sa_usr.sa_handler = sig_handler;
    sigemptyset(&sa_usr.sa_mask);
    sa_usr.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa_usr, NULL) == -1 ||
        sigaction(SIGUSR2, &sa_usr, NULL) == -1) {
        write(2, "Error: Failed to set up signal handlers\n", 39);
        return (1);
    }

    // Start transmission
    write(1, "Connecting to server...\n", 23);
    send_bit();

    // Wait for signals with timeout mechanism
    while (!g_data.message_complete) {
        if (!g_data.ready_to_send) {
            usleep(USLEEP_TIME);  // Sleep for a short time
            g_data.retries++;

            if (g_data.retries >= MAX_RETRIES) {
                // Retry sending the bit
                write(1, "Retrying...\n", 12);
                send_bit();
            }
        }
        pause();
    }

    return (0);
}
