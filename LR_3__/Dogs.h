#pragma once
#include "Animals.h"
//����������� ����� �� "��������"

class Dogs : public Animals
{
private:
	string breed; //������
	string nickname; //������
	string coat_color;  //�����
	string full_name_of_the_owner;  //������ ��� ���������
	string sizes;  //�������

public:
	Dogs();
	Dogs(const Dogs& copy_dogs);
	Dogs(string breed, string nickname, string coat_color, string full_name_of_the_owner, string sizes);
	virtual ~Dogs();
	string Get_full_name_of_the_owner();
	string Get_breed();
	string Get_nickname();
	string Get_coat_color();
	string Get_sizes();

	void Describe() override;
};