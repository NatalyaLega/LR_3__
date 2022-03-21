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

/*Вариант - 11 Создать абстрактный класс «Млекопитающие».Определить производные классы
«Животные» и «Люди».У животных определить производные классы собак, котов и рыб, которые
содержат в себе породу, кличку, окрас, ФИО владельца и размеры.Для класса «Люди» существуют
поля : ФИО, дата рождения, национальность.Определить виртуальные функции описания
человека, собаки, кота и рыбы.*/

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	//тут создать переменные-объекты классов????????????
	string breed_cat, nickname_cat, coat_color_cat, full_name_of_the_owner_cat, sizes_cat; //cat
	string breed_dog, nickname_dog, coat_color_dog, full_name_of_the_owner_dog, sizes_dog; //dog
	string breed_fish, nickname_fish, coat_color_fish, full_name_of_the_owner_fish, sizes_fish; //fish
	string full_name_people, date_of_birth_people, nationality_people; //people


	string initfile = "C:\\Users\\legan\\OneDrive\\LR_4\\data.txt";
	ifstream inFile;
	ofstream outFile;

	int c;
	cout << "Вас приветствует программа 3-ей лабораторной по ТП!" << endl;
	cout << "Как Вы хотите ввести данные?" << endl;
	cout << "1 - Вручную" << endl;
	cout << "2 - Из файла" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "--> ";
	cin >> c;

	switch (c)
	{
	case 1: //Вручную
		system("cls");
		cout << "~" << "Введите данные 'человека' через пробел(вместо пробела в данных нижнее подчеркивание): " << endl;
		cout << "ФИО, Дата рождения, Национальность\n\n";
		cin >> full_name_people >> date_of_birth_people >> nationality_people;

		cout << "\n" << "~" << "Введите данные 'собаки'через пробел(вместо пробела в данных нижнее подчеркивание):" << endl;
		cout << "Порода, кличка, окрас, ФИО владельца, размеры(длина и ширина)\n\n";
		cin >> breed_dog >> nickname_dog >> coat_color_dog >> full_name_of_the_owner_dog >> sizes_dog;

		cout << "\n" << "~" << "Введите данные 'кошки'через пробел(вместо пробела в данных нижнее подчеркивание): " << endl;
		cout << "Порода, кличка, окрас, ФИО владельца, размеры(длина и ширина)\n\n";
		cin >> breed_cat >> nickname_cat >> coat_color_cat >> full_name_of_the_owner_cat >> sizes_cat;

		cout << "\n" << "~" << "Введите данные 'рыбы'через пробел(вместо пробела в данных нижнее подчеркивание): " << endl;
		cout << "Порода, кличка, окрас, ФИО владельца, размеры(длина и ширина)\n\n";
		cin >> breed_fish >> nickname_fish >> coat_color_fish >> full_name_of_the_owner_fish >> sizes_fish;
		break;
	case 2:
		system("cls");
		inFile.open(initfile);
		if (!inFile)
		{
			cout << "Ошибка открытия файла!" << endl;
			exit(1);
		}
		cout << "Порядок взятия данных через пробел: человек, собака, кошка, рыба " << endl;
		inFile >> full_name_people >> date_of_birth_people >> nationality_people >> breed_dog >> nickname_dog >> coat_color_dog >> full_name_of_the_owner_dog >> sizes_dog >> breed_cat >> nickname_cat >> coat_color_cat >> full_name_of_the_owner_cat >> sizes_cat >> breed_fish >> nickname_fish >> coat_color_fish >> full_name_of_the_owner_fish >> sizes_fish;

		cout << "Данные взяты!" << endl;
		inFile.close();
	break;	case 0:
		exit(0);
		break;
	default:
		break;
	}

	//ВОТ ТУТ НУЖНО СОЗДАВАТЬ НЕ 4, А СТОЛЬКО, СКОЛЬКО ЗАХОЧЕТ ПОЛЬЗОВАТЕЛЬ. пока не знаю как...ЕЩЕ РЕАЛИЗОВАТЬ ПОДСЧЕТ ОБЪЕКТОВ С ПОМОЩЬЮ СТАТИЧЕСКОЙ ПЕРЕМЕННОЙ
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
	cout << "Описание человека: ";
	mamm[0]->Describe(); 
	cout << "Описание кошки: ";
	mamm[1]->Describe(); 
	cout << "Описание собаки: ";
	mamm[2]->Describe(); 
	cout << "Описание рыбы: ";
	mamm[3]->Describe();
	
	system("pause");
	system("cls");

	cout << "Желаете перезаписать в файл новые данные?" << endl;
	cout << "1 - Да" << endl;
	cout << "2 - Нет" << endl;
	cout << "--> ";
	cin >> c;
	switch (c)
	{
	case 1:
		outFile.open(initfile);
		if (!outFile)
		{
			cout << "Ошибка открытия файла!" << endl;
			exit(1);
		}
		cout << "Введите через пробел новые данные: ";
		cin >> full_name_people >> date_of_birth_people >> nationality_people >> breed_dog >> nickname_dog >> coat_color_dog >> full_name_of_the_owner_dog >> sizes_dog >> breed_cat >> nickname_cat >> coat_color_cat >> full_name_of_the_owner_cat >> sizes_cat >> breed_fish >> nickname_fish >> coat_color_fish >> full_name_of_the_owner_fish >> sizes_fish;
		outFile << full_name_people << date_of_birth_people << nationality_people << breed_dog << nickname_dog << coat_color_dog << full_name_of_the_owner_dog << sizes_dog << breed_cat << nickname_cat << coat_color_cat << full_name_of_the_owner_cat << sizes_cat << breed_fish << nickname_fish << coat_color_fish << full_name_of_the_owner_fish << sizes_fish;
		cout << "Данные записаны!" << endl;
		outFile.close();
		break;
	case 2: break;
	default: break;
	}

	return 0;
}
