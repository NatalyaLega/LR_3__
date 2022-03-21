#pragma once
#include "Mammals.h"

//производный класс "животные", от которого наследуются 3 класса

class Animals : public Mammals
{
public:
	Animals();

	virtual ~Animals();

	string Get_full_name() override;
	string Get_breed() override;
	string Get_nickname() override;
	string Get_coat_color() override;
	string Get_sizes() override;
};