int main(void)
{
        char a = 'z';
        char *str;

        str = "test";

        _printf("%c", a);
        _printf("%c\n", a);
        _printf("%s\n", str);
        _printf("%%");
        _printf("str %%\n");
        _printf("Apple\n");

        return (0);
}
