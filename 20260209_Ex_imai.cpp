#include<memory>

int main(void)
{
	int* p;

	p = new int;

	*p = 10;

	delete p;


	return 0;
}