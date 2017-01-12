/****************************************************************************
 * Trial of modified cs50.h version
 * using same C style, update for CS50x 2017 course.
 *
 * Created by: Joel Enriquez (2017/01/12)
 *
 ***************************************************************************/

#include <stdio.h>
#include <cs50b.h>

int main( void )
{
	printf( "char: " );
	char c = get_char();
	
	printf( "string: " );
	string s = get_string();

	printf( "float: " );
	float f = get_float();

	printf( "double: " );
	double d = get_double();

	printf( "int: " );
	int i = get_int();

	printf( "long long: " );
	long long l = get_long_long();

	printf("%c\n", c);
	printf("%s\n", s);
	printf("%f\n", f);
	printf("%lf\n", d);
	printf("%i\n", i);
	printf("%lld\n", l);

	return 0;
}
