#include "header.h";
void set(stringy& pt, const char* ch) {
	pt.str = new char[ArSize]; // �����㹻����ڴ����洢�ַ���������ֹ�ַ�
	strcpy_s(pt.str, ArSize, ch);
}
void show(const stringy &pt,int n) {
	for (int i = 0; i < n; i++)
	{
		cout << pt.str << endl;
	}
	cout << endl;
}
void show(const char* ch, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << ch << endl;
	}
	cout << endl;
}

//main
//#include "header.h"
//int main()
//{
//	stringy beany;
//	char testing[] = "Reality isn't what it used to be.";
//	set(beany, testing);
//	show(beany);
//	show(beany, 2);
//	testing[0] = 'D';
//	testing[1] = 'u';
//	show(testing);
//	show(testing, 3);
//	show("Done!");
//	return 0;
//}