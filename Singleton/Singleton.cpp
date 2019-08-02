#include "Singleton.h"

Singleton* Singleton::m_instance = NULL;
Singleton* Singleton::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new Singleton();
	}
	return m_instance;
}
void Singleton::method()
{
	cout << "This is singleton parttern" << endl;
}

Singleton::Singleton()
{
}

