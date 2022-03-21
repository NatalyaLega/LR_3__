#include "Fish.h"
#include <iostream>

Fish::Fish(string breed, string nickname, string coat_color, string full_name_of_the_owner, string sizes)
{
	this->breed = breed;
	this->nickname = nickname;
	this->coat_color = coat_color;
	this->full_name_of_the_owner = full_name_of_the_owner;
	this->sizes = sizes;
}

Fish::Fish() : breed(""), nickname(""), coat_color(""), full_name_of_the_owner(""), sizes("") { }

Fish::Fish(const Fish& copy_fish)
{
	breed = copy_fish.breed;
	nickname = copy_fish.nickname;
	coat_color = copy_fish.coat_color;
	full_name_of_the_owner = copy_fish.full_name_of_the_owner;
	sizes = copy_fish.sizes;
}

Fish::~Fish() { }

string Fish::Get_full_name() { return breed; }
string Fish::Get_breed() { return nickname; }
string Fish::Get_nickname() { return coat_color; }
string Fish::Get_coat_color() { return full_name_of_the_owner; }
string Fish::Get_sizes() { return sizes; }

