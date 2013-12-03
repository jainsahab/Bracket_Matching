typedef struct 
{
	void *elements;
	struct StackInfo{
		int top;
		int elementSize;
		int size;
	} stackinfo;
}Stack;
typedef char String[256];
typedef int boolean;
#define true 1
#define false 0
Stack* create(int ElementSize, int length);
boolean push(Stack* stack,void* InsertElement);
void* pop(Stack *stack);
void* top(Stack* stack);