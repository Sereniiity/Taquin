#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

static void	destroy(GtkWidget* widget, gpointer data)
{
	struct s_env_game*      game;
	(void)	widget;

	game = data;
	free_all(game);
	gtk_main_quit();
}

static void	move(GtkWidget* widget, gpointer data)
{
	env_game*	game;
	t_terrain*	terrain;

	game = data;
	terrain = game->terrain;
	if (check_square(widget, terrain))
	{
		if (check_puzzle(terrain))
			printf("c'est win\n");
	}
}

int		main(int argc, char** argv)
{
	env_game	game;
	int		i;
	(void)		argc;
	(void)		argv;

	i = 0;
	gtk_init(&argc, &argv);
	if (init_game(&game))
		return (0);
	init_score(&game);
	gtk_window_set_position(GTK_WINDOW(game.window),GTK_WIN_POS_CENTER); 
	generate_all_button(game.button, game.terrain);
	g_signal_connect(game.window, "destroy", G_CALLBACK(destroy), &game);
	while (i != 16)
	{
		g_signal_connect(game.button[i], "clicked", G_CALLBACK(move), &game);
		assign_button_coord(game.button[i], game.terrain, i);
		i = i + 1;
	}
	generated_platform(game.hbox, game.vbox, game.button);
	gtk_container_add(GTK_CONTAINER(game.window), GTK_WIDGET(game.vbox));
	gtk_widget_show_all(game.window);
	gtk_main();
	return (0);
}
