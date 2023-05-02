#include "../../cub3d.h"

int	game_loop(t_game *game)
{
	move(game);
	perform_raycasting(game->player, game->map);
	return (0);
}
