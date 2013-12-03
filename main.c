#include "bracketMatchLib.h"
#include <string.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	String input;
	strcpy(input,argv[1]);
	if(BracketMatch(input))
		printf("String Matched");
	else
		printf("String Not Matched");
	return 0;
}