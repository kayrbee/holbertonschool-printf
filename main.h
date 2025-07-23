#ifndef PRINTF_FUNCTION
#define PRINTF_FUNCTION
#include <unistd.h>
#include <stddef.h>

int _printf(const char *format, ...);

/* create a struct */
typedef struct print_op 
{
	const char *key;
	void (*f)(va_list *list);
} print_op;


#endif

