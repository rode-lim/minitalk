/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 04:39:40 by rode-lim          #+#    #+#             */
/*   Updated: 2023/10/19 04:39:40 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft_withbonus/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

int	is_it_pidable(char *str);
char	*ft_addchar(char *str, char c);

#endif