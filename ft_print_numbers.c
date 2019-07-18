#include "test.h"

void	ft_print_numbers(void)
{
	char nb = 47;

	while (++nb <= '9')
		write(1, &nb, 1);
	return;
}
