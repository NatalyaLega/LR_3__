#include "Animals.h"
#include <clocale>
#include <iostream>

//что-то странное и не факт что верное!
Animals::Animals() {}

Animals::~Animals() { }

string Animals::Get_full_name() { return "Name of the owner"; }

string Animals::Get_breed() { return "Breed"; }

string Animals::Get_nickname() { return "Nickname"; }

string Animals::Get_coat_color() { return "Coat color"; }

string Animals::Get_sizes() { return "Sizec"; }

