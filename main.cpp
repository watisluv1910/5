#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h> // printf
#include <fstream> // for working with file
#include <stdlib.h> // for rand, srand
#include <time.h> // for time

using namespace std;

double err_check() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "������ �����.\n������� �������� ������:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

double err_check_for_negative() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
	{
		cout << "������ �����.\n������� �������� ������:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

int err_check_int() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "������ �����.\n������� �������� ������:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

void f1() {
	ofstream fout; // output file stream (writing)
	string path = "text_file_f1.txt"; // path to the file
	fout.open(path); 
	if (!fout.is_open()) // chacking for the successful
	{
		cout << "������ �������� �����." << endl;
	}
	else
	{	
		srand(time(NULL)); // randomizing depends on time
		for (size_t i = 0; i < 10; i++)
		{
			fout << rand() % 100 << endl;
		}
	}
	fout.close(); // closing file 
	ifstream fin; // input file stream (reading)
	fin.open(path);
	if (!fin.is_open()) // chacking for the successful
	{
		cout << "������ �������� �����." << endl;
	}
	else
	{
		int sum = 0;
		cout << "���������� � ���� ��������: " << endl;
		while (!fin.eof()) // true while not end of file
		{	
			int var = 0;
			fin >> var;
			cout << var << endl;
			sum += var;
		}
		cout << "����� ���������� � ���� ����� �����: " << sum << endl;
	}
	fin.close(); // closing file
}

void f2() {

}

void f3() {

}

void f4() {

}

void f5() {

}

int main() {
	int counter;
	setlocale(LC_ALL, "Russian");
	cout << "����� ������ �� ��������� 2.\n" << "����� ��������� ������, ������� 0.\n";
	cout << "������� ����� ������: \n";
	counter = err_check_int();
	while (counter > 0)
	{
		switch (counter)
		{
		case 1:
			f1();
			break;
		case 2:
			//f2();
			break;
		case 3:
			//f3();
			break;
		case 4:
			//f4();
			break;
		case 5:
			//f5();
			break;
		default:
			cout << "����� ������ �� ��������� 2.\n" << "����� ��������� ������, ������� 0.\n";
			break;
		}
		cout << "������� ����� ��������� ������: \n";
		cin >> counter;
	}
}