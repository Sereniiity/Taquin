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
