# include "solong.h"

int ber_checker(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i--] != 'r')
		return (1);
	if (str[i--] != 'e')
		return (1);
	if (str[i--] != 'b')
		return (1);
	if (str[i--] != '.')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_obj object;

	object.wall = 0;
	object.space = 0;
	object.player = 0;
	object.collectible = 0;
	object.exit = 0;
	if (argc == 2)
	{
		if (ber_checker(argv[1]) == 1)
			return (printf("ERROR : the extension is not .ber\n"));
		map_checker(&object);
		
	}
	else
		return 0;
}
