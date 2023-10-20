/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 04:48:08 by rode-lim          #+#    #+#             */
/*   Updated: 2023/10/19 04:48:08 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void ft_send_msg(int pid, char *msg)
{
	int i;
	int bit;
	int signal;

	i = 0;
	while (msg[i] != '\0')
	{
		bit = 0;
		while (bit++ < 8)
		{
			signal = (msg[i] & (1 << (7 - bit))) ? SIGUSR1 : SIGUSR2;
			if (kill(pid, signal) == -1)
				exit(1);
			usleep(50);
		}
		i++;
	}
	bit = 0;
	while (bit++ < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
		usleep(25);
	}
}

void	sig_handler(int sig)
{
	void(sig); //To avoid the warning
	ft_putstr_fd("Message received by server\n", 1);
	exit(0); //Exit the process
} //This function is called when the server receives the message

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || !is_it_pidable(argv[1]))
	{
		ft_putstr_fd("Invalid PID\n", 2);
		ft_putstr_fd("Usage: ./client [server PID] [message]\n", 2);
		exit(0);
	}
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	pid = ft_atoi(argv[1]);
	ft_send_message(pid, argv[2]);
	return (0);
}

//Ign: Ignore the signal; i.e., do nothing, just return
// Term: terminate the process
// Cont: unblock a stopped process
// Stop: block the process