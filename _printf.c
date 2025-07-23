#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 */
int  print_str(va_list *list)
{
	char *str;
	str = va_arg(*list, char *);
        write(1, &str, strlen(str));  //check strlen necessity here, check later
	return (strlen);
}
/**
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int j;
	print_op op[] = {
		{"c", print_char},
		{"s", print_str},
	};


	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			j = i + 1;

			if (format[i] == '%' && format[j] == 's')
				


			write(1, &format[i], strlen(format[i]));  //check strlen necessity here, check later
			i++;





		return (-1);

}
