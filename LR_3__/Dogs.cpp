#include "Dogs.h"
#include <iostream>

Dogs::Dogs(string breed, string nickname, string coat_color, string full_name_of_the_owner, string sizes)
{
	this->breed = breed;
	this->nickname = nickname;
	this->coat_color = coat_color;
	this->full_name_of_the_owner = full_name_of_the_owner;
	this->sizes = sizes;
}

Dogs::Dogs() : breed(""), nickname(""), coat_color(""), full_name_of_the_owner(""), sizes("") { }

Dogs::Dogs(const Dogs& copy_dogs)
{
	breed = copy_dogs.breed;
	nickname = copy_dogs.nickname;
	coat_color = copy_dogs.coat_color;
	full_name_of_the_owner = copy_dogs.full_name_of_the_owner;
	sizes = copy_dogs.sizes;
}
Dogs::~Dogs() { }

string Dogs::Get_full_name_of_the_owner() { return full_name_of_the_owner; }
string Dogs::Get_breed() { return breed; }
string Dogs::Get_nickname() { return nickname; }
string Dogs::Get_coat_color() { return coat_color; }
string Dogs::Get_sizes() { return sizes; }

void Dogs::Describe()
{
	Get_full_name_of_the_owner();
	Get_breed();
	Get_nickname();
	Get_coat_color();
}
