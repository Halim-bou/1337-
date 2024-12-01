#include "./headers/ft_printf.h"
#include <stdio.h>

void	ft_printf_test(int i, int j)
{
	printf("returns in printf is %d\n", i);
	ft_printf("returns in ft_printf is %d\n", j);
}
int	main(void)
{
	int i, j = 0;
	char *str;

	i = printf("%c\n", 'a');
	j = ft_printf("%c\n", 'a');
	ft_printf_test(i, j);
	i = printf("hello %c\n");
	j = ft_printf("hello%c\n");
	ft_printf_test(i, j);
	//////////////////////////
	i = printf("%p\n", str);
	j = ft_printf("%p\n", str);
	ft_printf_test(i, j);
	i = printf("%p\n", str);
	j = ft_printf("%p\n", str);
	ft_printf_test(i, j);
	str = malloc(1);
	free(str);
	i = printf("%p\n", str);
	j = ft_printf("%p\n", str);
	ft_printf_test(i, j);
	////////////////////////
	str = "hey";
	i = printf("%s\n", str);
	j = ft_printf("%s\n", str);
	ft_printf_test(i, j);
	str = "";
	i = printf("%s\n", str);
	j = ft_printf("%s\n", str);
	ft_printf_test(i, j);
	str = "%";
	i = printf("%s\n", str);
	j = ft_printf("%s\n", str);
	ft_printf_test(i, j);
	str = "hey";
	i = printf("hey %s hey\n", str);
	j = ft_printf("hey %s hey\n", str);
	ft_printf_test(i, j);
	str = "hey there";
	i = printf("%s\n", str);
	j = ft_printf("%s\n", str);
	ft_printf_test(i, j);
	return(1);
}
