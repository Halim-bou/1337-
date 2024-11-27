#include "./headers/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *str = "hey";
	printf("Printf: %p\n", str);
	ft_printf("Ft_printf: %p\n", str);
	printf("%X\n", 42);
	ft_printf("%x\n", 42);
	printf("%d\n", 10);
	ft_printf("%d\n", 10);
	printf("%% \n");
	ft_printf("%%\n");
	return(1);
}
