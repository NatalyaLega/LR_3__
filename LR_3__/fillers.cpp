#include "fillers.h"

People FillHuman(istream& inp, bool output)
{
	string full_name;
	string date_of_birth;
	string nationality;
	if (output){
		std::cout << "¬ведите им€ человека: ";
	}
	
	inp >> full_name;
	if (full_name == "~") {
		return People();
	}
	if (output) {
		std::cout << "¬ведите дату рождени€: ";
	}
	inp >> date_of_birth;
	if (output) {
		std::cout << "¬ведите национальность: ";
	}
	inp >> nationality;
	People human(full_name, date_of_birth, nationality);
	return human;
}

bool isEmpty(People& hum)
{
	return hum.Get_full_name() == "";
}

void ProcessData(CustomArray& mammals, int current_type, istream& inFile, bool output)
{
	if (current_type == 0) {
		Dogs dog = FillAnimal<Dogs>(inFile, output);
		if (!isEmpty(dog))
			mammals.push_new(dog);
	}
	if (current_type == 1) {
		Cats cat = FillAnimal<Cats>(inFile, output);
		if (!isEmpty(cat))
			mammals.push_new(cat);
	}
	if (current_type == 2) {
		People hum = FillHuman(inFile, output);
		if (!isEmpty(hum))
			mammals.push_new(hum);
	}
	if (current_type == 3) {
		Fish fish = FillAnimal<Fish>(inFile, output);
		if (!isEmpty(fish))
			mammals.push_new(fish);
	}
}

void FullFile(ostream& out, People& obj) {
	out << obj.Get_full_name()<<" ";
	out << obj.Get_date_of_birth() << " ";
	out << obj.Get_nationality() << " ";
}

void Writer(ostream& outFile, People* hum, size_t len) {
	if (len == 0)
		outFile << "~";
	for (size_t i = 0; i < len; i++) {
		FullFile(outFile, hum[i]);
	}
	outFile << "\n";
}