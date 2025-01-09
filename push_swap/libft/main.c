#include <stdio.h>
#include <stdlib.h>
#include "libft.h"  // Adjust this if your ft_split function is in a different file

void print_split(char **result) {
    int i = 0;
    while (result[i]) {
        printf("Segment %d: \"%s\"\n", i, result[i]);
        i++;
    }
}

int main(void) {
    char **result;

    // Test 1: Basic case with regular input
    result = ft_split("Hello World 42", ' ');
    printf("Test 1: Basic split\n");
    print_split(result);
    free(result);

    // Test 2: Multiple consecutive delimiters
    result = ft_split("Hello   World", ' ');
    printf("\nTest 2: Multiple consecutive delimiters\n");
    print_split(result);
    free(result);

    // Test 3: Delimiter at start and end
    result = ft_split("  Hello World  ", ' ');
    printf("\nTest 3: Delimiter at start and end\n");
    print_split(result);
    free(result);

    // Test 4: Only delimiters
    result = ft_split("     ", ' ');
    printf("\nTest 4: Only delimiters\n");
    if (result[0] == NULL) printf("Empty result as expected.\n");
    free(result);

    // Test 5: No delimiters in the string
    result = ft_split("HelloWorld", ' ');
    printf("\nTest 5: No delimiters in the string\n");
    print_split(result);
    free(result);

    // Test 6: Empty string
    result = ft_split("", ' ');
    printf("\nTest 6: Empty string\n");
    if (result[0] == NULL) printf("Empty result as expected.\n");
    free(result);

    // Test 7: Null character as delimiter
    result = ft_split("Hello\0World", '\0');
    printf("\nTest 7: Null character as delimiter\n");
    print_split(result);
    free(result);

    return 0;
}
