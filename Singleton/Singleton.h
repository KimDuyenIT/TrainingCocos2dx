#pragma once
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <iostream>
using namespace std;

class Singleton
{	
private:
	static Singleton* m_instance;
	Singleton();
public:
	static Singleton* getInstance();
	void method();
};
#endif

