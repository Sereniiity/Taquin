#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

void	check_left(t_terrain* button, t_terrain* terrain)
{
	while (terrain->x != button->x - 1 && terrain->y != button->y)
		terrain = terrain->next;
	if (terrain->num == 0)
		return (1);
	return (0);
}

void	check_right(t_terrain* button, t_terrain* terrain)
{
	while (terrain->x != button->x + 1 && terrain->y != button->y)
		terrain = terrain->next;
	if (terrain->num == 0)
		return (1);
	return (0);
}

void	check_top(t_terrain* button, t_terrain* terrain)
{
	while (terrain->x != button->x && terrain->y != button->y - 1)
		terrain = terrain->next;
	if (terrain->num == 0)
		return (1);
	return (0);
}

void	check_bot(t_terrain* button, t_terrain* terrain)
{
	while (terrain->x != button->x && terrain->y != button->y + 1)
		terrain = terrain->next;
	if (terrain->num == 0)
		return (1);
	return (0);
}
