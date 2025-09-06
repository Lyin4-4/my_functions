#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int my_puts(const char* str);
const char* my_strchr(const char* str, int ch);
int my_strlen(const char* str);
char* my_strcpy(char* str2, const char* str1);
char* my_strncpy(char* str2, const char* str1, int n);
void my_strcat(char* str, char* in_str);
void my_strncat(char* str, char* in_str, int n);
int my_atoi(char* str);
char* my_fgets(char *s, int n, FILE *iop);
char* my_strdup(char* s);
int my_getline(char* s, int n);

int main() {
    char asd[5] = "aaaa";
    char pis[100] = "gwrgr";
    char baba[5] = "bbbb";
    char s[7] = "ABABDG";
    printf("%s\n", my_strcpy(baba, asd));
    printf("%s\n", my_strncpy(baba, asd, 3));
    /*
    printf("%c\n",*my_strchr("aaxdA", 'A'));
    printf("%d\n", my_strlen("spermasiski"));
    my_strncat(s, pis, 5);
    printf("%s\n", pis);
    printf("%d\n", my_atoi(asd));
    printf("%s", my_fgets(baba, sizeof(baba), stdin));
    printf("%s\n", my_strdup(s));
    printf("%d\n", my_getline(baba, 100));
    printf("%s\n", baba);
    */

    return 0;
}

int my_puts(const char* str) {
    assert(str);

    while (*str != '\0') {
        printf("%c", str++);
    }

    putchar('\n');

    return ferror(stdout) ? EOF : 0;
}

const char* my_strchr(const char* str, int ch) {
    assert(str);

    while (*str != '\0' && *str != ch) {
        str++;

        if (*str == ch) {

            return str;
        }
    }

    return NULL;
}

int my_strlen(const char* str) {
    assert(str);

    int cnt = 0;
    while (*str != '\0') {
        str++;
        ++cnt;
    }

    return cnt;
}

char* my_strcpy(char* str2, const char* str1) {   //
    assert(str1);
    assert(str2);

    char* var = str2;

    while ((*str2 = *str1) != '\0') {  //
        str2++;
        str1++;
    }

    return var;
}

char* my_strncpy(char* str2, const char* str1, int n) {  //
    assert(str1);
    assert(str2);

    int cnt = 0;

    char* var = (char*) calloc(n, sizeof(char));
    assert(var);
    str2 = var;

    while (((*var = *str1) != '\0') && (cnt++ < n)); {
        printf("rf\n");
        var++;
        str1++;
        // (((*var = *str1) != '\0')) {
        //    cnt++;
        //    printf("yes\n");
        //}
    }

    return str2;
}

void my_strcat(char* str, char* in_str) {   //
    assert(str);
    assert(in_str);

    while (*in_str++ != '\0');
    in_str--;
    while (*str != '\0') {
        *in_str = *str;
        str++;
        in_str++;
    }
    *in_str = '\0';
}

void my_strncat(char* str, char* in_str, int n) {    //
    assert(str);
    assert(in_str);

    while (*in_str++ != '\0');
    in_str--;

    int cnt = 0;

    while ((*str != '\0') && cnt++ < n){
        *in_str = *str;
        str++;
        in_str++;
    }
    *in_str = '\0';
}

int my_atoi(char* str) {

    int n = 0;

    while (*str >= '0' && *str <= '9') {
        n = n * 10 + (*str - '0');
        str++;
    }

    return n;
}

char* my_fgets(char *s, int n, FILE *iop) {     // assert
    assert(s);
    assert(iop);

    int cnt = 0;
    int c = 0;
    char* cs = 0;

    cs = s;

    while((cnt++ < n) && ((c = getc(iop)) != EOF)) {
        if ((*cs++ = c) == '\n') {
            break;
        }
    }
    *cs = '\0';

    return (c == EOF && cs == s) ? NULL : s;
}

char* my_strdup(char* s) {    // assert
    assert(s);

    char* p = NULL;

    p = (char*) malloc(sizeof(s));    //
    assert(p);

    if (p != NULL) {
        my_strcpy(p, s);
    }

    return p;
}

int my_getline(char* s, int n) {   //
    assert(s);

    int cnt = 0;
    char c = 0;

    while (cnt < n && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        cnt++;
    }

    if (c == '\n') {
        *s++ = c;
        cnt++;
    }

    *s = '\0';

    return cnt;
}

