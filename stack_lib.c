#include "stack_lib.h"
#include <stdlib.h>
#include <string.h>
Stack* create(int ElementSize, int length){
	Stack* stack;
	stack=malloc(sizeof(Stack)*1);
	stack->stackinfo.elementSize=ElementSize;
	stack->stackinfo.size=length;
	stack->stackinfo.top=-1;
	stack->elements=calloc(stack->stackinfo.size,stack->stackinfo.elementSize);
	return stack;
}

boolean IsStackFull(Stack *st){
	if((st->stackinfo.top+1) >= st->stackinfo.size)
		return true;
	else
		return false;
}

boolean push(Stack* stack,void* elementToPush){
	void* address;
	if(IsStackFull(stack))
		return false;
	address=stack->elements+(++(stack->stackinfo.top)*stack->stackinfo.elementSize);
	memcpy(address, elementToPush, stack->stackinfo.elementSize);
	return true;
}

boolean IsEmpty(Stack* stack){
        return stack->stackinfo.top==-1;
}

void* pop(Stack* stack){
	if(IsEmpty(stack))
		return false;
	return stack->elements+((stack->stackinfo.top--)*stack->stackinfo.elementSize);
}

void* top(Stack* stack){
	return stack->elements+(stack->stackinfo.top*stack->stackinfo.elementSize);
}