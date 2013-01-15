#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

void	move_right(t_terrain* button, t_terrain* terrain)
{
	GdkColor	white;
	GdkColor	brown;

	gdk_color_parse ("white", &white);
	gdk_color_parse ("brown", &brown);
	while (terrain->x != button->x + 1 || terrain->y != button->y)
		terrain = terrain->next;
	terrain->num = button->num;
	button->num = 0;
	print_label(terrain->num, terrain->button);
	gtk_widget_modify_bg(GTK_WIDGET(terrain->button), GTK_STATE_NORMAL, &brown);
	gtk_widget_modify_bg(GTK_WIDGET(button->button), GTK_STATE_NORMAL, &white);
	gtk_button_set_label(GTK_BUTTON(button->button), " ");
}
