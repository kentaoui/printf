#include "main.h"

/****************** PRINT POINTER ******************/
int print_pointer(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // ... (implementation)
}

/************************* PRINT NON PRINTABLE *************************/
int print_non_printable(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // ... (implementation)
}

/************************* PRINT REVERSE *************************/
int print_reverse(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // ... (implementation)
}

/************************* PRINT A STRING IN ROT13 *************************/
int print_rot13string(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // ... (implementation)
}

/************************* PRINT UNSIGNED DECIMAL *************************/
int print_unsigned(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // ... (implementation)
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
int print_octal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // ... (implementation)
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
int print_hexadecimal(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // ... (implementation)
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
int print_hexa_upper(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    // ... (implementation)
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%p\n", (void *)0x12345678);
    _printf("%R\n", "Hello, World!");
    _printf("%T\n", "Hello, World!");
    _printf("%u\n", 12345);
    _printf("%o\n", 0777);
    _printf("%x\n", 0x1aB);
    _printf("%X\n", 0x1aB);
    return (0);
}

