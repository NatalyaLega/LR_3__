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
	
virtual void Describe() = 0; //������� ��� ��������

  private:
 	static int Count;  //���������� ��� �������� ���-�� ��������
};