/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:32:02 by rode-lim          #+#    #+#             */
/*   Updated: 2023/10/20 03:32:02 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum, siginfo_t *info, void *s)
{
	static unsigned char	c = 0xFF;//Initialize the char to 0xFF
	static int				bit = 0;//Initialize the bit to 0
	static char				*str = 0;//Initialize the string to 0

	(void)s;//To avoid the warning
	if (signum == SIGUSR1)//If the signal is SR1
		c |= 0x80 >> bit;//Set the bit to 1
	else if (signum == SIGUSR2)//If the signal is SR2
		c ^= 0x80 >> bit;//Set the bit to 0
	if (++bit == 8)
	{
		if (c)
			str = ft_addchar(str, c);//Add the char to the string
		else
		{
			ft_putstr_fd(str, 1);//Print the string
			if (kill(info->si_pid, SIGURS2) == -1)
				exit (1);//Exit if the kill fails
			str = 0;//Set the string to 0
		}
		bit = 0;//Set the bit to 0
		c = 0xFF;//Set the char to 0xFF
	}
}

int	main(void)
{
	struct sigaction	sig;//Struct to handle signals in signal.h
	sigset_t			blocker;//struct to block signals in signal.h
	pid_t				pid;//Process ID
	
	sigemptyset(&blocker);//Initialize the signal set pointed to by blocker~
	sigaddset(&blocker, SIGUSR1);//AddSR1 to the signl set pointed toby block
	sigaddset(&blocker, SIGUSR2);//AddSR2 to the signl set pointed toby block
	sig.sa_flags = SA_SIGINFO;//Set the flags to SA_SIGINFO
	sig.sa_sigaction = sig_handler;//Set the handler to sig_handler
	pid = getpid();//Get the process ID
	ft_putstr_fd("PID: ", 1);//Print the PID
	ft_putnbr_fd(pid, 1);//Print the PID
	ft_putchar_fd('\n', 1);//Print a new line
	sigaction(SIGUSR1, &sig, NULL);//Set the action for SR1
	sigaction(SIGUSR2, &sig, NULL);//Set the action for SR2
	while (1)//Infinite loop
	{
		pause();//Pause the process
	}
}
