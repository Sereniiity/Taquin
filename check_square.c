#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

int	check_axe(t_terrain* button, t_terrain* terrain)
{
	check_left(button, terrain);
	{
		return (1);
	}
	check_right(button, terrain);
	check_top(button, terrain);
	check_bot(button, terrain);
}

int	check_square(GtkWidget* widget, t_terrain* terrain)
{
	t_terrain*	begin;

	begin = terrain;
	while (terrain->button != widget)
		terrain = terrain->next;
	if (terrain->num == 0)
		return (0);
	if (check_axe(terrain, begin))
		return (1);
	return (0);
}
