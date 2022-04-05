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
#include "fillers.h"
#include "mammalsArray.h"
#include <any>
/*Вариант - 11 Создать абстрактный класс «Млекопитающие».Определить производные классы
«Животные» и «Люди».У животных определить производные классы собак, котов и рыб, которые
содержат в себе породу, кличку, окрас, ФИО владельца и размеры.Для класса «Люди» существуют
поля : ФИО, дата рождения, национальность.Определить виртуальные функции описания
человека, собаки, кота и рыбы.*/

int menu() {
	setlocale(LC_ALL, "Rus");
	std::cout << "Кого будем вводить?" << endl;
	std::cout << "1) Собака" << endl;
	std::cout << "2) Кошка" << endl;
	std::cout << "3) Человек" << endl;
	std::cout << "4) Рыба" << endl;
	std::cout << "5) End" << endl;
	int i;
	std::cin >> i;
	return i;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	string initfile = ".\\data.txt";
	ifstream inFile;
	ofstream outFile;

	int c;
	std::cout << "Вас приветствует программа 3-ей лабораторной по ТП!" << endl;
	std::cout << "Как Вы хотите ввести данные?" << endl;
	std::cout << "1 - Вручную" << endl;
	std::cout << "2 - Из файла" << endl;
	std::cout << "0 - Выход из программы" << endl;
	std::cout << "--> ";
	std::cin >> c;
	CustomArray mammals;
	switch (c)
	{
	case 1: //Вручную
		system("cls");
		{
			int current_type= 0;
			while (current_type+1 != 5) {
				current_type = menu()-1;
				ProcessData(mammals, current_type, std::cin, true);
			}
			break;
		}
	case 2: {
		system("cls");
		inFile.open(initfile);
		if (!inFile)
		{
			std::cout << "Ошибка открытия файла!" << endl;
			exit(1);
		}
		/*Сначала (построчно)
		читаем собак
		потом читаем кошек
		потом читаем людей
		потом рыб
		если не хотим вводить какой-то тип - ~ в начале строки*/
		int current_type = 0;
		while (!inFile.eof()) {
			ProcessData(mammals, current_type, inFile);
			char c;
			inFile.get(c);
			if (c == '\n') {
				current_type++;
				break;
			}
			inFile.unget();
		}
		std::cout << "Данные взяты!" << endl;
		inFile.close();
		break;
	}
	case 0:
		exit(0);
		break;
	default:
		break;
	}
	
	std::cout << "Введенные данные: " << endl;

	for (int i = 0; i < mammals.getSize(); i++) {
		switch (mammals[i]->type)
		{
		case 0:
			mammals[i]->dog->Describe();
			break;
		case 1:
			mammals[i]->cat->Describe();
			break;
		case 2:
			mammals[i]->hum->Describe();
			break;
		case 3:
			mammals[i]->fish->Describe();
			break;
		}
	}
	
	system("pause");
	system("cls");

	std::cout << "Желаете перезаписать в файл новые данные?" << endl;
	std::cout << "1 - Да" << endl;
	std::cout << "2 - Нет" << endl;
	std::cout << "--> ";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1: {
		outFile.open(initfile);
		if (!outFile)
		{
			cout << "Ошибка открытия файла!" << endl;
			exit(1);
		}
		//ввод
		if (c==2) {
			int current_type = 0;
			while (current_type != 4) {
				current_type = menu() - 1;
				ProcessData(mammals, current_type, std::cin, true);
			}
		}
		//вывод в файл
		Writer(outFile, mammals.dogs, mammals.length[0]);
		Writer(outFile, mammals.cats, mammals.length[1]);
		Writer(outFile, mammals.people, mammals.length[2]);
		Writer(outFile, mammals.fish, mammals.length[3]);
		std::cout << "Данные записаны!" << endl;
		outFile.close();
		break;
	}
	case 2: 
		break;
	default: 
		break;
	}

	return 0;
}
