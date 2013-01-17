#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

void	init_score(env_game* game)
{
	GdkColor	button;

	gdk_color_parse ("green", &button);
	game->button_score = gtk_button_new_with_label("0");
	game->label = gtk_label_new("Bienvenue sur le jeu du Taquin");
	gtk_widget_modify_bg(GTK_WIDGET(game->button_score), GTK_STATE_NORMAL, &button);
	gtk_box_pack_start(GTK_BOX(game->hbox[0]), game->button_score, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(game->hbox[0]), game->label, TRUE, TRUE, 0);
}
