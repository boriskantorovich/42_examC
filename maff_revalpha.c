#include <unistd.h>

int		main(void)
{
	char a;
	char c;

	a = 123;
	c = 10;
	while (--a >= 97)
	{
		
		if (a % 2 == 1)
		{
			a -= 32;
			write(1, &a, 1);
			a += 32;
		}
		else
			write(1, &a, 1);
	}
	write(1, &c, 1);
	return (0);
}
