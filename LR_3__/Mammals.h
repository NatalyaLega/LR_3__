#pragma once
#include <string>
using namespace std;
//abstract
class Mammals
{
public:
	Mammals() {};
	virtual ~Mammals() {};

//виртуальные функции для описания человека, собаки, кота и рыбы
	
virtual void Describe() = 0; //функция для описания

  private:
 	static int Count;  //переменная для подсчёта кол-ва объектов
};