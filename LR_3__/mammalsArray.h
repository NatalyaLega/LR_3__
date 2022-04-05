#pragma once
#include "Dogs.h"
#include "Cats.h"
#include "People.h"
#include "Fish.h"

struct OnReturn {
	union{
		Dogs* dog;
		Cats* cat;
		People* hum;
		Fish* fish;
	};
	int type = 0;
};

class CustomArray {
private:
	int *order;
public:
	std::size_t* length; //length[0] dogs length[1] cats length[2] people length[3]- fish length[4]- order
	Dogs* dogs;
	Cats* cats;
	People* people;
	Fish* fish;
	CustomArray();
	void push_new(Cats& cat);
	void push_new(Dogs& dog);
	void push_new(People& hum);
	void push_new(Fish& fish);
	void expandOrder(int type);
	~CustomArray();
	OnReturn* operator[](int index);
	std::size_t getSize();
};

template<class C>
C* expand(C* old, std::size_t old_size,C& add_me) {
	C* newArr = new C[old_size+1];
	for (int i = 0; i < old_size; i++) {
		newArr[i] = old[i];
	}
	newArr[old_size] = add_me;
	delete[] old;
	return newArr;
}