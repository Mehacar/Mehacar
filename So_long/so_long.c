/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehacar <mehacar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:10:23 by mehacar           #+#    #+#             */
/*   Updated: 2023/04/09 02:30:10 by mehacar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checking(t_data *data)
{
	left_top_wall_control(data);
	right_bottom_wall_control(data);
	line_control(data);
	find_player(data);
	collectable_control(data);
	unreachable_exit_control(data);
	door_control(data);
	coin_check(data->map);
	exit_check(data->map);
	ft_argcheck(data->map);
}

int	bercheck(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 'r' || s[i - 2] != 'e' || s[i - 3] != 'b' || \
		s[i - 4] != '.' || i < 5)
	{
		ft_printf("Wrong file name!\n");
		return (0);
	}
	return (1);
}

void	mapreader(t_data *data, char *map)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open(map, O_RDWR);
	s = ft_read(fd, data->x);
	data->x = s;
	map_is_space(data);
	data->map = ft_split(s, '\n');
	data->controlmap = ft_split(s, '\n');
	data->height = map_height(data->map);
	data->width = map_width(data->map);
	data->mat_y = data->height;
	data->mat_x = data->width;
	free(s);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		if (!bercheck(av[1]))
			return (0);
		data = ft_calloc(sizeof(t_data), 1);
		data->key = 1;
		data->img = (void **)ft_calloc(sizeof(void *), 5);
		mapreader(data, av[1]);
		map_checking(data);
		ft_window(data);
	}
	else
	{
		ft_printf("Wrong input type. -./so_long map.ber-");
		exit(1);
	}
	free(data->img);
	free(data);
}
