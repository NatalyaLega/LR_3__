#pragma once
#include "Mammals.h"

//производный класс "животные", от которого наследуются 3 класса

class Animals : public Mammals
{
public:
	Animals();

	virtual ~Animals();

	void Describe() override;

};