#pragma once
#include <string>
using namespace std;
//abstract
class Mammals
{
public:
	Mammals() {};
	virtual ~Mammals() {};



	//виртуальные функции дл€ описани€ человека, собаки, кота и рыбы
	virtual string Get_full_name() = 0;      //фио человека и фио хоз€ина животных
	virtual string Get_date_of_birth() = 0;  //дата рождени€
	virtual string Get_nationality() = 0;    //национальность

	virtual string Get_breed() = 0;      //порода
	virtual string Get_nickname() = 0;   //кличка
	virtual string Get_coat_color() = 0; //окрас
	virtual string Get_sizes() = 0;      //размеры

  //private:
  //	static int Count;  //переменна€ дл€ подсчЄта кол-ва объектов
};