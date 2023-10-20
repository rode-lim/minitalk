/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 04:53:34 by rode-lim          #+#    #+#             */
/*   Updated: 2023/10/19 04:53:34 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_it_pidable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
} //our server needs a pid, so we need to check if the pid is valid

static char	*ft_stradd_first(char c)
{
	char	*add;

	add = (char *)malloc(sizeof(char) * 2);
	if (add == NULL)
		return (NULL);
	add[0] = c;
	add[1] = '\0';
	return (add);
}

char	*ft_addchar(char *str, char c)
{
	char	*temp;
	char		i;

	if (!c)
		return (0);
	if (!str)
		return (ft_stradd_first(c));
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (temp == NULL)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		temp[i] = str[i];
	free(str);
	temp[i] = c;
	temp[i++] = '\0';
	return (temp);
} //this function is used to add a char to a string