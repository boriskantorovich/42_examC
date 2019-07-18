/*
Allowed functions: atoi, printf, write, malloc, free

Write a program that takes a string which contains an equation written in
Reverse Polish notation (RPN) as its first argument, evaluates the equation, and
prints the result on the standard output followed by a newline. 

Reverse Polish Notation is a mathematical notation in which every operator
follows all of its operands. In RPN, every operator encountered evaluates the
previous 2 operands, and the result of this operation then becomes the first of
the two operands for the subsequent operator. Operands and operators must be
spaced by at least one space.

You must implement the following operators : "+", "-", "*", "/", and "%".

If the string isn't valid or there isn't exactly one argument, you must print
"Error" on the standard output followed by a newline.

All the given operands must fit in a "int".

Examples of formulas converted in RPN:

3 + 4                   >>    3 4 +
((1 * 2) * 3) - 4       >>    1 2 * 3 * 4 -  ou  3 1 2 * * 4 -
50 * (5 - (10 / 9))     >>    5 10 9 / - 50 *

Here's how to evaluate a formula in RPN:

1 2 * 3 * 4 -
2 3 * 4 -
6 4 -
2

Or:

3 1 2 * * 4 -
3 2 * 4 -
6 4 -
2

Examples:

$> ./rpn_calc "1 2 * 3 * 4 +" | cat -e
10$
$> ./rpn_calc "1 2 3 4 +" | cat -e
Error$
$> ./rpn_calc |cat -e
Error$
 */

/*
Prototype
1. Read the line
2. Pass it to the arguments
3. Make operations
4. Return value
5. Print it
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct		s_rpn
{
	int				nb;
	char			op;
	struct s_rpn	*next;
}					t_rpn;

int		ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	else	
		return (0);
}

int		ft_isop(char c)
{
	if (c == '-' || c == '+' || c == '*' || c == '/' || c == '%')
		return (1);
	else	
		return (0);
}

t_rpn	*ft_readall(char *str)
{
	t_rpn	*list;
	t_rpn	*ptr_list;

	printf("##	ft_readall\n");
	if(!(list = (t_rpn *)malloc(sizeof(t_rpn))))
		return (NULL);
	list->next = NULL;
	ptr_list = list;
	printf("##	ft_readall 2\n");
	while (*str)
	{
		printf("##	ft_readall_while\n");
		list->nb = atoi(str);
		list->op = 'x';
		while (ft_isdigit(*str))
		{
			printf("##	ft_readall_while ft_isdigit\n");
			str++;
		}
		printf("##	ft_readall_while 2\n");
		if (*str == ' ')
			str++;
		/*
		if (ft_isop(*str))
			list->op = *str;
		str++;
		list = list->next;
		*/
	}
	return (ptr_list);
}

int		main(int argc, char **argv)
{
	t_rpn *nbs_and_ops;

	if (argc == 2)
	{
		nbs_and_ops = ft_readall(argv[1]); // read line, pass it, print
		while (nbs_and_ops)
		{
			printf("%d	%c	%p\n", nbs_and_ops->nb, nbs_and_ops->op, nbs_and_ops);
			nbs_and_ops = nbs_and_ops->next;
		}
	}
	else 
		printf("Error\n");
	return (0);
}
