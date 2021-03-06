#ifndef	_BASE_H_
#define	_BASE_H_

typedef struct	s_terrain
{
	int			i;
	int			x;
	int			y;
	int			color;
	int			num;
	struct s_terrain*	next;
	GtkWidget*		button;
}		t_terrain;

typedef struct	s_env_game
{
	GtkWidget*	label;
	GtkWidget**	button;
	GtkWidget**	hbox;
	GtkWidget*	window;
	GtkWidget*	vbox;
	GtkWidget*	button_score;
	int		score;
	t_terrain*	terrain;
}		env_game;

void	init_score(env_game* game);
int	check_puzzle(t_terrain* terrain);
void	move_left(t_terrain* button, t_terrain* terrain);
void	move_right(t_terrain* button, t_terrain* terrain);
void	move_top(t_terrain* button, t_terrain* terrain);
void	move_bot(t_terrain* button, t_terrain* terrain);
int	check_left(t_terrain* button, t_terrain* terrain);
int	check_right(t_terrain* button, t_terrain* terrain);
int	check_top(t_terrain* button, t_terrain* terrain);
int	check_bot(t_terrain* button, t_terrain* terrain);
void	free_all(env_game* game);
int	check_square(GtkWidget* widget, t_terrain* terrain);
int	check_num(int num, t_terrain* terrain);
void	print_label(int num, GtkWidget* button);
void	generate_all_button(GtkWidget** button, t_terrain* terrain);
void	generated_platform(GtkWidget** hbox, GtkWidget* vbox, GtkWidget** button);
char*	convert_int(int i, char* label);
int	init_game(env_game* game);
int	generate_coord(t_terrain* terrain);
void	assign_button_coord(GtkWidget* widget, t_terrain* terrain, int i);
#endif
