/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehacar <mehacar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:20:28 by mehacar           #+#    #+#             */
/*   Updated: 2023/04/09 02:20:29 by mehacar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_argcheck(char *map[])
{
	int	i;
	int	j;

	j = 0;
	while (*map && map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if ((map[j][i] != 'P') && (map[j][i] != '0') && (map[j][i] != '1')
				&& (map[j][i] != 'E') && (map[j][i] != 'C')
				&& (map[j][i] != '\n'))
			{
				write(1, "Invalid Map!", 13);
				exit(1);
			}
			i++;
		}
		j++;
	}
}

void	exit_check(char *map[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				return ;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	ft_printf("There isn't exit");
	exit(1);
}

void	player_num_control(t_data *data)
{
	if (data->player_num != 1)
	{
		ft_printf("Birden fazla karakter var");
		exit(1);
	}
}
