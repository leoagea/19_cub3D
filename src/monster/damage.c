#include "../../inc/cub3d.h"

void take_damage(t_player *player)
{
	player->hp = player->hp - 1;
	if (player->hp == 0)
		exit (1); //LEAK
}