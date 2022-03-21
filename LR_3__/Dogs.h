#pragma once
#include "Animals.h"
//производный класс от "животные"

class Dogs : public Animals
{
private:
	string breed; //порода
	string nickname; //кличка
	string coat_color;  //окрас
	string full_name_of_the_owner;  //полное имя владельца
	string sizes;  //размеры

public:
	Dogs();
	Dogs(const Dogs& copy_dogs);
	Dogs(string breed, string nickname, string coat_color, string full_name_of_the_owner, string sizes);
	virtual ~Dogs();
	string Get_full_name() override;
	string Get_breed() override;
	string Get_nickname() override;
	string Get_coat_color() override;
	string Get_sizes() override;
};