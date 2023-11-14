#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
    int len3, len5;
    int len4, len6;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");

	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);

	_printf("%s with a null string: \n", "23");
	printf("%s with a null string: \n", "23");

	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');

	_printf("Large Character: %c\n", 255);
	printf("Large Character: %c\n", 255);

	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");

	_printf("Empty String: %s\n", "");
	printf("Empty String: %s\n", "");

	_printf("String with Spaces: %s\n", "Hello World");
	printf("String with Spaces: %s\n", "Hello World");
    
    _printf("%!\n");
    printf("%!\n");

	_printf("Zero Integer: %d\n", 0);
	printf("Zero Integer: %d\n", 0);

	_printf("Multiple %% in a row: %% %c %%\n", 'X');
	printf("after custom print\n");
	printf("Multiple %% in a row: %% %c %%\n", 'X');

	_printf("Multiple Percent Signs: %%%% %%%% %%%% %%%%\n");
	printf("Multiple Percent Signs: %%%% %%%% %%%% %%%%\n");

	_printf("Unordered Specifiers: %d %s %c\n", 42, "Order", 'A');
	printf("Unordered Specifiers: %d %s %c\n", 42, "Order", 'A');

	_printf("Combination: %s %d %c %% %i\n", "Order", 42, 'X', -123);
	printf("Combination: %s %d %c %% %i\n", "Order", 42, 'X', -123);

	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
    
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
    
    len3 = _printf("%c", 'S');
	printf("%d\n", len3);
	len4 = printf("%c", 'S');
	printf("%d\n", len4);


	len5 = _printf("%");
	_printf("%d\n", len5);
	_printf("Lawson\n");
	_printf("%%\n");
	printf("\n");
	len6 = printf("%");
	printf("%d\n", len6);
	printf("Noblet\n");
	printf("%%\n");

	_printf("Unknown\n");
	_printf("Unknown:[%r]\n");
	return (0);
}
