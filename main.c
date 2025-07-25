#include "main.h"
#include <stdio.h>

int main(void)
{
        char a = 'z';
        char *str;

        str = "test";

        printf("Test 1: string literal\n");
        printf("Test 2: %%c without nl\n");
        printf("Test 3: %%c with nl\n");
        printf("Test 4: %%s\n");
        printf("Test 5: %%%%\n");
        printf("Test 6: combo input with %%%%\n");
        printf("Test 7: error checks - pass in null\n");
        printf("Test 8: error checks - pass in a single %%\n");
        _printf("Apple\n");
        _printf("%c", a);
        _printf("%c\n", a);
        _printf("%s\n", str);
        _printf("%%");
        _printf("str %%\n");
        _printf(NULL);
        _printf("%");

        _printf("%d\n", 1024);
        printf("%d\n", 1024);
        _printf("%d\n", -1024);
        printf("%d\n", -1024);
        _printf("%d\n", 0);
        printf("%d\n", 0);
        _printf("%d\n", INT_MAX);
        printf("%d\n", INT_MAX);
        _printf("%d\n", INT_MIN);
        printf("%d\n", INT_MIN);
        _printf("%i\n", 1024);
        printf("%i\n", 1024);
        _printf("%i\n", -1024);
        printf("%i\n", -1024);
        _printf("%i\n", 0);
        printf("%i\n", 0);
        _printf("%i\n", INT_MAX);
        printf("%i\n", INT_MAX);
        _printf("%i\n", INT_MIN);
        printf("%i\n", INT_MIN);
        _printf("%d\n", 10000);
        printf("%d\n", 10000);
        _printf("%i\n", 10000);
        printf("%i\n", 10000);
        _printf("There is %d bytes in %d KB\n", 1024, 1);
        printf("There is %d bytes in %d KB\n", 1024, 1);
        _printf("%d - %d = %d\n", 1024, 2048, -1024);
        printf("%d - %d = %d\n", 1024, 2048, -1024);
        _printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
        printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
        _printf("There is %i bytes in %i KB\n", 1024, 1);
        printf("There is %i bytes in %i KB\n", 1024, 1);
        _printf("%i - %i = %i\n", 1024, 2048, -1024);
        printf("%i - %i = %i\n", 1024, 2048, -1024);
        _printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
        printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
        _printf("%d == %i\n", 1024, 1024);
        printf("%d == %i\n", 1024, 1024);
        _printf("iddi%diddiiddi\n", 1024);
        printf("iddi%diddiiddi\n", 1024);
        
        return (0);
}