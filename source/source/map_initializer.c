/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-mata <ada-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:10:31 by ada-mata          #+#    #+#             */
/*   Updated: 2023/12/08 15:25:58 by ada-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_initializer(t_map *map, char **av)
{
	map->filename = av[1];
	map->moves = 0;
	map->y = 0;
	map->x = 0; 
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
	map->collectibles_remaining = 0;
	map->animation_on = 0;
	map->player_moving = 0;
	map->current_frame = 0;
	map->array = NULL;
}
