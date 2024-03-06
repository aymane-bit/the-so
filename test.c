# include "../solong.h"

int 	obj_checker(t_obj *object,char *str)
{
	int i = 0;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			object->wall++;
		if (str[i] == '0')
			object->space++;
		if (str[i] == 'E')
			object->exit++;
		if (str[i] == 'C')
			object->collectible++;
		if (str[i] == 'P')
			object->player++;
	i++;
	}
	if (object->player != 1 || object->exit != 1)
	{	
		free(str);
		ft_printf("ERROR : check the map (P or E)\n");
		exit(1);
	}
	ft_printf("all good ser\n");
	return (free(str),0);
}
int 	five_checker(char *str)
{
	int i;
	int d;

	d = strlen(str);
	i = 0;
	while ((str[i] == 'P' || str[i] == 'E' || str[i] == '0'
				|| str[i] == '1' || str[i] == 'C' || str[i] == '\n') && str[i])   
		i++;
	if (d == i)
		return (free(str),0);
	else
		printf("ERROR : the map is not valid");
		exit(1);
}
int component_checker(t_obj *object)
{
	char *str = 0;
	int fd = open("maps/map.ber", O_RDWR);

	str = get_next_line(fd);
	char *str2 = 0;
	while(str)
	{
		str2 = ft_strjoin(str2,str);
		free(str);
		str = get_next_line(fd);
	}

	return 0;
}
