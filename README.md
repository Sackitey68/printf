printf Function
Project 0x11 - C - printf
Recreate the printf function in C.

Installing
Compile:

$ gcc -Wall -Werror -Wextra -pedantic *.c
Authorized functions and macros
write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)
Tasks
Task 0 - function that produces output according to a format

Task 1 - Handle conversion specifiers "d", "i"

Task 2 - create a man page for our function

Task 3 - handle conversion specifer "b"

Task 4 - handle conversion specifier "u", "o", "x", "X"

Task 5 - use a local buffer of 1024 chars in order to call write as little as possible

Task 6 - handle conversion specifier "S"

Task 7 - handle conversion specifier "p"

Task 8 - handle flag characters for non-custom specifiers "+", " ", "#"

Task 9 - handle length modifiers for non-custom specifiers "l", "h"

Task 10 - handle the field width for non-custom conversion specifiers

Task 11 - handle the precision for non-custom conversion specifiers

Task 12 - handle the "0" flag for non-custom conversion specifiers

Task 13 - handle the "-" flag character for non-custom conversion specifiers

Task 14 - handle the "r" custom conversion specifier (prints the reversed string)

Task 15 - handle the "R" custom conversion specifier (prints the rot13'ed string)
