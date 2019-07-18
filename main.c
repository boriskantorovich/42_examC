#include "test.h"
#include <string.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}



void	ft_putnbr_alt(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb *= -1;
	}
	while (nb > 9)
	{
		ft_putnbr(nb/10);
		nb %= 10;
	}
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb *= -1;
	}
	while (nb > 9)
	{
		ft_putnbr(nb/10);
		nb %= 10;
	}
	ft_putchar(nb % 10 + '0');
}

int		main(void)
{
	char nl = '\n';
	char *s = "Hello world class m df class class";
	int i;

	i = ft_strlen(s);
	ft_putnbr(i);
	write(1, &nl, 1);
	ft_print_numbers();
	write(1, &nl, 1);
	return (0);
}
