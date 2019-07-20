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

size_t	ft_stlen(char *str)
{
	size_t len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

t_rpn	*ft_readall(char *str)
{
	t_rpn	*list;
	t_rpn	*ptr_list;
	size_t	size;

	if(!(list = (t_rpn *)malloc(sizeof(t_rpn))))
		return (NULL);
	list->next = NULL;
	ptr_list = list;
	size = ft_strlen(str) + 1;

	/*int len = 3;
	hile (len-- && *str != '\0')
	{
		list->nb = atoi(str);
		printf("##	while\n");
		printf("##	list->nb = %d\n", list->nb);
		printf("## char = %c\n", *str);
		list->op = 'x';
		if (*str == '\0')
			break ;
		if ((*str == '+' || *str == '-') && ft_isdigit(*(str + 1)))
		{
			printf("##	+- c = %c\n", *str);
			str++;
		}
		printf("## char = %c\n", *str);
		while (ft_isdigit(*str) && (*(str + 1) != '\0'))
		{
			printf("##	ft_readall_while ft_isdigit c = %c\n", *str);
			str++;
		}
		if (*str == ' ')
			str++;
		if (ft_isop(*str))
			list->op = *str;
		if (*str == ' ')
			str++;
		printf("##	list->op = %c\n", list->op);
		if(!(list->next = (t_rpn *)malloc(sizeof(t_rpn))))
			return (NULL);
		list = list->next;
		str++;	
	}
	 */
	return (ptr_list);
}

int		main(int argc, char **argv)
{
	t_rpn *nbs_and_ops;

	if (argc == 2)
	{
		nbs_and_ops = ft_readall(argv[1]); // read line, pass it, print
		/*while (nbs_and_ops)
		{
			printf("%d	%c	%p\n", nbs_and_ops->nb, nbs_and_ops->op, nbs_and_ops);
			nbs_and_ops = nbs_and_ops->next;
		} */
	}
	else 
		printf("Error\n");
	return (0);
}
