//realisation 1:
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

int f4_1() {
	cout << 45325;
	POINT op;
	HWND hWnd = GetConsoleWindow(); //�������� ���������� ���� �������
	HDC hDC = GetDC(hWnd); //�������� �������� ���������� �� ����������� �����������
	SelectObject(hDC, GetStockObject(WHITE_PEN)); //�������� ���� WHITE_PEN � ��������

	MoveToEx(hDC, 50, 50, &op); //������ ������� ����� � ���������� 50,50
	LineTo(hDC, 100, 200); //������ ����� �� ������� ����� � ����� 100, 200

	ReleaseDC(hWnd, hDC); //"�����������" ��������
	cin.get();
	return 0;
}