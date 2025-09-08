#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int my_puts(const char* str);
const char* my_strchr(const char* str, int ch);
int my_strlen(const char* str);
char* my_strcpy(char* str2, const char* str1);
char* my_strncpy(char* str2, const char* str1, int n);
char* my_strcat(const char* str, char* in_str);
char* my_strncat(const char* str, char* in_str, int n);
int my_atoi(const char* str);
char* my_fgets(char *s, int n, FILE *iop);
char* my_strdup(const char* s);
int my_getline(char** s, size_t* n, FILE* iop);

int main() {
    char asd[5] = "aaaa";
    char pis[100] = "gwrgr";
    char baba[5] = "";
    char s[7] = "Ahntnt";
    //printf("%s", my_strncat(asd, pis, 1));
    //printf("%s\n", my_strcpy(baba, asd));
    //printf("%s\n", my_strncpy(baba, asd, 2));
    /*
    printf("%c\n",*my_strchr("aaxdA", 'A'));
    printf("%d\n", my_strlen("spermasiski"));
    my_strncat(s, pis, 5);
    printf("%s\n", pis);
    printf("%d\n", my_atoi(asd));
    */
    //printf("%s", my_fgets(baba, sizeof(baba), stdin));
    //printf("%s\n", my_strdup(s));
    char* qwe = "";
    size_t sz = 5;
    char** bn = &qwe;
    int xcxxcc = my_getline(bn, &sz, stdin);
    printf("%s\n", *bn);

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

char* my_strcpy(char* str2, const char* str1) {
    assert(str1);
    assert(str2);

    char* var = str2;

    while ((*str2 = *str1) != '\0') {
        str2++;
        str1++;
    }

    return var;
}

char* my_strncpy(char* str2, const char* str1, int n) {
    assert(str1);
    assert(str2);

    int cnt = 0;

    char* var = str2;
    *str2 = *str1;
    cnt++;

    while ((*str2 != '\0') && (cnt++ < n)) {
        str2++;
        str1++;
        *str2 = *str1;
    }

    return var;
}

char* my_strcat(const char* str, char* in_str) {
    assert(str);
    assert(in_str);

    char* var = in_str;

    while (*in_str != '\0')
        in_str++;

    in_str--;

    while (*str != '\0') {
        *in_str = *str;
        str++;
        in_str++;
    }
    *in_str = '\0';

    return var;
}

char* my_strncat(const char* str, char* in_str, int n) {
    assert(str);
    assert(in_str);

    char* var = in_str;

    while (*in_str++ != '\0');
    in_str--;

    int cnt = 0;

    while ((*str != '\0') && cnt < n){
        cnt++;
        *in_str = *str;
        str++;
        in_str++;
    }
    *in_str = '\0';

    return var;
}

int my_atoi(const char* str) {
    assert(str);

    int n = 0;

    while (*str >= '0' && *str <= '9') {
        n = n * 10 + (*str - '0');
        str++;
    }

    return n;
}

char* my_fgets(char *s, int n, FILE *iop) {
    assert(s);
    assert(iop);

    int cnt = 0;
    int c = 0;
    char* cs = 0;

    cs = s;
    c = getc(iop);
    cnt++;

    while((cnt < n) && (c != EOF)) {
        cnt++;
        *cs = c;
        if (*cs == '\n') {
            cs++;
            break;
        }
        cs++;
        c = getc(iop);
    }
    *cs = '\0';

    return (c == EOF && cs == s) ? NULL : s;
}

char* my_strdup(const char* s) {
    assert(s);

    char* p = NULL;

    p = (char*) calloc(sizeof(s), sizeof(*s));
    assert(p);

    if (p != NULL) {
        my_strcpy(p, s);
    }

    return p;
}

int my_getline(char** s, size_t* n, FILE* iop) {   //
    assert(s);
    assert(*s);
    assert(n);
    assert(iop);

    *s = (char*)calloc(*n, sizeof(char));
    int cnt = 0;
    char c = 0;

    c = getc(iop);

    while (cnt < *n && c != EOF) {
        if (cnt + 1 == *n) {
            *s = (char*)realloc(*s - cnt, *n + 100);
            *n += 100;
            assert(*s);
            *s = *s + cnt;
        }
        if (c == '\n') {
            **s = c;
            cnt++;
            (*s)++;
            break;
        }
        **s = c;
        (*s)++;
        cnt++;
        c = getc(iop);
    }

    **s = '\0';
    if (cnt < *n) {
        *s = (char*)realloc(*s - cnt, strlen(*s - cnt));
        assert(*s);
    }
    else {
        *s -= cnt;
    }

    *n = cnt;

    return cnt;
}

