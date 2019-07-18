#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(const char *s)
{
	while(*s)
		ft_putchar(*(s++));
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	if (argc-- > 1)
		ft_putendl(argv[argc]);
	else 
		ft_putchar('\n');
	return (0);
}
