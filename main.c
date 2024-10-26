#include "libft.h"

void print_array(const char *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("'%c' ", arr[i]);
    }
    printf("\n");
}
void print_str(const char *str, size_t len) {
    if (str)
        printf("Found string: %.*s\n", (int)len, str);
    else
        printf("Not found\n");
}

// Helper function to test ft_memcmp against memcmp
void test_memcmp(const void *s1, const void *s2, size_t n, const char *test_name) {
    int result_ft = ft_memcmp(s1, s2, n);
    int result_lib = memcmp(s1, s2, n);

    if (result_ft == result_lib) {
        printf("Test %s: PASSED\n", test_name);
    } else {
        printf("Test %s: FAILED (ft_memcmp: %d, memcmp: %d)\n", test_name, result_ft, result_lib);
    }
}

// Helper function to test ft_strlcpy against strlcpy
void test_strlcpy(const char *src, size_t size, const char *test_name) {
    char dst1[100]; // Destination buffer for standard strlcpy
    char dst2[100]; // Destination buffer for ft_strlcpy
    size_t result_lib;
    size_t result_ft;

    // Copy using standard strlcpy
    memset(dst1, 0, sizeof(dst1)); // Clear the buffer
    result_lib = strlcpy(dst1, src, size);

    // Copy using custom ft_strlcpy
    memset(dst2, 0, sizeof(dst2)); // Clear the buffer
    result_ft = ft_strlcpy(dst2, src, size);

    // Compare results
    if (result_lib == result_ft && strcmp(dst1, dst2) == 0) {
        printf("Test %s: PASSED\n", test_name);
    } else {
        printf("Test %s: FAILED (strlcpy: %zu, ft_strlcpy: %zu, dst1: '%s', dst2: '%s')\n",
               test_name, result_lib, result_ft, dst1, dst2);
    }
}

