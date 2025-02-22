/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehacar <mehacar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:21:16 by mehacar           #+#    #+#             */
/*   Updated: 2023/04/09 02:22:58 by mehacar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int key, t_data *data)
{
	(void)data;
	if (key == 53)
		exit(0);
	return (0);
}

int	mouse(int button, int x, int y, t_data *data)
{
	int	z;

	z = x + y + button;
	(void)z;
	(void)data;
	return (0);
}

void	can_go_exit(t_data *data)
{
	char	*coin;

	coin = ft_itoa(data->coin);
	mlx_string_put(data->mlx, data->mlx_window, 10, 50, 0x00FF00, "COIN : ");
	mlx_string_put(data->mlx, data->mlx_window, 80, 50, 0x00FF00, coin);
	free(coin);
	if (data->coin == 0)
	{
		mlx_string_put(data->mlx, data->mlx_window, 10, 82, 0xFFFFFF,
			"You can go door!");
	}
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->controlmap[i])
	{
		j = 0;
		while (data->controlmap[i][j])
		{
			if (data->controlmap[i][j] == 'P')
			{
				recursive_control(data, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_keyboard(int keyhook, t_data *data)
{
	ft_putimages(data);
	if (keyhook == 53)
	{
		exit_function(data);
	}
	if (data->coin == 0 && ((keyhook == 2 \
				&& data->map[data->position_y][data->position_x + 1] == 'E') \
			|| (keyhook == 1 && data->map[data->position_y
				+ 1][data->position_x] == 'E') || (keyhook == 0
				&& data->map[data->position_y][data->position_x - 1] == 'E')
			|| (keyhook == 13 && data->map[data->position_y
				- 1][data->position_x] == 'E')))
	{
		ft_printf("Steps: %d\n", data->step + 1);
		ft_printf("Game Over! You Win!\n");
		free(data->img);
		exit(1);
	}
	ft_key_hook(keyhook, data);
	hookles(data);
	return (0);
}
