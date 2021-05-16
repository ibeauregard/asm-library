#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

size_t strlen_(const char* string);
char* strchr_(const char* string, int c);
char* index_(const char* string, int c);
void* memset_(void* ptr, int value, size_t num);
void* memcpy_(void* restrict dest, const void* restrict src, size_t num);
int strcmp_(const char *s1, const char *s2);
int strncmp_(const char *s1, const char *s2, size_t num);
int strcasecmp_(const char *s1, const char *s2);
ssize_t read_(int fd, void* buf, size_t count);
ssize_t write_(int fd, const void* buf, size_t count);

int main(void)
{
    /* strlen */
    printf("strlen_(\"\"): %zu\nExpected: %zu\n\n",
            strlen_(""),
            strlen(""));
    printf("strlen_(\"strlen_ test\"): %zu\nExpected: %zu\n\n",
            strlen_("strlen_ test"),
            strlen("strlen_ test"));
    printf("strlen_(\"The quick brown fox jumps over the lazy dog\"): %zu\nExpected: %zu\n\n",
            strlen_("The quick brown fox jumps over the lazy dog"),
            strlen("The quick brown fox jumps over the lazy dog"));

    /* strchr */
    printf("strchr_(\"\", 'a'): %p\nExpected: %p\n\n",
            strchr_("", 'a'),
            strchr("", 'a'));
    printf("strchr_(\"The quick brown fox\", 'l'): %p\nExpected: %p\n\n",
            strchr_("The quick brown fox", 'l'),
            strchr("The quick brown fox", 'l'));
    printf("strchr_(\"The quick brown fox jumps over the lazy dog\", 'l'): %s\nExpected: %s\n\n",
            strchr_("The quick brown fox jumps over the lazy dog", 'l'),
            strchr("The quick brown fox jumps over the lazy dog", 'l'));

    /* index */
    printf("index_(\"\", 'a'): %p\nExpected: %p\n\n",
            index_("", 'a'),
            index("", 'a'));
    printf("index_(\"The quick brown fox\", 'l'): %p\nExpected: %p\n\n",
            index_("The quick brown fox", 'l'),
            index("The quick brown fox", 'l'));
    printf("index_(\"The quick brown fox jumps over the lazy dog\", 'l'): %s\nExpected: %s\n\n",
            index_("The quick brown fox jumps over the lazy dog", 'l'),
            index("The quick brown fox jumps over the lazy dog", 'l'));

    /* memset */
    char message_[] = "Almost every programmer should know memset!",
          message[] = "Almost every programmer should know memset!";
    printf("memset_(message, '-', 0): %s\nExpected: %s\n\n",
            (char*) memset_(message_, '-', 0),
            (char*) memset(message, '-', 0));
    printf("memset_(message, '-', 6): %s\nExpected: %s\n\n",
            (char*) memset_(message_, '-', 6),
            (char*) memset(message, '-', 6));
    
    /* memcpy */
    printf("memcpy_(message, \"ALMOST\", 6): %s\nExpected: %s\n\n",
            (char*) memcpy_(message_, "ALMOST", 6),
            (char*) memcpy(message, "ALMOST", 6));

    /* strcmp */
    printf("strcmp_(\"\", \"\"): %d\nExpected: %d\n\n",
            strcmp_("", ""),
            strcmp("", ""));
    printf("strcmp_(\"a\", \"a\"): %d\nExpected: %d\n\n",
            strcmp_("a", "a"),
            strcmp("a", "a"));
    printf("strcmp_(\"a\", \"\"): %d\nExpected: <any positive number>\n\n",
            strcmp_("a", ""));
    printf("strcmp_(\"\", \"a\"): %d\nExpected: <any negative number>\n\n",
            strcmp_("", "a"));
    printf("strcmp_(\"The quick brown fox jumps\", \"The quick brown dog\"): %d\nExpected: <any positive number>\n\n",
            strcmp_("The quick brown fox jumps", "The quick brown dog"));
    printf("strcmp_(\"The quick brown dog\", \"The quick brown fox jumps\"): %d\nExpected: <any negative number>\n\n",
            strcmp_("The quick brown dog", "The quick brown fox jumps"));

    /* strncmp */
    printf("strncmp_(\"The quick brown dog\", \"A quick brown fox jumps\", 0): %d\nExpected: %d\n\n",
            strncmp_("The quick brown dog", "A quick brown fox jumps", 0),
            strncmp("The quick brown dog", "A quick brown fox jumps", 0));
    printf("strncmp_(\"The quick brown dog\", \"The quick brown fox jumps\", 15): %d\nExpected: 0\n\n",
            strncmp_("The quick brown dog", "The quick brown fox jumps", 15));
    printf("strncmp_(\"The quick brown dog\", \"The quick brown fox jumps\", 19): %d\nExpected: <any negative number>\n\n",
            strncmp_("The quick brown dog", "The quick brown fox jumps", 19));
    printf("strncmp_(\"The quick brown fox jumps\", \"The quick brown dog\", 19): %d\nExpected: <any positive number>\n\n",
            strncmp_("The quick brown fox jumps", "The quick brown dog", 19));

    /* strcasecmp */
    printf("strcasecmp_(\"\", \"\"): %d\nExpected: %d\n\n",
            strcasecmp_("", ""),
            strcasecmp("", ""));
    printf("strcasecmp_(\"A\", \"a\"): %d\nExpected: %d\n\n",
            strcasecmp_("A", "a"),
            strcasecmp("A", "a"));
    printf("strcasecmp_(\"The quick brown fox jumps over the lazy dog\", \"thE quicK browN foX jumpS oveR thE lazY doG\"): %d\nExpected: %d\n\n",
            strcasecmp_("The quick brown fox jumps over the lazy dog", "thE quicK browN foX jumpS oveR thE lazY doG"),
            strcasecmp("The quick brown fox jumps over the lazy dog", "thE quicK browN foX jumpS oveR thE lazY doG"));
    printf("strcasecmp_(\"a\", \"\"): %d\nExpected: <any positive number>\n\n",
            strcasecmp_("a", ""));
    printf("strcasecmp_(\"\", \"a\"): %d\nExpected: <any negative number>\n\n",
            strcasecmp_("", "a"));
    printf("strcasecmp_(\"THE QUICK BROWN FOX JUMPS\", \"The quick brown dog\"): %d\nExpected: <any positive number>\n\n",
            strcasecmp_("THE QUICK BROWN FOX JUMPS", "The quick brown dog"));
    printf("strcasecmp_(\"The quick brown dog\", \"THE QUICK BROWN FOX JUMPS\"): %d\nExpected: <any negative number>\n\n",
            strcasecmp_("The quick brown dog", "THE QUICK BROWN FOX JUMPS"));
    
    /* read */
    char syscall_str_[9], syscall_str[9];
    int fd_ = open("syscall.txt", O_RDONLY), fd = open("syscall.txt", O_RDONLY);
    printf("Return value from read_(fd, syscall_str, 9): %zd\nExpected: %zd\n\n",
            read_(fd_, syscall_str_, 9),
            read(fd, syscall_str, 9));
    close(fd_); close(fd);
    
    /* write */
    printf("Return value from write_(1, syscall_str, 9): %zd\nExpected: %zd\n\n",
            write_(1, syscall_str, 9),
            write(1, syscall_str, 9));

    return 0;    
}