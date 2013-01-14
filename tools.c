#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

void	print_label(int num, GtkWidget* button)
{
	char*	label;

	label = malloc(3 * sizeof(char));
	label = convert_int(num, label);
	gtk_button_set_label(GTK_BUTTON(button), (gchar*)label);
	free(label);
}

int	check_num(int num, t_terrain* terrain)
{
	t_terrain*	move;
	int		count;

	count = 0;
	move = terrain;
	while (count != 16)
	{
		printf("%d\n", num);
		if (move->num == num)
			return (1);
		move = move->next;
		count = count + 1;
	}
	return (0);
}

char*	convert_int(int i, char* label)
{
	label[0] = 48 + (i / 10);
	label[1] = 48 + (i % 10);
	label[2] = '\0';
	return (label);
}
