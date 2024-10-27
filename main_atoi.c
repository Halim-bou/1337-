#include "libft.a" // assuming ft_substr and ft_calloc are in libft.h

// void test_ft_substr(char *s, unsigned int start, size_t len, const char *expected)
// {
//     char *result = ft_substr(s, start, len);
//     if (result == NULL)
//     {
//         printf("ft_substr(%s, %u, %zu) returned NULL\n", s, start, len);
//     }
//     else if (strcmp(result, expected) == 0)
//     {
//         printf("SUCCESS: ft_substr(%s, %u, %zu) returned \"%s\"\n", s, start, len, result);
//     }
//     else
//     {
//         printf("FAILURE: ft_substr(%s, %u, %zu) returned \"%s\", expected \"%s\"\n", s, start, len, result, expected);
//     }
//     free(result);
// }

// int main(void)
// {
//     // Test 1: Normal case, substring from the middle
//     test_ft_substr("Hello World", 6, 5, "World");

//     // Test 2: Substring from the start
//     test_ft_substr("Hello World", 0, 5, "Hello");

//     // Test 3: Substring with length exceeding string length
//     test_ft_substr("Hello", 1, 10, "ello");

//     // Test 4: Start index exceeds string length
//     test_ft_substr("Hello", 10, 5, "");

//     // Test 5: Length 0, should return empty string
//     test_ft_substr("Hello", 2, 0, "");

//     // Test 6: Empty string input
//     test_ft_substr("", 0, 5, "");

//     // Test 7: Start from the last character
//     test_ft_substr("Hello", 4, 2, "o");

//     // Test 8: Start index at string length, should return empty string
//     test_ft_substr("Hello", 5, 1, "");

//     // Test 9: Start beyond string length, empty string edge case
//     test_ft_substr("This is a test", 20, 5, "");

//     // Test 10: Substring the entire string
//     test_ft_substr("Complete string", 0, 15, "Complete string");

void test_ft_strjoin(char *s1, char *s2, const char *expected)
{
    char *result = ft_strjoin(s1, s2);
    if (result == NULL)
    {
        printf("ft_strjoin(%s, %s) returned NULL\n", s1, s2);
    }
    else if (strcmp(result, expected) == 0)
    {
        printf("SUCCESS: ft_strjoin(\"%s\", \"%s\") returned \"%s\"\n", s1, s2, result);
    }
    else
    {
        printf("FAILURE: ft_strjoin(\"%s\", \"%s\") returned \"%s\", expected \"%s\"\n", s1, s2, result, expected);
    }
    free(result);
}

void test_ft_strtrim(const char *s1,const char *set, const char *expected)
{
    char *result = ft_strtrim(s1, set);
    if (result == NULL)
    {
        printf("ft_strtrim(%s, %s) returned NULL\n", s1, set);
    }
    else if (strcmp(result, expected) == 0)
    {
        printf("SUCCESS: ft_strtrim(\"%s\", \"%s\") returned \"%s\"\n", s1, set, result);
    }
    else
    {
        printf("FAILURE: ft_strtrim(\"%s\", \"%s\") returned \"%s\", expected \"%s\"\n", s1, set, result, expected);
    }
    free(result);
}

void print_split_result(char **result)
{
    if (!result)
    {
        printf("NULL result\n");
        return;
    }

    int i = 0;
    while (result[i])
    {
        printf("\"%s\"\n", result[i]);
        i++;
    }
    printf("-----\n");
}

// Helper function to free the result array from ft_split
void free_split_result(char **result)
{
    int i = 0;
    if (result)
    {
        while (result[i])
        {
            free(result[i]);
            i++;
        }
        free(result);
    }
}

void test_ft_split(const char *s, char c)
{
    printf("Test: ft_split(\"%s\", '%c')\n", s, c);
    char **result = ft_split(s, c);
    print_split_result(result);
    free_split_result(result);
}

int main(void)
{
    // Test 1: Normal case, join two regular strings
    test_ft_strjoin("Hello", " World", "Hello World");

    // Test 2: First string is empty, join an empty string with a regular string
    test_ft_strjoin("", "World", "World");

    // Test 3: Second string is empty, join a regular string with an empty string
    test_ft_strjoin("Hello", "", "Hello");

    // Test 4: Both strings are empty
    test_ft_strjoin("", "", "");

    // Test 5: First string is NULL
    test_ft_strjoin(NULL, "World", "World");

    // Test 6: Second string is NULL
    test_ft_strjoin("Hello", NULL, "Hello");

    // Test 7: Both strings are NULL
    test_ft_strjoin(NULL, NULL, "");

    // Test 8: Long strings concatenation
    test_ft_strjoin("This is a longer string. ", "And this is another long string.", "This is a longer string. And this is another long string.");

    // Test 9: Join with special characters
    test_ft_strjoin("Hello", " @#$%^&*", "Hello @#$%^&*");

    // Test 10: Numerical strings
    test_ft_strjoin("12345", "67890", "1234567890");
///////////////////////////////////////////////////
printf("#################### STRTRIME TESTS#######3####\n");
    // Test 1: Normal case, join two regular strings
    test_ft_strtrim("Hello   ", "o ", "Hell");

    // Test 2: First string is empty, join an empty string with a regular string
    test_ft_strtrim("   o Hello   ", "o ", "Hell");

    // Test 3: Second string is empty, join a regular string with an empty string
    test_ft_strtrim("  He llo ", " ", "He llo");

    // Test 4: Both strings are empty
    test_ft_strtrim("", "", "");

    // Test 5: First string is NULL
    //test_ft_strtrim(NULL, "World", "World");

    // Test 6: Second string is NULL
    //test_ft_strtrim("Hello", NULL, "Hello");

    // Test 7: Both strings are NULL
    //test_ft_strtrim(NULL, NULL, "");

    // Test 8: Long strings concatenation
    test_ft_strtrim("                               ", " ", "");

    // Test 9: Join with special characters
    test_ft_strtrim("Hello", " .;H", "ello");

    // Test 10: Numerical strings
    test_ft_strtrim("123465", "6", "123465");

    printf("##################### FT_SPLIT TESTS#########\n");

    // Test 1: Simple case with spaces
    test_ft_split("Hello World From ft_split", ' ');

    // Test 2: String with multiple consecutive delimiters
    test_ft_split("Hello,,,World,,From,ft_split", ',');

    // Test 3: String with leading delimiters
    test_ft_split(",,Hello,World", ',');

    // Test 4: String with trailing delimiters
    test_ft_split("Hello,World,,,", ',');

    // Test 5: String with only delimiters
    test_ft_split(",,,,", ',');

    // Test 6: Empty string with delimiter
    test_ft_split("", ',');

    // Test 7: String with no occurrence of delimiter
    test_ft_split("HelloWorld", ',');

    // Test 8: Delimiter at the start and end of string
    test_ft_split(",Hello,World,", ',');

    // Test 9: String with special characters as delimiter
    test_ft_split("Hello$World$From$ft_split", '$');

    // Test 10: String with a single character as input
    test_ft_split("H", ' ');

    // Test 11: String with delimiter but empty tokens (like CSV)
    test_ft_split(",,A,,B,,,C,,", ',');

    // Test 12: Only one token with surrounding delimiters
    test_ft_split(",,,Token,,", ',');

    // Test 13: Empty string with space as delimiter
    test_ft_split("", ' ');

    return 0;
}

