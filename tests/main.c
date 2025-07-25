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

        return (0);
}
