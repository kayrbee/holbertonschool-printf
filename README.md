##A shared repo for Dana, Mel & Kat's printf project

Test cases for exercise 0: 
	Solve for %c and %s

    _printf("Character: [%c]\n", 'H');
    _printf("String: [%s]\n", "I am a string !");

**Logic**
Protoype:
/* int _printf(const char *format, ...); */

**Inputs and outputs**
Call _printf()
Inputs: format identifier, variable length list of strings to print
Output: print the strings that it is given, in order, in the right format

**Pseudocode**
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
*/

