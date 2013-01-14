#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "base.h"

t_terrain*	generate_color(int i, int x, int y, t_terrain* terrain)
{
	terrain->i = i;
	terrain->x = x;
	terrain->y = y;
	terrain->num = 0;
	if (i == 15)
		terrain->color = 0;
	else
		terrain->color = 1;
	return (terrain);
}

int	generate_coord(t_terrain* terrain)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i != 16)
	{
		x = 0;
		while (x != 4)
		{
			terrain->next = malloc(sizeof(t_terrain));
			if (terrain->next == 0)
				return (1);
			terrain = generate_color(i, x, y, terrain);
			terrain = terrain->next;
			x = x + 1;
			i = i + 1;
		}
		y = y + 1;
	}
	return (0);
}
