/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:35:21 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/08 14:52:24 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	print_map(t_data *data)
// {
// 	int	i;
// 	i = 0;
// 	while (data->map[i])
// 	{
// 		printf("%s", data->map[i]);
// 		i++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		perror("Error, no file specified.");
		exit (EXIT_FAILURE);
	}
	data.fd = open(argv[1], O_RDONLY);
	ft_bzero(&data, sizeof(data));
	read_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 680, 420, "fdf");
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	return (0);
}
