## A shared repo for Dana, Mel & Kat's _printf project

Test cases for exercise 0: solve for %c and %s

	_printf("Character: [%c]\n", 'H');
	_printf("String: [%s]\n", "I am a string !");

### To Do
See [tests/to-do-list](https://github.com/kayrbee/holbertonschool-printf/blob/kb/refactor/tests/to-do-list)

### Logic
#### Function protoype
	int _printf(const char *format, ...);

#### Inputs and outputs
**Inputs:**: format identifier, variable length list of strings to print

**Behaviour:** print the strings that it is given, in order, in the right format

**Return:** success (0) or failure

#### Pseudocode
Call _printf()

Example input: %s, string="hello"

	Check for an empty string - exit function if empty
	
	While not at end of string (NULL terminator check):
	  Evaluate the current character
	    If the current character is a format specifier (%)
	      	Look up the format specifier (find the correct function to format a string)
	      	Pass the current va_arg to the correct function
	      	Which should print va_arg as a literal?
	    Else if the current character is a new line specifier (\n)
		Print a newline character
	    Else print the current character
	  Loop to next character

