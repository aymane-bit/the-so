# include "libft.h"

int main()
{
	int fd = open("Makefile", O_RDWR);
	char *str = get_next_line(fd);
	while(str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
}