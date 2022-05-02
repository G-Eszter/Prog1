#include<stdio.h>
#include<string.h>

void C (char* p, int x)
{
	printf("p is %s\n", p);
	printf("x is %d\n", x);
}

int main()
{
	printf("Hello World!\n");
	char h[12] = "Hello";
	char w[12] = "World!";
	
	printf("%s %s\n", h, w);
	
	C("foo", 7);
}
