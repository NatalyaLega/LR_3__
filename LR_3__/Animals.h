#pragma once
#include "Mammals.h"

//����������� ����� "��������", �� �������� ����������� 3 ������

class Animals : public Mammals
{
public:
	Animals();

	virtual ~Animals();

	void Describe() override;

};