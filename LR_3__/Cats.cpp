#include "Cats.h"
#include <iostream>

Cats::Cats(string breed, string nickname, string coat_color, string full_name_of_the_owner, string sizes)
{
	this->breed = breed;
	this->nickname = nickname;
	this->coat_color = coat_color;
	this->full_name_of_the_owner = full_name_of_the_owner;
	this->sizes = sizes;
}

Cats::Cats() : breed(""), nickname(""), coat_color(""), full_name_of_the_owner(""), sizes("") { }

Cats::Cats(const Cats& copy_cats)
{
	breed = copy_cats.breed;
	nickname = copy_cats.nickname;
	coat_color = copy_cats.coat_color;
	full_name_of_the_owner = copy_cats.full_name_of_the_owner;
	sizes = copy_cats.sizes;
}

Cats::~Cats() { }

string Cats::Get_full_name() { return breed; }
string Cats::Get_breed() { return nickname; }
string Cats::Get_nickname() { return coat_color; }
string Cats::Get_coat_color() { return full_name_of_the_owner; }
string Cats::Get_sizes() { return sizes; }
