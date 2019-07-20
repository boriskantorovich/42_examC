#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
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

void	ft_printhex(int n)
{
	int c;

	if (n >= 16)
		ft_printhex(n / 16);
	c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	ft_putchar(c);
}

void	ft_printchars(unsigned char c)
{
	ft_putchar((c > 31 && c < 127) ? c : '.');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*t;
	size_t			i;
	size_t			tmp;
	int				col;
	size_t			j;

	i = 0;
	j = 0;
	t = (unsigned char *)addr;
	while (j < size)
	{
		ft_putchar(t[j]);
		j++;
	}
	j = 0;
	ft_putchar('\n');
	while (j < size)
	{
		ft_putnbr(t[j]);
		j++;
	}
	ft_putchar('\n');
	while (i < size)
	{
		col = -1;
		tmp = i;
		while (++col < 16)
		{
			if (i < size)
			{
				if (t[i] < 16)
					ft_putchar('0');
				ft_printhex(t[i]);
			}
			else
				ft_putstr("  ");
			if (i % 2)
				ft_putchar(' ');
			i++;
		}
		col = -1;
		i = tmp;
		while (++col < 16 && i < size)
			ft_printchars(t[i++]);
		ft_putchar('\n');
	}
}
