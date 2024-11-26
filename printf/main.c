#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *str = "hey";
	printf("Printf: %p\n", str);
	ft_printf("Ft_printf: %p\n", str);
	printf("%X\n", 10);
	ft_printf("%X\n", 10);
	printf("%d\n", 10);
	ft_printf("%d\n", 10);
	return(1);
}