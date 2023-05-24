// Ces fonctions devront être supprimé pour l'examen.
// Ces fonctions sont utiles pour débugé la map concernant de chaque erreur possible.

int	ft_map_space_error(char **map, int actual, int i, int y)
{
	if (map[actual][i] == ' ')
	{
		if (i - 1 >= 0 && map[actual][i - 1] == '0')
		{
			printf("Erreur! Il y a un '0' sur la gauche de l'espace. Le résultat : map[actual][i - 1] = [%c] et débug x [%d] y [%d]\n", map[actual][i - 1], actual, i - 1);
		}
		if (map[actual][i + 1] == '0')
		{
			printf("Erreur! Il y a un '0' sur la droite de l'espace. Le résultat : map[actual][i + 1] = [%c] et débug x [%d] y [%d]\n", map[actual][i + 1], actual, i + 1);
		}
		if (actual + 1 != y && map[actual + 1][i] == '0')
		{
		printf("Erreur! Il y a un '0' sur la ligne d'après l'espace. Le résultat : map[actual + 1][i] = [%c] et débug x [%d] y [%d]\n", map[actual + 1][i], actual + 1, i);
		}
		if (actual != 0 && map[actual - 1][i] == '0')
		{
			printf("Erreur! Il y a un '0' sur la ligne d'avant l'espace. Le résultat : map[actual - 1][i] = [%c] et débug x [%d] y [%d]\n", map[actual - 1][i], actual - 1, i);
		}
	}
	return (0);
}

int	ft_map_zero_error(char **map, int actual, int i, int y)
{
	if (map[actual][i] == '0')
	{
		if (map[actual][i + 1] != '1')
		{
			if (map[actual][i + 1] != '0' && map[actual][i + 1] != 'N' && map[actual][i + 1] != 'S' && map[actual][i + 1] != 'E' && map[actual][i + 1] != 'W')
			{
				printf("Erreur! Mur manquant à droite du vide. Le résultat : map[actual][i + 1] = [%c] et debug x [%d] y [%d]\n", map[actual][i + 1], actual, i + 1);
			}
		}
		if (map[actual][i - 1] != '1')
		{
			if (map[actual][i - 1] != '0' && map[actual][i - 1] != 'N' && map[actual][i - 1] != 'S' && map[actual][i - 1] != 'E' && map[actual][i - 1] != 'W')
			{
				printf("Erreur! Mur manquant à gauche du vide. Le résultat : map[actual][i - 1] = [%c] et debug x [%d] y [%d]\n", map[actual][i - 1], actual, i - 1);
			}
		}
		if (actual + 1 != y && map[actual + 1][i] != '1')
		{
			if (map[actual + 1][i] != '0' && map[actual + 1][i] != 'N' && map[actual + 1][i] != 'S' && map[actual + 1][i] != 'E' && map[actual + 1][i] != 'W')
			{
				printf("Erreur! Mur manquant sur la ligne suivante du vide. Le résultat : map[actual + 1][i] = [%c] et debug x [%d] y [%d]\n", map[actual + 1][i], actual + 1, i);
			}
		}
		if (actual != 0 && map[actual - 1][i] != '1')
		{
			if (map[actual - 1][i] != '0' && map[actual - 1][i] != 'N' && map[actual - 1][i] != 'S' && map[actual - 1][i] != 'E' && map[actual - 1][i] != 'W')
			{
				printf("Erreur ! Mur manquant sur la ligne avant du vide. Le résultat : map[actual - 1][i] = [%c] et debug x [%d] y [%d]\n", map[actual - 1][i], actual - 1, i);
			}
		}
		if (actual + 1 == y)
		{
			printf("Erreur! Il y a un vide sur la dernière ligne! Le résultat : map[actual][i] = [%c] et debug x [%d] y [%d]\n", map[actual][i], actual, i);
		}
	}
	return (0);
}

