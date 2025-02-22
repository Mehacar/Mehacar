/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehacar <mehacar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:20:57 by mehacar           #+#    #+#             */
/*   Updated: 2023/04/09 02:30:54 by mehacar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_window(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, data->width * 64, data->height
			* 64, "SO_LONG");
	data->img[0] = mlx_xpm_file_to_image(data->mlx, PL_FT, &data->imgx,
			&data->imgy);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, GR, &data->imgx,
			&data->imgy);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, WLL, &data->imgx,
			&data->imgy);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, COIN, &data->imgx,
			&data->imgy);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, DOR, &data->imgx,
			&data->imgy);
	hookles(data);
}

void	hookles(t_data *data)
{
	data->coin = 0;
	data->mat_x = 0;
	data->mat_y = 0;
	data->player_num = 0;
	ft_putimages(data);
	player_num_control(data);
	mlx_hook(data->mlx_window, 2, 0, ft_keyboard, data);
	mlx_hook(data->mlx_window, 17, 1L << 0, exit_function, data);
	mlx_loop(data->mlx);
}

void	ft_putimages(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_window);
	while (data->map[data->mat_y])
	{
		data->mat_x = 0;
		while (data->map[data->mat_y][data->mat_x])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1],
				data->mat_x * 64, data->mat_y * 64);
			if (data->map[data->mat_y][data->mat_x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_window,
					data->img[2], data->mat_x * 64, data->mat_y * 64);
			if (data->map[data->mat_y][data->mat_x] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_window,
					data->img[0], data->mat_x * 64, data->mat_y * 64);
				data->position_x = data->mat_x;
				data->position_y = data->mat_y;
				data->player_num++;
			}
			ft_putimages1(data, data->mat_x, data->mat_y);
			data->mat_x++;
		}
		data->mat_y++;
	}
	can_go_exit(data);
}

void	ft_putimages1(t_data *data, int mat_x, int mat_y)
{
	if (data->map[data->mat_y][mat_x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->img[3], mat_x * 64, mat_y * 64);
		data->coin++;
	}
	if (data->map[mat_y][mat_x] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->img[4], mat_x * 64, mat_y * 64);
	}
	if (data->map[mat_y][mat_x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->img[1], mat_x * 64, mat_y * 64);
}

void	ft_key_hook(int keyhook, t_data *data)
{
	if (keyhook == 13 && data->map[data->position_y
			- 1][data->position_x] != '1' && data->map[data->position_y
		- 1][data->position_x] != 'E')
		ft_move_up(data);
	if (keyhook == 0 && data->map[data->position_y][data->position_x - 1] != '1'
		&& data->map[data->position_y][data->position_x - 1] != 'E')
		ft_move_left(data);
	if (keyhook == 1 && data->map[data->position_y + 1][data->position_x] != '1'
		&& data->map[data->position_y + 1][data->position_x] != 'E')
		ft_move_down(data);
	if (keyhook == 2 && data->map[data->position_y][data->position_x + 1] != '1'
		&& data->map[data->position_y][data->position_x + 1] != 'E')
		ft_move_right(data);
	ft_printf("Step : %d\n", data->step);
}
