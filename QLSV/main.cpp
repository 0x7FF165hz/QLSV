#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;
const std::string filename = "data.txt";

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

//print list person in data.txt
void _print_person(std::vector<Person>& person_list) {
	for (int i = 0; i < person_list.size(); i++)
	{
		cout << "Ten: " << person_list[i].fullname << "\n";
		cout << "Tuoi: " << person_list[i].age << "\n";
		cout << "Diem: " << person_list[i].score << "\n";
	}
}

//Function press any key to continue
void press() {
	cout << "Press any key to continue...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	cin.get();
	return;
}

// Print list menu choice
int _list_menu() {
	int command = 0;
	clearScreen();
	cout << "+" << std::setfill('-') << std::setw(7) << "+" << std::setw(40)                                                   << "+" << "\n";
	cout << '|' << " STT" << "  |"<< std::setfill(' ') << std::right << std::setw(28) << "Danh sach lua chon" << std::setw(12) << "|" << "\n";
	cout << '|' << std::setfill('-') << std::setw(7) << "|" << std::setw(40)                                                   << "|" << "\n";
	cout << '|' << "  1" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "In danh sach sinh vien"             << "|" << "\n";
	cout << '|' << "  2" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Them"                               << "|" << "\n";
	cout << '|' << "  3" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Sua"                                << "|" << "\n";
	cout << '|' << "  4" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Xoa"                                << "|" << "\n";
	cout << '|' << "  5" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Tim kiem"                           << "|" << "\n";
	cout << '|' << "  6" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Sap xep"                            << "|" << "\n";
	cout << '|' << "  7" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Thong ke"                           << "|" << "\n";
	cout << '|' << "  8" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Sao luu"                            << "|" << "\n";
	cout << '|' << "  9" << "   | " << std::left << std::setfill(' ') << std::setw(38) << "Thoat"                              << "|" << "\n";
	cout << "+" << std::setfill('-') << std::setw(7)<< std::right << "+" << std::setw(40) << std::right                        << "+" << "\n";
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
		case 9:
			return 0;
		defaut:
			break;
		}
	}
	
}
