#include "Singleton.h"

int main()
{
	//Cach 1
	Singleton *res = Singleton::getInstance();
	res->method();
	//Cach 2
	Singleton::getInstance()->method();
	system("pause");
	return 0;
}