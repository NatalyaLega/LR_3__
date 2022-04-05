#include "mammalsArray.h"
#include <iostream>
CustomArray::CustomArray()
{
	this->order = new int[0];
	this->length = new std::size_t[5];
	for (int i = 0; i < 5; i++) {
		this->length[i] = 0;
	}
	this->dogs = new Dogs[0];
	this->cats = new Cats[0];
	this->people = new People[0];
	this->fish = new Fish[0];
}

void CustomArray::push_new(Cats& cat)
{
	this->expandOrder(cat.Type());
	this->cats = expand(this->cats, this->length[cat.Type()], cat);
}

void CustomArray::push_new(Dogs& dog) {
	this->expandOrder(dog.Type());
	this->dogs = expand(this->dogs, this->length[dog.Type()]++, dog);
}
void CustomArray::push_new(People& people) {
	this->expandOrder(people.Type());
	this->people = expand(this->people, this->length[people.Type()]++, people);
}
void CustomArray::push_new(Fish& f) {
	this->expandOrder(f.Type());
	this->fish = expand(this->fish, this->length[f.Type()]++, f);
}

void CustomArray::expandOrder(int type)
{
	int* expandOrder = new int[this->length[4]+1];
	for (int i = 0; i < this->length[4]; i++) {
		expandOrder[i] = this->order[i];
	}
	expandOrder[this->length[4]] = type; //добавляем в очередь
	this->order = expandOrder; //присваиваем новый порядок чтения
	this->length[4]++;
}

CustomArray::~CustomArray()
{
	delete[] this->order;
	delete[] this->dogs;
	delete[] this->cats;
	delete[] this->fish;
	delete[] this->people;
	delete[] this->length;
}

OnReturn* CustomArray::operator[](int index)
{
	int helper = 0;
	for (int i = 0; i < index; i++) {
		if (this->order[i] == this->order[index]) {
			helper++;
		}
	}
	OnReturn onret;
	
	switch (this->order[index]) {
	case 0:
		//onret = this->dogs[helper];
		onret.dog= &this->dogs[helper];
		break;
	case 1:
		onret.cat = &this->cats[helper];
		break;
	case 2:
		onret.hum = &this->people[helper];
		break;
	case 3:
		onret.fish = &this->fish[helper];
		break;
	}
	onret.type = this->order[helper];
	return &onret;
}

std::size_t CustomArray::getSize()
{
	return this->length[4];
}
