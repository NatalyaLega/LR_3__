#pragma once
#include "Mammals.h"

//Производный класс "люди"

class People : public Mammals
{
private:
	string full_name;
	string date_of_birth;
	string nationality;
public:
	People();
	People(string full_name, string date_of_birth, string nationality);
	People(const People& copy_people);
	virtual ~People();
	string Get_full_name()  override;
	string Get_date_of_birth() override;
	string Get_nationality() override;
};
