#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int j;

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
