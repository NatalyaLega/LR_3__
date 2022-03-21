#include <iostream>
#include <fstream>
#include <cmath>
#include <locale>
#include <string>
#include "Mammals.h"
#include "People.h"
#include "Animals.h"
#include "Cats.h"
#include "Dogs.h"
#include "Fish.h"

/*������� - 11 ������� ����������� ����� ��������������.���������� ����������� ������
��������� � �����.� �������� ���������� ����������� ������ �����, ����� � ���, �������
�������� � ���� ������, ������, �����, ��� ��������� � �������.��� ������ ����� ����������
���� : ���, ���� ��������, ��������������.���������� ����������� ������� ��������
��������, ������, ���� � ����.*/

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	//��� ������� ����������-������� �������????????????
	string breed_cat, nickname_cat, coat_color_cat, full_name_of_the_owner_cat, sizes_cat; //cat
	string breed_dog, nickname_dog, coat_color_dog, full_name_of_the_owner_dog, sizes_dog; //dog
	string breed_fish, nickname_fish, coat_color_fish, full_name_of_the_owner_fish, sizes_fish; //fish
	string full_name_people, date_of_birth_people, nationality_people; //people


	string initfile = "C:\\Users\\legan\\OneDrive\\LR_4\\data.txt";
	ifstream inFile;
	ofstream outFile;

	int c;
	cout << "��� ������������ ��������� 3-�� ������������ �� ��!" << endl;
	cout << "��� �� ������ ������ ������?" << endl;
	cout << "1 - �������" << endl;
	cout << "2 - �� �����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "--> ";
	cin >> c;

	switch (c)
	{
	case 1: //�������
		system("cls");
		cout << "~" << "������� ������ '��������' ����� ������(������ ������� � ������ ������ �������������): " << endl;
		cout << "���, ���� ��������, ��������������\n\n";
		cin >> full_name_people >> date_of_birth_people >> nationality_people;

		cout << "\n" << "~" << "������� ������ '������'����� ������(������ ������� � ������ ������ �������������):" << endl;
		cout << "������, ������, �����, ��� ���������, �������(����� � ������)\n\n";
		cin >> breed_dog >> nickname_dog >> coat_color_dog >> full_name_of_the_owner_dog >> sizes_dog;

		cout << "\n" << "~" << "������� ������ '�����'����� ������(������ ������� � ������ ������ �������������): " << endl;
		cout << "������, ������, �����, ��� ���������, �������(����� � ������)\n\n";
		cin >> breed_cat >> nickname_cat >> coat_color_cat >> full_name_of_the_owner_cat >> sizes_cat;

		cout << "\n" << "~" << "������� ������ '����'����� ������(������ ������� � ������ ������ �������������): " << endl;
		cout << "������, ������, �����, ��� ���������, �������(����� � ������)\n\n";
		cin >> breed_fish >> nickname_fish >> coat_color_fish >> full_name_of_the_owner_fish >> sizes_fish;
		break;
	case 2:
		system("cls");
		inFile.open(initfile);
		if (!inFile)
		{
			cout << "������ �������� �����!" << endl;
			exit(1);
		}
		cout << "������� ������ ������ ����� ������: �������, ������, �����, ���� " << endl;
		inFile >> full_name_people >> date_of_birth_people >> nationality_people >> breed_dog >> nickname_dog >> coat_color_dog >> full_name_of_the_owner_dog >> sizes_dog >> breed_cat >> nickname_cat >> coat_color_cat >> full_name_of_the_owner_cat >> sizes_cat >> breed_fish >> nickname_fish >> coat_color_fish >> full_name_of_the_owner_fish >> sizes_fish;

		cout << "������ �����!" << endl;
		inFile.close();
	break;	case 0:
		exit(0);
		break;
	default:
		break;
	}

	//��� ��� ����� ��������� �� 4, � �������, ������� ������� ������������. ���� �� ���� ���...��� ����������� ������� �������� � ������� ����������� ����������
	Mammals* mamm[4];
	People people(full_name_people, date_of_birth_people, nationality_people);
	Cats cat(breed_cat, nickname_cat, coat_color_cat, full_name_of_the_owner_cat, sizes_cat);
	Dogs dog(breed_dog, nickname_dog, coat_color_dog, full_name_of_the_owner_dog, sizes_dog);
	Fish fish(breed_fish, nickname_fish, coat_color_fish, full_name_of_the_owner_fish, sizes_fish);
	mamm[0] = &people;
	mamm[1] = &cat;
	mamm[2] = &dog;
	mamm[3] = &fish;

	system("pause");
	system("cls");
	cout << "�������� ��������: ";
	mamm[0]->Describe(); 
	cout << "�������� �����: ";
	mamm[1]->Describe(); 
	cout << "�������� ������: ";
	mamm[2]->Describe(); 
	cout << "�������� ����: ";
	mamm[3]->Describe();
	
	system("pause");
	system("cls");

	cout << "������� ������������ � ���� ����� ������?" << endl;
	cout << "1 - ��" << endl;
	cout << "2 - ���" << endl;
	cout << "--> ";
	cin >> c;
	switch (c)
	{
	case 1:
		outFile.open(initfile);
		if (!outFile)
		{
			cout << "������ �������� �����!" << endl;
			exit(1);
		}
		cout << "������� ����� ������ ����� ������: ";
		cin >> full_name_people >> date_of_birth_people >> nationality_people >> breed_dog >> nickname_dog >> coat_color_dog >> full_name_of_the_owner_dog >> sizes_dog >> breed_cat >> nickname_cat >> coat_color_cat >> full_name_of_the_owner_cat >> sizes_cat >> breed_fish >> nickname_fish >> coat_color_fish >> full_name_of_the_owner_fish >> sizes_fish;
		outFile << full_name_people << date_of_birth_people << nationality_people << breed_dog << nickname_dog << coat_color_dog << full_name_of_the_owner_dog << sizes_dog << breed_cat << nickname_cat << coat_color_cat << full_name_of_the_owner_cat << sizes_cat << breed_fish << nickname_fish << coat_color_fish << full_name_of_the_owner_fish << sizes_fish;
		cout << "������ ��������!" << endl;
		outFile.close();
		break;
	case 2: break;
	default: break;
	}

	return 0;
}
