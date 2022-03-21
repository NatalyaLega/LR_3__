#pragma once
#include "Animals.h"
//����������� ����� �� "��������"

class Fish : public Animals
{
private:
	string breed; //������
	string nickname; //������
	string coat_color;  //�����
	string full_name_of_the_owner;  //������ ��� ���������
	string sizes;  //�������

public:
	Fish();
	Fish(const Fish& copy_cats);
	Fish(string breed, string nickname, string coat_color, string full_name_of_the_owner, string sizes);
	virtual ~Fish();
	string Get_full_name() override;
	string Get_breed() override;
	string Get_nickname() override;
	string Get_coat_color() override;
	string Get_sizes() override;
};