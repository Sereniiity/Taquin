#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

void	free_terrain(t_terrain*	terrain)
{
	t_terrain*	tmp;
	int		count;

	count = 0;
	while (count != 15)
	{
		tmp = terrain->next;
		free(terrain);
		terrain = tmp;
		count = count + 1;
	}
	free(terrain);
}

void	free_all(env_game* game)
{
	free_terrain(game->terrain);
}
