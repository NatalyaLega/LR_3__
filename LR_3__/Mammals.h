#pragma once
#include <string>
using namespace std;
//abstract
class Mammals
{
public:
	Mammals() {};
	virtual ~Mammals() {};



	//����������� ������� ��� �������� ��������, ������, ���� � ����
	virtual string Get_full_name() = 0;      //��� �������� � ��� ������� ��������
	virtual string Get_date_of_birth() = 0;  //���� ��������
	virtual string Get_nationality() = 0;    //��������������

	virtual string Get_breed() = 0;      //������
	virtual string Get_nickname() = 0;   //������
	virtual string Get_coat_color() = 0; //�����
	virtual string Get_sizes() = 0;      //�������

  //private:
  //	static int Count;  //���������� ��� �������� ���-�� ��������
};