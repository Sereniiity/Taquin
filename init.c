#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

void	generate_label(int i, t_terrain* terrain, GtkWidget* button)
{
	t_terrain*	move;
	int		num;
	int		ret;

	srand((unsigned)time(NULL));
	move = terrain;
	while (move->i != i)
		move = move->next;
	num = rand()%15;
	ret = check_num(num, terrain);
	while (ret != 0)
	{
		num = rand()%16;
		ret = check_num(num, terrain);
	}
	move->num = num;
	print_label(num, button);
}

void	assign_button_coord(GtkWidget* widget, t_terrain* terrain, int i)
{
	int	a;

	a = 0;
	while (a != i)
	{
		terrain = terrain->next;
		a = a + 1;
	}
	terrain->button = widget;
}

void	generated_platform(GtkWidget** hbox, GtkWidget* vbox, GtkWidget** button)
{
	int	i;
	int	j;
	int	b;

	i = 1;
	b = 0;
	while (i != 5)
	{
		hbox[i] = gtk_hbox_new(TRUE, 0);
		j = 0;
		while (j != 4)
		{
			gtk_box_pack_start(GTK_BOX(hbox[i]), button[b], TRUE, TRUE, 0);
			j = j + 1;
			b = b + 1;
		}
		gtk_box_pack_start(GTK_BOX(vbox), hbox[i], TRUE, TRUE, 0);
		i = i + 1;
	}
}

void	generate_all_button(GtkWidget** button, t_terrain* terrain)
{
	int		i;
	GdkColor	white;
	GdkColor	brown;

	gdk_color_parse ("white", &white);
	gdk_color_parse ("brown", &brown);
	i = 0;
	while (i != 16)
	{
		button[i] = gtk_button_new();
		if (i != 15)
			generate_label(i, terrain, button[i]);
		gtk_widget_modify_bg(GTK_WIDGET(button[i]), GTK_STATE_PRELIGHT, &white);
		gtk_widget_modify_bg(GTK_WIDGET(button[i]), GTK_STATE_NORMAL, &brown);
		if (i == 15)
			gtk_widget_modify_bg(GTK_WIDGET(button[i]), GTK_STATE_NORMAL, &white);
		i = i + 1;
	}
}

int	init_game(env_game* game)
{
	game->vbox = gtk_vbox_new(TRUE, 0);
	game->button = malloc(16 * sizeof(GtkWidget*));
	if (game->button == 0)
		return (1);
	game->terrain = malloc(sizeof(t_terrain));
	if (game->terrain == 0)
		return (1);
	game->hbox = malloc(5 * sizeof(GtkWidget*));
	if (game->hbox == 0)
		return (1);
	if(generate_coord(game->terrain))
		return (1);
	game->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(game->window), 800, 800);
	gtk_window_set_position(GTK_WINDOW(game->window),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(game->window), 0);
	game->hbox[0] = gtk_hbox_new(TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->vbox), game->hbox[0], TRUE, TRUE, 0);
	return (0);
}
