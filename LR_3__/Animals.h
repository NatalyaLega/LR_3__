#pragma once
#include "Mammals.h"

//����������� ����� "��������", �� �������� ����������� 3 ������

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