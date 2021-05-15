#include <stdio.h>

size_t strlen_(const char* string);
char* strchr_(const char* string, int c);
void* memset_(void* ptr, int value, size_t num);
void* memcpy_(void* restrict dest, const void* restrict src, size_t num);

int main(void)
{
    printf("strlen_(\"\"): %zu\nExpected: 0\n\n",
            strlen_(""));
    printf("strlen_(\"strlen_ test\"): %zu\nExpected: 12\n\n",
            strlen_("strlen_ test"));
    printf("strlen_(\"The quick brown fox jumps over the lazy dog\"): %zu\nExpected: 43\n\n",
            strlen_("The quick brown fox jumps over the lazy dog"));

    printf("strchr_(\"\", 'a'): %s\nExpected: (null)\n\n",
            strchr_("", 'a'));
    printf("strchr_(\"The quick brown fox\", 'l'): %s\nExpected: (null)\n\n",
            strchr_("The quick brown fox", 'l'));
    printf("strchr_(\"The quick brown fox jumps over the lazy dog\", 'l'): %s\nExpected: lazy dog\n\n",
            strchr_("The quick brown fox jumps over the lazy dog", 'l'));

    char message[] = "Almost every programmer should know memset!";
    printf("memset_(message, '-', 0): %s\nExpected: Almost every programmer should know memset!\n\n",
            (char*) memset_(message, '-', 0));
    printf("memset_(message, '-', 6): %s\nExpected: ------ every programmer should know memset!\n\n",
            (char*) memset_(message, '-', 6));
    
    printf("memcpy_(message, \"ALMOST\", 6): %s\nExpected: ALMOST every programmer should know memset!\n\n",
            (char*) memcpy_(message, "ALMOST", 6));

    return 0;    
}