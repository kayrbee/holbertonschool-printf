int main(void)
{
        char a = 'z';
        char *str;

        str = "test";

        printf("Test 1: string literal ");
        _printf("Apple\n");
        printf("Test 2: %%c without nl");
        _printf("%c", a);
        printf("Test 3: %%c with nl");
        _printf("%c\n", a);
        printf("Test 4: %%s ");
        _printf("%s\n", str);
        printf("Test 5: %%%% ");
        _printf("%%");
        printf("Test 6: combo input with %%%% ");
        _printf("str %%\n");
        printf("Test 7: error checks - pass in null\n");
        _printf(NULL);
        printf("Test 8: error checks - pass in a single %%");
        _printf("%");

        return (0);
}
