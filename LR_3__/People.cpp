#include "People.h"
#include <iostream>


People::People() : full_name(""), date_of_birth(""), nationality("") { }

People::People(string full_name, string date_of_birth, string nationality)
{
	this->full_name = full_name;
	this->date_of_birth = date_of_birth;
	this->nationality = nationality;
}

People::People(const People& copy_people)
{
	full_name = copy_people.full_name;
	date_of_birth = copy_people.date_of_birth;
	nationality = copy_people.nationality;
}

People::~People() { }

void People::Describe()
{
	std::cout<< "ФИО: " << Get_full_name() << endl;
	std::cout << "Дата рождения: " << Get_date_of_birth() << endl;
	std::cout << "Национальность: " << Get_nationality() << endl;
	std::cout << "\n";
}

string People::Get_full_name() { return full_name; }

string People::Get_date_of_birth() { return date_of_birth; }

string People::Get_nationality() { return nationality; }