int	ft_map_player_error(char **map, int actual, int i, int y)
{
	if (map[actual][i] == 'N' || map[actual][i] == 'S' || map[actual][i] == 'E' || map[actual][i] == 'W')
	{
		if (i - 1 >= 0 && (map[actual][i - 1] != '0' && map[actual][i - 1] != '1'))
		{
			printf("Erreur! Position hors map sur la gauche. Le résultat : map[actual][i - 1] = [%c] et débug x [%d] y [%d]\n", map[actual][i - 1], actual, i - 1);
		}
		if (map[actual][i + 1] != '0' && map[actual][i + 1] != '1')
		{
			printf("Erreur! Position hors map sur la droite. Le résultat : map[actual][i + 1] = [%c] et débug x [%d] y [%d]\n", map[actual][i + 1], actual, i + 1);
		}
		if (actual + 1 != y && (map[actual + 1][i] != '0' && map[actual + 1][i] != '1'))
		{
			printf("Erreur! Position hors map sur la ligne d'après. Le résultat : map[actual + 1][i] = [%c] et débug x [%d] y [%d]\n", map[actual + 1][i], actual + 1, i);
		}
		if (actual != 0 && (map[actual - 1][i] != '0' && map[actual - 1][i] != '1'))
		{
			printf("Erreur! Position hors map sur la ligne d'avant. Le résultat : map[actual - 1][i] = [%c] et débug x [%d] y [%d]\n", map[actual - 1][i], actual - 1, i);
		}
		if (actual + 1 == y)
		{
			printf("Erreur! Position hors map sur la dernière ligne. Le résultat : map[actual][i] = [%c] et debug x [%d] y [%d]\n", map[actual][i], actual, i);
		}
	}
	return (0);
}

int	ft_map_char_error(char **map, int actual, int i)
{
	if (map[actual][i] != ' ' && map[actual][i] != '1' && map[actual][i] != '0' && map[actual][i] != 'N' && map[actual][i] != 'S' && map[actual][i] != 'W' && map[actual][i] != 'E')
	{
		printf("Erreur! Caractère non valide dans la carte!\n");
	}
	return (0);
}

int	ft_map_wall_error(char **map, int actual, int i, int y)
{
	if (map[actual][i] == '1')
	{
		if (map[actual][i + 1] != ' ' && map[actual][i + 1] != '1' && map[actual][i + 1] != '\0')
		{
			if (map[actual][i + 1] != '0' && map[actual][i + 1] != 'N' && map[actual][i + 1] != 'S' && map[actual][i + 1] != 'E' && map[actual][i + 1] != 'W')
			{
				printf("Erreur! Mur manquant à droite du vide. Le résultat : map[actual][i + 1] = [%c] et debug x [%d] y [%d]\n", map[actual][i + 1], actual, i + 1);
			}
		}
		if (i - 1 > -1 && map[actual][i - 1] != ' ' && map[actual][i - 1] != '1' && map[actual][i - 1] != '\0')
		{
			if (map[actual][i - 1] != '0' && map[actual][i - 1] != 'N' && map[actual][i - 1] != 'S' && map[actual][i - 1] != 'E' && map[actual][i - 1] != 'W')
			{
				printf("Erreur! Mur manquant à gauche du vide. Le résultat : map[actual][i - 1] = [%c] et debug x [%d] y [%d]\n", map[actual][i - 1], actual, i - 1);
			}
		}
		if (actual + 1 != y && map[actual + 1][i] != ' ' && map[actual + 1][i] != '1' && map[actual + 1][i] != '\0')
		{
			if (map[actual + 1][i] != '0' && map[actual + 1][i] != 'N' && map[actual + 1][i] != 'S' && map[actual + 1][i] != 'E' && map[actual + 1][i] != 'W')
			{
				printf("Erreur! Mur manquant sur la ligne suivante du vide. Le résultat : map[actual + 1][i] = [%c] et debug x [%d] y [%d]\n", map[actual + 1][i], actual + 1, i);
			}
		}
		if (actual != 0  && map[actual - 1][i] != ' ' && map[actual - 1][i] != '1' && map[actual - 1][i] != '\0')
		{
			if (map[actual - 1][i] != '0' && map[actual - 1][i] != 'N' && map[actual - 1][i] != 'S' && map[actual - 1][i] != 'E' && map[actual - 1][i] != 'W')
			{
				printf("Erreur ! Mur manquant sur la ligne avant du vide. Le résultat : map[actual - 1][i] = [%c] et debug x [%d] y [%d]\n", map[actual - 1][i], actual - 1, i);
			}
		}
	}
	return (0);
}