#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

int	check_left(t_terrain* button, t_terrain* terrain)
{
	if (button->x >= 1)
	{
		while (terrain->x != button->x - 1 || terrain->y != button->y)
			terrain = terrain->next;
		if (terrain->num == 0)
			return (1);
	}
	return (0);
}

int	check_right(t_terrain* button, t_terrain* terrain)
{
	if (button->x <= 2)
	{
		while (terrain->x != button->x + 1 || terrain->y != button->y)
			terrain = terrain->next;
		if (terrain->num == 0)
			return (1);
	}
	return (0);
}

int	check_top(t_terrain* button, t_terrain* terrain)
{
	if (button->y >= 1)
	{
		while (terrain->x != button->x || terrain->y != button->y - 1)
			terrain = terrain->next;
		if (terrain->num == 0)
			return (1);
	}
	return (0);
}

int	check_bot(t_terrain* button, t_terrain* terrain)
{
	if (button->y <= 2)
	{
		while (terrain->x != button->x || terrain->y != button->y + 1)
			terrain = terrain->next;
		if (terrain->num == 0)
			return (1);
	}
	return (0);
}
