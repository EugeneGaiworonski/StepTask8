#include <iostream>
#include <string>
#include <vector>
#include <functional>
//---------------------------------------------------------------����� STUDENT-----------------------------------------
class Student
{
	int id, age;											//���������� �����
	std::string name;
	std::string st_class;

public:
	Student()											//�����������
	{
		id = 0;
		age = 16;
		name = "studentname";
		st_class = "none";
		std::cout << "\nNew student is done";
	}
public:
	~Student()											//����������
	{
		std::cout << std::endl << name << " is terminated";
	}
public:
	void redact()										//�������� ��������
	{
		std::cout << "\nName: ";
		std::getline(std::cin, name);
		std::cout << "\nAge: ";
		std::cin >> age;
		std::cout << "\nID: ";
		std::cin >> id;
		std::cout << "\nClass: ";
		std::cin >> st_class;
	}
public:
	void print()											//����� ���������� � �������� �� �����
	{
		std::cout << std::endl << name << ", " << age
			<< " years old, id is: " << id
			<< " and in " << st_class << " class";
	}
};
//--------------------------------------------------------------����� ������ STUDENT-----------------------------------------------------

//--------------------------------------------------------------------MAIN()-------------------------------------------------------------
int main()
{
	int numb_of_students = 0;								//���-�� ��������� ��� ��������
	std::cout << "Type amount of students: ";
	std::cin >> numb_of_students;

	Student buff_student;
	std::vector <Student> stud_vec;
	//stud_vec.resize(numb_of_students);
	for (int i = 0; i < numb_of_students; i++)
	{
		buff_student.redact();
		stud_vec.push_back(buff_student);
	}

	for (int i = 0; i < stud_vec.size(); i++)
	{
		stud_vec.at(i).print();
	}

	std::cout << "\nnum: ";
	int num;
	std::cin >> num;
	stud_vec.erase(stud_vec.begin() + num);

	for (int i = 0; i < stud_vec.size(); i++)
	{
		stud_vec.at(i).print();
	}

}