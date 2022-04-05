#pragma once
#include "Mammals.h"
#include "People.h"
#include "Cats.h"
#include "Dogs.h"
#include "Fish.h"
#include "mammalsArray.h"
#include <iostream>
People FillHuman(istream& inp, bool output= true);
template<class Anim>
Anim FillAnimal(istream& inp, bool output= true)
{
	string breed; //порода
	string nickname; //кличка
	string coat_color;  //окрас
	string full_name_of_the_owner;  //полное им€ владельца
	string sizes;  //размеры
	if (output) {
		std::cout << "¬ведите породу: ";
	}

	inp >> breed;
	if (breed == "~") {
		return Anim();
	}
	if (output) {
		std::cout << "¬ведите кличку: ";
	}
	inp >> nickname;
	if (output) {
		std::cout << "¬ведите окраску: ";
	}
	inp >> coat_color;

	if (output) {
		std::cout << "¬ведите размеры: ";
	}

	inp >> sizes;

	if (output) {
		std::cout << "¬ведите им€ владельца: ";
	}

	inp >> full_name_of_the_owner;

	Anim animal(breed, nickname, coat_color, full_name_of_the_owner, sizes);
	return animal;
}
bool isEmpty(People& hum);

template<class Anim>
bool isEmpty(Anim& animal) {
	return animal.Get_breed() == "";
}

void FullFile(ostream& out, People& obj);

template<class Anim>
void FullFile(ostream& out, Anim& obj) {
	out << obj.Get_breed() << " ";
	out << obj.Get_nickname() << " ";
	out << obj.Get_coat_color()<<" ";
	out << obj.Get_sizes() << " ";
	out << obj.Get_full_name_of_the_owner();
}

void ProcessData(CustomArray& mammals, int cur, istream& inFile, bool output=false);

void Writer(ostream& outFile, People* hum, size_t len);

template<class Anim>
void Writer(ostream& outFile, Anim *mammals, size_t len) {
	if (len == 0)
		outFile << "~";
	for (size_t i = 0; i < len; i++) {
		FullFile(outFile, mammals[i]);
	}
	outFile << "\n";
}
