/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:07:01 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/11 13:58:08 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_hexa(t_data *data, int z, int n)
{

}

void	put_colors(t_data *data, int z)
{
	int	n;

	if (z < 0)
	{
		n = 1;
		z *= -1;

		convert_hexa(data, z, n);
	}
	else
	{
		n = 0;
		convert_hexa(data, z, n);
	}
}