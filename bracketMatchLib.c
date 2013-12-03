
#include "bracketMatchLib.h"
#include <stdio.h>
#include <string.h>

boolean isBracketMatch(Stack* stack,char st){
	if((st==')' && *(char*)top(stack)=='(')
		|| (st==']' && *(char*)top(stack)=='[')
		|| (st=='}' && *(char*)top(stack)=='{'))
		return true;
	return false;
}

boolean BracketMatch(String st){
	Stack* stack;
	int count;
	stack = create(sizeof(char), strlen(st));
	for (count = 0; count < strlen(st); ++count)
	{
		if(st[count]=='(' || st[count]=='[' || st[count]=='{')
			push(stack, &st[count]);
		if(st[count]==')' || st[count]==']' || st[count]=='}'){
			if(!isBracketMatch(stack,st[count]))
				return false;
			pop(stack);
		}

	}
	return stack->stackinfo.top==-1 && true || false;
}