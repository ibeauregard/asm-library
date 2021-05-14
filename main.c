#include <stdio.h>

size_t strlen_(const char* string);

int main(void)
{
    printf("strlen_(\"\"): %zu\nExpected: 0\n\n", strlen_(""));
    printf("strlen_(\"strlen_ test\"): %zu\nExpected: 12\n\n", strlen_("strlen_ test"));
    printf("strlen_(\"The quick brown fox jumps over the lazy dog\"): %zu\nExpected: 43\n\n", strlen_("The quick brown fox jumps over the lazy dog"));

    return 0;    
}