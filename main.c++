#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h> // printf
#include <fstream> // for working with file
#include <stdlib.h> // for rand, srand
#include <time.h> // for time
#include "Header.h" // for running f4_1 or f4_2
#include <iomanip> // for setw
#include <vector> // for vector

using namespace std;

double inicializeNotNegativeDouble() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "������ �����.\n������� �������� ������:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

double inicializeDouble() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
	{
		cout << "������ �����.\n������� �������� ������:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

int inicializeNotNegativeInteger() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "������ �����.\n������� �������� ������:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // operator >> will no longer fetch data from the stream as it is in the wrong format
	}
	return temp_var;
}

int inicializeInteger() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
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
		srand(time(0)); // randomizing depends on time
		float variable;
		for (size_t i = 0; i < 10; i++)
		{
			variable = (rand() % 100 - 50) / 10.0f;
			fout << variable << endl;
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
		float sum = 0;
		cout << "���������� � ���� ��������: " << endl;
		while (!fin.eof()) // true while not end of file
		{	
			float var;
			fin >> var;
			cout << var << endl;
			sum += var;
		}
		cout << "����� ���������� � ���� ����� �����: " << sum << "." << endl;
	}
	fin.close(); // closing file
}

int defineSign(int a) { // for f2
	if (a > 0)
	{
		return 1;
	}
	else if (a == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void f2() {
	cout << "������� �����, ���� �������� ����� ����������:" << endl;
	int x = inicializeInteger();
	cout << "���� �������� ����� ������������� ����� " << defineSign(x) << " � ��������������� �������." << endl;
}

double computeSquareRectangle(double a, double b) { // for f3
	return a * b;
}

double computeSquareTriangle(double h, double x) { // for f3
	return h * x / 2;
}

double computeSquareCircle(double r) { // for f3
	return M_PI * pow(r, 2);
}

void f3() {
	cout << "�������:\n1, ���� ������ ��������� S ��������������.\n2, ���� ������ ��������� S ������������.\n3, ���� ������ ��������� S �����.\n�������� ��������:\n";
	int chose = inicializeNotNegativeInteger(); // choosing figure
	if (chose == 1)
	{
		cout << "������� �������� ������ ��������������:\n";
		double a = inicializeNotNegativeDouble();
		double b = inicializeNotNegativeDouble();
		cout << "S �������������� = " << computeSquareRectangle(a, b) << "." << endl;
	}
	else if (chose == 2)
	{
		cout << "������� �������� ���� ��������� � ���������� � ���� ������:\n";
		double h = inicializeNotNegativeDouble();
		double x = inicializeNotNegativeDouble();
		cout << "S ������������ = " << computeSquareTriangle(h, x) << "." << endl;
	}
	else if (chose == 3)
	{
		cout << "������� �������� ������� �����:\n";
		double r = inicializeNotNegativeDouble();
		cout << "S ����� = " << computeSquareCircle(r) << "." << endl;
	}
	else
	{
		cout << "���������� ������ ����� �� ��������� 3.\n";
	}
}

void f4() {
	//realisation 3:
	for (int i = 0; i < 13; ++i)
	{
		if (i < 6) {
			if (0 == i % 2) {
				for (int j = 0; j < 8; ++j)
				{
					cout << "  *";
				}
				cout.width(60);
				cout << setw(60) << setfill('/');
			}
			else {
				cout << " ";
				for (int j = 0; j < 8; ++j)
					cout << "*  ";
			}
			cout << '\n';
		}

	}
	for (int i = 1; i < 8; ++i)
	{
		if (0 == i % 2)
		{
			cout << setw(84) << setfill(' ') << '\n';
		}
		else
		{
			cout << setw(84) << setfill('/') << '\n';
		}
	}
}

void f5() {
	system("\"D:/Microsoft VS source/C++/Home Tasks/1 ����/�� �5 �� 6� ������/Task 5 (graph)/Debug/Task 5 (graph).exe\"");
}

bool isCorrect(string romanianNumber) {
	if (romanianNumber.length() > 4) {
		for (size_t i = 0; i != romanianNumber.length() - 4; i++) {
			if (romanianNumber[i] == romanianNumber[i + 1] &&
				romanianNumber[i + 1] == romanianNumber[i + 2] &&
				romanianNumber[i + 2] == romanianNumber[i + 3] &&
				romanianNumber[i + 3] == romanianNumber[i + 4]) {
				return false;
			}
		}
	}
	char romanianNumbers[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	for (size_t i = 0; i < romanianNumber.length(); i++) {	
		bool isromanianNumber = false;
		for (size_t j = 0; j < 7; j++) {
			if (romanianNumber[i] == romanianNumbers[j]) {
				isromanianNumber = true;
			}
		}
		if (!isromanianNumber) {
			return false;
		}
	}
	return true;
}

void f6() {
	cout << "Enter romaniac number:\n";
	string romanianNumber;
	cin >> romanianNumber;
	if (isCorrect( romanianNumber )) {
		char romanianNumbers[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		int arabicNumbers[7] = { 1, 5, 10, 50, 100, 500, 1000 };
		int arabicNumber = 0;
		for (size_t i = 0; i < romanianNumber.length(); i++) {
			for (size_t j = 0; j < 7; j++) {
				if (romanianNumber[i] == romanianNumbers[j]) {
					if (i + 1 < romanianNumber.length()) {
						for (size_t k = 0; k < 7; k++) {
							if (romanianNumber[i + 1] == romanianNumbers[k]) {
								if (j < k) {
									arabicNumber -= arabicNumbers[j];
								}
								else {
									arabicNumber += arabicNumbers[j];
								}
							}
						}
					}
					else {
						arabicNumber += arabicNumbers[j];
					}
				}
			}
		}
		cout << "Entered romaniac number is euqal to "<< arabicNumber << " decimal arabic number." << endl;
	}
	else {
		cout << "Wrong number entered.\nTry again and enter the number correctly.\n";
	}
}

void generatePseudoRandomNumber(int flag) {
	int nS = 0, m, a, c;
	if (flag == 0) {
		cout << "������� �������� ��������� m:\n";
		m = inicializeInteger();
		cout << "������� �������� ���������� a:\n";
		a = inicializeInteger();
		cout << "������� �������� ������������������ c:\n";
		c = inicializeInteger();
	}
	else if (flag == 1) {
		m = 37;
		cout << "�������� ��������� m: " << m << ".\n";
		a = 3;
		cout << "�������� ���������� a: " << a << ".\n";
		c = 64;
		cout << "�������� ������������������ c: " << c << ".\n";
	}
	else {
		m = 25173;
		cout << "�������� ��������� m: " << m << ".\n";
		a = 13849;
		cout << "�������� ���������� a: " << a << ".\n";
		c = 65537;
		cout << "�������� ������������������ c: " << c << ".\n";
	}
	cout << "������� �������� ������������������ maxLen:\n";
	int maxLen = inicializeNotNegativeInteger();
	cout << endl;
	for (int i = 0; i < maxLen; i++) {
		nS = (m * nS + a) % c;
		cout << "��������������� �����: " << nS << ".\n";
	}
	cout << endl;
}

void f7() {
	cout << "��������:\n1, ����� ���������� � ��������������� ������ �����.\n2, ����� ��������������� �������� ���������� �����.\n";
	int choosePath = inicializeNotNegativeInteger();
	switch (choosePath) {
	case 1 :
		generatePseudoRandomNumber(0);
		break;
	case 2 :
		cout << "��������:\n1, ����� ���������� � I ���������.\n2, ����� ���������� � II ���������.\n";
		choosePath = inicializeNotNegativeInteger();
		switch (choosePath) {
		case 1 :
			generatePseudoRandomNumber(1);
			break;
		case 2 :
			generatePseudoRandomNumber(2);
			break;
		}
		break;
	default :
		cout << "�������� ����� �� ������������� ������������ ���������.\n���������� �����.\n";
		break;
	}
}

void f8() {
	float productsArray[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
	float profitsArray[3][2] = { 0 };
	float pricesArray[4][2] = { {1.2f, 0.5f}, {2.8f, 0.4f}, {5.0f, 1.0f}, {2.0f, 1.5f} };
	cout << endl << "������� C = A * B:\n\n";
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 4; j++) {
			// i - index of seller
			// j - index of product
			// 0 - index of price
			// 1 - index of commision
			profitsArray[i][0] += productsArray[i][j] * pricesArray[j][0];
			profitsArray[i][1] += productsArray[i][j] * pricesArray[j][1];
		}
		cout << profitsArray[i][0] << "\t" << profitsArray[i][1] << endl;
	}

	float sumProfit = 0, sumCommision = 0, maxProfitSeller, maxCommissionSeller, minProfitSeller, minCommissionSeller;

	float minProfit = numeric_limits<float>::max(), minCommision = minProfit, maxProfit = numeric_limits<float>::lowest(), maxCommision = maxProfit;

	for (size_t i = 0; i < 3; i++) {

		for (size_t k = 0; k < 2; k++) {

			if (k == 0) {

				if (profitsArray[i][k] > maxProfit) {
					maxProfit = profitsArray[i][k];
					maxProfitSeller = i + 1;
				}
				if (profitsArray[i][k] < minProfit) {
					minProfit = profitsArray[i][k];
					minProfitSeller = i + 1;
				}
				sumProfit += profitsArray[i][k];
			}
			else {
				if (profitsArray[i][k] > maxCommision) {
					maxCommision = profitsArray[i][k];
					maxCommissionSeller = i + 1;
				}
				if (profitsArray[i][k] < minCommision) {
					minCommision = profitsArray[i][k];
					minCommissionSeller = i + 1;
				}
				sumCommision += profitsArray[i][k];
			}
		}
	}
	cout << "\n������ �� ������� ������:\n1)" << maxProfitSeller << "� �������� ������� ������ ����� ����� � ������, " << minProfitSeller << "� �������� ������� ������ ����� ����� � ������.\n";
	cout << "2)" << maxCommissionSeller << "� �������� ������� ���������� ������������ � ������, " << minCommissionSeller << "� �������� ������� ���������� ������������ � ������.\n";
	cout << "3)����� ����� �����, ���������� �� ��������� ������, ����� " << sumProfit << ".\n4)����� ����� ������������, ���������� ����������, ����� " << sumCommision << ".\n";
	cout << "5)����� ����� �����, ��������� ����� ���� ���������, ����� " << sumProfit + sumCommision << ".\n\n";
}

void f9() {
	string number, number_end;
	int ss1, ss2, number_int = 0;
	cout << "������� �����:\n";
	cin >> number;
	cout << "������� ����������� ������� ���������:\n";
	ss1 = inicializeNotNegativeInteger();
	cout << "������� �������� ������� ���������:\n";
	ss2 = inicializeNotNegativeInteger();
	vector <char> alphabet; // inicialization of not-fixed len vector
	for (size_t i = 65; i < 65 + 26; i++) 
	{
		alphabet.push_back((char)i); // appending letter to the end of vector
	}
	for (int i = number.length()-1; i >= 0; i--) // reversed iteration for transfer to decimal sys
	{
		char rank_s = number[i]; 
		if (find(alphabet.begin(), alphabet.end(), rank_s) != alphabet.end()) // if char is letter 
		{
			number_int += (static_cast<int>(rank_s) - 55) * pow(ss1, (number.length() - 1 - i));
		}
		else // if char is number
		{
			number_int += (static_cast<int>(rank_s) - 48) * pow(ss1, (number.length() - 1 - i));
		}
	}
	while (number_int > 0) // transfer to ss2
	{
		if (number_int % ss2 >= 10) // transfer number to letter
		{
			char rank_ch = (char)((number_int % ss2) + 55);
			number_end = rank_ch + number_end;
		}
		else
		{
			number_end = to_string(number_int % ss2) + number_end;
		}
		number_int /= ss2; // <= rank
	}
	cout << "�������� ���������: " << number_end << "." << endl;
}

int main() {
	int chooseTask;
	setlocale(LC_ALL, "Russian");
	cout << "����� ������ �� ��������� 9.\n" << "����� ��������� ������, ������� 0.\n";
	cout << "������� ����� ������: \n";
	chooseTask = inicializeNotNegativeInteger();
	while (chooseTask > 0) {
		switch (chooseTask) {
		case 1 :
			f1();
			break;
		case 2 :
			f2();
			break;
		case 3 :
			f3();
			break;
		case 4 :
			f4();
			break;
		case 5 :
			f5();
			break;
		case 6 :
			f6();
			break;
		case 7 :
			f7();
			break;
		case 8 :
			f8();
			break;
		case 9 :
			f9();
			break;
		default :
			cout << "����� ������ �� ��������� 9.\n" << "����� ��������� ������, ������� 0.\n";
			break;
		}
		cout << "������� ����� ��������� ������: \n";
		chooseTask = inicializeNotNegativeInteger();;
	}
}