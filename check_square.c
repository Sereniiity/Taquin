#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

int	check_puzzle(t_terrain* terrain)
{
	int	count;

	count = 0;
	while (terrain->num == terrain->i + 1)
	{
		terrain = terrain->next;
		count = count + 1;
	}
	if (count == 15)
		return(1);
	return (0);
}

int	check_axe(t_terrain* button, t_terrain* terrain)
{
	if (check_left(button, terrain))
	{
		move_left(button, terrain);
		return (1);
	}
	else if (check_right(button, terrain))
	{
		move_right(button, terrain);
		return (1);
	}
	else if (check_top(button, terrain))
	{
		move_top(button, terrain);
		return (1);
	}
	else if (check_bot(button, terrain))
	{
		move_bot(button, terrain);
		return (1);
	}
	return (0);
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
