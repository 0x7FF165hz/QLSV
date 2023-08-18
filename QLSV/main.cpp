#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;
const std::string filename = "data.txt";

/* LIST FUNCTION USE IN THIS PROGRAMMING :
- Feature Function :
+ clearScreen() : Clear Screen in console
+ press() : push to console -> "Press any key to continue"

- Key Function :
+ load_person_from_data () : Load person from data.txt to console
+ _print_person() : print list person in data.txt
+ _list_menu() : Print list menu choice
+ _add_person() : add a person to vecotr
+ _change_person() : change a person with index
+ _remove_person() : remove a person with index
+ _find_person() : find a person in vector
+ _sort_person() : + sort with name
				   + sort with age
				   + sort with score
+ _statictical() : + average score
				   + % medium score
				   + % high score
				   + % list person best of score
+_write_vector_to_file() : Save person_list to file data.txt
*/

// Structure for one person
struct Person
{
	std::string fullname;
	int age;
	float score;

	Person(std::string fullname, int age, float score) :
		fullname(fullname), age(age), score(score)
	{}
	Person()
	{}
};
// Clear after user input wrong
void clearScreen() {
#ifdef _WIN32
	std::system("cls"); // On Windows
#else
	std::system("clear"); // On other platforms
#endif
}
//Function press any key to continue
void press() {
	cout << "Press any key to continue...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return;
}
// Load person from data.txt to console
void _load_person_from_data(std::vector<Person>& person_list) {
	Person person;
	std::ifstream output_File(filename);
	std::string line;

	//get person in data and save to vector
	while (std::getline(output_File, line)) {
		std::stringstream ss(line);
		std::getline(ss, person.fullname, ';');
		ss >> person.age;
		ss.ignore();
		ss >> person.score;
		person_list.push_back(person);
	}
}
//print list person
void _print_person(std::vector<Person>& person_list) {
	cout << "+" << std::setfill('-') << std::setw(7) << "+" << std::setw(40) << "+" << "\n";
	cout << '|' << " STT" << "  |" << std::left << std::setfill(' ') << std::setw(22) << " Ho va ten" << "|" << std::setw(7) << " Tuoi" << '|' << std::setw(8) << " Diem" << '|' << "\n";
	cout << "+" << std::setfill('-') << std::setw(7) << std::right << "+" << std::setw(40) << std::right << "+" << "\n";
	for (int i = 0; i < person_list.size(); i++) {
		cout << "|" << "  " << std::setfill(' ') << std::left << std::setw(4) << i + 1 << "|" << " " << std::setw(21)
			<< person_list[i].fullname << "|" << " " << std::setw(6) << person_list[i].age << "|" << " " << std::setw(7) << person_list[i].score << "|" << "\n";
	}
	cout << "+" << std::setfill('-') << std::setw(7) << std::right << "+" << std::setw(40) << std::right << "+" << "\n";
}
// add person to vector from console
void _add_person(std::vector<Person>& person_list) {
	Person person;
	cout << "\t\t(!) Nhap ten: "; cin >> person.fullname;
	cout << "\t\t(!) Nhap tuoi: "; cin >> person.age;
	cout << "\t\t(!) Nhap diem: "; cin >> person.score;
	person_list.push_back(person);
}
// insert a person to vector from console
void _change_person(std::vector<Person>& person_list) {
	int choice;
	Person person;
	cout << "Nhap STT sinh vien muon sua: "; cin >> choice;
	cout << "\t\t(!) Nhap ten: "; cin >> person.fullname;
	cout << "\t\t(!) Nhap tuoi: "; cin >> person.age;
	cout << "\t\t(!) Nhap diem: "; cin >> person.score;
	for (int i = 0; i < person_list.size(); i++) {
		if (i == choice - 1) person_list[i] = person;
	}
}
//remove a person in vector, input from console
void _remove_person(std::vector<Person>& person_list) {
	int choice;
	cout << "Nhap STT sinh vien can xoa: "; cin >> choice;
	person_list.erase(person_list.begin() + choice - 1);
}
// Find a person in vector with character from console
void _find_person(std::vector<Person>& person_list) {
	std::string character;
	Person person;
	std::vector<Person> person_list_new;
	cout << "\t(!)Nhap ki tu ban can tim: "; cin >> character;
	for (int i = 0; i < person_list.size(); i++) {
		size_t found = person_list[i].fullname.find(character);
		if (found != std::string::npos) {
			person_list_new.push_back(person_list[i]);
		}
	}
	_print_person(person_list_new);
}
//Sort person with name
void _sort_person_with_name(std::vector<Person> person_list) {
	Person temp;
	for (int i = 0; i < person_list.size(); i++) {
		for (int j = i + 1; j < person_list.size(); j++) {
			if (person_list[i].fullname > person_list[j].fullname) {
				temp = person_list[i];
				person_list[i] = person_list[j];
				person_list[j] = temp;
			}
		}
	}
	_print_person(person_list);
}
//Sort person with age
void _sort_person_with_age(std::vector<Person> person_list) {
	Person temp;
	for (int i = 0; i < person_list.size(); i++) {
		for (int j = i + 1; j < person_list.size(); j++) {
			if (person_list[i].age < person_list[j].age) {
				temp = person_list[i];
				person_list[i] = person_list[j];
				person_list[j] = temp;
			}
		}
	}
	_print_person(person_list);
}
//Sort person with score
void _sort_person_with_score(std::vector<Person> person_list) {
	Person temp;
	for (int i = 0; i < person_list.size(); i++) {
		for (int j = i + 1; j < person_list.size(); j++) {
			if (person_list[i].score < person_list[j].score) {
				temp = person_list[i];
				person_list[i] = person_list[j];
				person_list[j] = temp;
			}
		}
	}
	_print_person(person_list);
}
// Average score of list
void _average_score(std::vector<Person> person_list) {
	float sum = 0;
	for (int i = 0; i < person_list.size(); i++) {
		sum = sum + person_list[i].score;
	}
	sum = sum / person_list.size();
	cout << "Diem trung binh cua ca lop la: " << sum << "\n";
}
// Statictical medium score of list
void _medium_score(std::vector<Person> person_list) {
	float sum = 0;
	for (int i = 0; i < person_list.size(); i++) {
		if (person_list[i].score >= 7 && person_list[i].score < 8.5) sum++;
	}
	sum = (sum / person_list.size()) * 100;
	cout << "% Hoc sinh kha la: " << sum << "%" << "\n";
}
// Statictical high score of list
void _high_score(std::vector<Person> person_list) {
	float sum = 0;
	for (int i = 0; i < person_list.size(); i++) {
		if (person_list[i].score >= 8.5 && person_list[i].score <= 10) sum++;
	}
	sum = (sum / person_list.size()) * 100;
	cout << "% Hoc sinh gioi la: " << sum << "%" << "\n";
}
// Statictical best person of list
void _highest_person_score(std::vector<Person> person_list) {
	std::vector<std::string> highest_person;
	int max_index = 0;
	for (int i = 1; i < person_list.size(); i++) {
		if (person_list[i].score > person_list[max_index].score) {
			max_index = i;
		}
	}
	for (int i = 0; i < person_list.size(); i++) {
		if (person_list[i].score == person_list[max_index].score) {
			highest_person.push_back(person_list[i].fullname);
		}
	}
	cout << "Nguoi cao diem nhat trong lop la: ";
	for (int i = 0; i < highest_person.size(); i++) {
		cout << "\n" << "\t\t\t\t" << i+1 << ". " << highest_person[i];
	}
	cout << "\n";
}
//Sort person with choice
void _sort_person(std::vector<Person>& person_list) {
	int command;
	cout << "\t\t(!) Sap xep theo ten" << "\n";
	cout << "\t\t(!) Sap xep theo tuoi" << "\n";
	cout << "\t\t(!) Sap xep theo diem" << "\n";
	cout << "Nhap lua chon cua ban: "; cin >> command;

	switch (command) {
	case 1:
		_sort_person_with_name(person_list);
		break;
	case 2:
		_sort_person_with_age(person_list);
		break;
	case 3:
		_sort_person_with_score(person_list);
		break;
	}
}
//Statictical person list in vector with some atribute
void _statictical(std::vector<Person>& person_list) {
	int command;
	cout << "\t\t(!) Diem trung binh cua ca lop" << "\n";
	cout << "\t\t(!) % Diem kha trong ca lop" << "\n";
	cout << "\t\t(!) % Diem gioi trong ca lop" << "\n";
	cout << "\t\t(!) Nguoi cao diem nhat trong lop" << "\n";
	cout << "Nhap lua chon cua ban: "; cin >> command;

	switch (command) {
	case 1:
		_average_score(person_list);
		break;
	case 2:
		_medium_score(person_list);
		break;
	case 3:
		_high_score(person_list);
		break;
	case 4:
		_highest_person_score(person_list);
		break;
	}
}
//Write vector to data.txt
void _write_vector_to_file(std::vector<Person>& person_list) {
	std::ofstream writeFile(filename);

	for (int i = 0; i < person_list.size(); i++) {
		writeFile << person_list[i].fullname << ';' << person_list[i].age << ';' << person_list[i].score << "\n";
	}
	cout << "Da luu du lieu vao file " << filename << "\n";
}
// Print list menu choice
int _list_menu() {
	int command = 0;
	clearScreen();
	cout << "+" << std::setfill('-') << std::setw(7) << "+" << std::setw(40) << "+" << "\n";
	cout << '|' << " STT" << "  |" << std::setfill(' ') << std::right << std::setw(28) << "Danh sach lua chon" << std::setw(12) << "|" << "\n";
	cout << '|' << std::setfill('-') << std::setw(7) << "|" << std::setw(40) << "|" << "\n";
	cout << '|' << "  1" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "In danh sach sinh vien" << "|" << "\n";
	cout << '|' << "  2" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Them" << "|" << "\n";
	cout << '|' << "  3" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Sua" << "|" << "\n";
	cout << '|' << "  4" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Xoa" << "|" << "\n";
	cout << '|' << "  5" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Tim kiem" << "|" << "\n";
	cout << '|' << "  6" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Sap xep" << "|" << "\n";
	cout << '|' << "  7" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Thong ke" << "|" << "\n";
	cout << '|' << "  8" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Sao luu" << "|" << "\n";
	cout << '|' << "  9" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Thoat" << "|" << "\n";
	cout << "+" << std::setfill('-') << std::setw(7) << std::right << "+" << std::setw(40) << std::right << "+" << "\n";
	cout << "Nhap lua chon cua ban: "; cin >> command;
	return command;
}
//entry point
int main()
{
	std::vector<Person> person_list;
	_load_person_from_data(person_list);
	while (true) {
		int command = _list_menu();
		switch (command) {
		case 1:
			_print_person(person_list);
			press();
			break;
		case 2:
			_add_person(person_list);
			press();
			break;
		case 3:
			_change_person(person_list);
			press();
			break;
		case 4:
			_remove_person(person_list);
			press();
			break;
		case 5:
			_find_person(person_list);
			press();
			break;
		case 6:
			_sort_person(person_list);
			press();
			break;
		case 7:
			_statictical(person_list);
			press();
			break;
		case 8:
			_write_vector_to_file(person_list);
			press();
			break;
		case 9:
			return 0;
		defaut:
			break;
		}
	}
}