int main(void) {
	char buffer[10];

	printf("###### MEMSET TESTS ###############");
	memset(buffer, 'A', sizeof(buffer));
	printf("Initial buffer:\n");
    print_array(buffer, sizeof(buffer));

	ft_memset(buffer, 'A', sizeof(buffer));
    printf("Initial buffer:\n");
    print_array(buffer, sizeof(buffer));

	printf("#####################");

    // Use memset to set part of the buffer to 'B'
    memset(buffer, 'B', 10); // Set 10 bytes starting from index 5 to 'B'
	printf("Buffer after memset:\n");
    print_array(buffer, sizeof(buffer));

	ft_memset(buffer, 'B', 10); // Set 10 bytes starting from index 5 to 'B'
    printf("Buffer after memset:\n");
    print_array(buffer, sizeof(buffer));

	printf("#####################");
    /*
    // Use memset to clear the buffer
    memset(buffer, 0, sizeof(buffer)); // Clear the entire buffer
	printf("Buffer after clearing:\n");
    print_array(buffer, sizeof(buffer));

	ft_memset(buffer, 0, sizeof(buffer));
	printf("Buffer after clearing:\n");
    print_array(buffer, sizeof(buffer));
    */
/*
	printf("######### BZERO TEST ##############\n");
	 bzero(buffer, 5);
	 printf("Buffer after bzero: ");
    print_array(buffer, sizeof(buffer));
    // Use ft_bzero to set the first 10 bytes of buffer2 to zero
    ft_bzero(buffer, 10);

    printf("Buffer after ft_bzero: ");
    print_array(buffer, sizeof(buffer));

	printf("END");
    return 0;
*/
    printf("###### MEMCPY TESTS ###############\n");
    char src[50] = "This is a memcpy test.";
    char dest1[50];
    char dest2[50];

    // Test standard memcpy
    memcpy(dest1, src, strlen(src) + 1);
    // Test custom ft_memcpy
    ft_memcpy(dest2, src, strlen(src) + 1);

    // Compare the results
    if (strcmp(dest1, dest2) == 0) {
        printf("Both memcpy and ft_memcpy give the same result: %s\n", dest1);
    } else {
        printf("memcpy: %s\n", dest1);
        printf("ft_memcpy: %s\n", dest2);
    }

    printf("#############3 MEMMOVE TESTS ################\n");

    printf("###### MEMCPY TESTS ###############\n");
    char src1[50] = "This is a memcpy test.";
    char src2[50] = "This is a memcpy test.";

    // Test standard memcpy
    memmove(src1 + 5, src1, strlen(src1) + 1);
    // Test custom ft_memcpy
    ft_memmove(src2 + 5, src2, strlen(src2) + 1);

    // Compare the results
    if (strcmp(src1, src2) == 0) {
        printf("Both memmove and ft_memmove give the same result: %s\n", dest1);
    }
    printf("memmove: %s\n", src1);
    printf("ft_memmove: %s\n", src2);


    printf("############## ft_strchar tests #############\n");

    char test_strchr[50] = "This is a strchr test.";
    printf("%s\n", ft_strchr(test_strchr, 'a'));
    //printf("%s\n", ft_strchr(test_strchr, 'o'));
    printf("############### strchar cmp\n");
    printf("%s\n", strchr(test_strchr, 'a'));
    //printf("%s\n", strchr(test_strchr, 'o'));

    printf("###########3 ft_strrchr tests ###########3###\n");

    char test_strrchr[50] = "aThis is  strrchr test.";
    printf("%s\n", ft_strrchr(test_strrchr, 'a'));
    // printf("%s\n", ft_strrchr(test_strrchr, 'o'));
    printf("############### strchar cmp\n");
    printf("%s\n", strrchr(test_strrchr, 'a'));
    // printf("%s\n", strrchr(test_strrchr, 'o'));

    printf("###########3 ft_memchr tests ###########3###\n");

    char test_memchr[50] = "This is a memchr test.";
    printf("%p\n", ft_memchr(test_memchr, 'a', 12));
    // printf("%s\n", ft_memchr(test_memchr, 'o'));
    printf("############### memchr cmp\n");
    printf("%p\n", memchr(test_memchr, 'a', 12));
    // printf("%s\n", memchr(test_memchr, 'o'));

    printf("#################### FT_MEMCMP TESTS ###############\n");
     char test1_a[] = {0x01, 0x02, 0x03};
    char test1_b[] = {0x01, 0x02, 0x03};
    test_memcmp(test1_a, test1_b, 3, "Basic equality");

    // 2. Basic inequality
    char test2_a[] = {0x01, 0x02, 0x03};
    char test2_b[] = {0x01, 0x02, 0x04};
    test_memcmp(test2_a, test2_b, 3, "Basic inequality");

    // 3. Empty memory comparison
    char test3_a[] = "";
    char test3_b[] = "";
    test_memcmp(test3_a, test3_b, 0, "Empty memory comparison");

    // 4. Partial comparison (should compare first N bytes)
    char test4_a[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    char test4_b[] = {0x01, 0x02, 0x03, 0x00, 0x00}; // Last bytes differ
    test_memcmp(test4_a, test4_b, 3, "Partial comparison");

    // 5. Overlapping memory (should still work correctly for memcmp)
    char test5[] = "Hello, World!";
    test_memcmp(test5, test5 + 7, 5, "Overlapping memory comparison");

    // 6. Large buffer comparison
    char test6_a[1000], test6_b[1000];
    memset(test6_a, 0x55, 1000); // Fill with 0x55
    memset(test6_b, 0x55, 1000); // Same pattern
    test_memcmp(test6_a, test6_b, 1000, "Large buffer comparison");

    // 7. Binary data comparison (including null bytes)
    char test7_a[] = {0x00, 0x01, 0xFF, 0x80, 0x00};
    char test7_b[] = {0x00, 0x01, 0xFF, 0x80, 0x00};
    test_memcmp(test7_a, test7_b, 5, "Binary data comparison");

    // 8. Compare non-printable characters
    char test8_a[] = {0x80, 0x81, 0x82, 0x83};
    char test8_b[] = {0x80, 0x81, 0x82, 0x85}; // Last byte differs
    test_memcmp(test8_a, test8_b, 4, "Non-printable characters comparison");

    // 9. Unequal size comparison (compare first N bytes)
    char test9_a[] = {0x01, 0x02, 0x03};
    char test9_b[] = {0x01, 0x02, 0x00, 0x04};
    test_memcmp(test9_a, test9_b, 3, "Unequal size comparison");

    printf("############### STRLCPY TESTS ###############");

     // 1. Normal copy
    test_strlcpy("Hello, World!", 50, "Normal copy");

    // 2. Copy with buffer size smaller than source
    test_strlcpy("Hello, World!", 10, "Copy with small buffer");

    // 3. Exact buffer size
    test_strlcpy("Hello", 6, "Exact buffer size");

    // 4. Empty source string
    test_strlcpy("", 50, "Empty source string");

    // 5. Zero size
    test_strlcpy("Hello, World!", 0, "Zero size");

    // 6. Large buffer size (more than source length)
    test_strlcpy("Short", 100, "Large buffer size");

    // 7. Source with null byte
    test_strlcpy("Hello\0World", 50, "Source with null byte");

    // 8. Source exactly equal to buffer size
    test_strlcpy("1234567890", 11, "Source equals buffer size");

    // 9. Destination buffer size is 1
    test_strlcpy("Hello", 1, "Destination buffer size is 1");

    // 10. Multiple calls to test copying in same buffer
    char bfr1[100];
    char bfr2[100];

    // Test multiple calls
    memset(bfr1, 0, sizeof(bfr1));
    memset(bfr2, 0, sizeof(bfr2));
    strlcpy(bfr1, "First", sizeof(bfr1));
    ft_strlcpy(bfr2, "First", sizeof(bfr2));
    printf("Multiple calls: strlcpy: '%s', ft_strlcpy: '%s'\n", bfr1, bfr2);

    printf("######################## STRNSTR TESTS #################\n");
    const char *str1 = "hello can you catsh i'm just here!";
    const char *str2 = "can you catsh";
    const char *str3 = "";
    //const char *str4 = "no no it's not me";
    char *ptr;

    // Test 1:git  strnstr with str2
    ptr = ft_strnstr(str1, str2, 20);
    printf("str1 vs str2\n");
    printf("%s\n", ptr);

    // Test 2: strnstr with str3
    ptr = ft_strnstr(str1, str3, 10);
    printf("str1 vs str3\n");
    printf("%s\n", ptr);

    // Test 3: strnstr with str4
    //ptr = ft_strnstr(str1, str4, 20);
    //printf("str1 vs str4\n");
    //printf("%s\n", ptr);

    printf("############### FT_STRLCAT TESTS ###############\n");
    char s_1_1[20] = "Hello";
    char s_1_2[] = " World";
    printf("(ft_strlcat)Test 1: %zu | Result: %s\n", ft_strlcat(s_1_1, s_1_2, 12), s_1_1); // Expected: 11, "Hello World"
    //printf("(strlcat)Test 1: %zu | Result: %s\n", strlcat(s_1_1, s_1_2, 12), s_1_1);
    char s_2_1[20] = "Hello";
    char s_2_2[] = " World";
    printf("(ft_strlcat)Test 2: %zu | Result: %s\n", ft_strlcat(s_2_1, s_2_2, 8), s_2_1); // Expected: 11, "Hello Wo"
    //printf("(strlcat)Test 2: %zu | Result: %s\n", strlcat(s_2_1, s_2_2, 8), s_2_1);
    char s_3_1[10] = "Foo";
    char s_3_2[] = "Bar";
    printf("(ft_strlcat)Test 3: %zu | Result: %s\n", ft_strlcat(s_3_1, s_3_2, 7), s_3_1); // Expected: 6, "FooBar"
    //printf("(strlcat)Test 3: %zu | Result: %s\n", strlcat(s_3_1, s_3_2, 7), s_3_1);
    char s_4_1[10] = "Hello";
    char s_4_2[] = "";
    printf("(ft_strlcat)Test 4: %zu | Result: %s\n", ft_strlcat(s_4_1, s_4_2, 10), s_4_1); // Expected: 5, "Hello"
    //printf("(strlcat)Test 4: %zu | Result: %s\n", strlcat(s_4_1, s_4_2, 10), s_4_1);
    char s_5_1[10] = "";
    char s_5_2[] = "Test";
    printf("(ft_strlcat)Test 5: %zu | Result: %s\n", ft_strlcat(s_5_1, s_5_2, 6), s_5_1); // Expected: 4, "Test"
    //printf("(strlcat)Test 5: %zu | Result: %s\n", strlcat(s_5_1, s_5_2, 6), s_5_1);
    char s_6_1[10] = "Hello";
    char s_6_2[] = " World";
    printf("(ft_strlcat)Test 6: %zu | Result: %s\n", ft_strlcat(s_6_1, s_6_2, 0), s_6_1); // Expected: 11, ""
    //printf("(strlcat)Test 6: %zu | Result: %s\n", strlcat(s_6_1, s_6_2, 0), s_6_1);
    char s_7_1[10] = "12345";
    char s_7_2[] = "6789";
    printf("(ft_strlcat)Test 7: %zu | Result: %s\n", ft_strlcat(s_7_1, s_7_2, 3), s_7_1); // Expected: 9, "12345"
    //printf("(strlcat)Test 7: %zu | Result: %s\n", strlcat(s_7_1, s_7_2, 3), s_7_1);
    
    return (0);
}
