//#include <iostream>
//#include <string>
//using namespace std;
//const int MAX = 5;
//
//int main() {
//	int score[MAX];
//	int i = 0;
//	cout << "Welcome,enter your score down below. It must be integer!";
//	for (i; i < MAX; i++) {
//		cout << "Enter your #" << i+1 << " score" << endl;
//		while (!(cin >> score[i])) {   //����Ƿ�Ϊƥ�����ͣ�����ƥ������cinΪ�٣�ȡ��Ϊ�棬����while���
//			cout << "please enter the valid number, try again.";
//			cin.clear();//����ʧЧλ
//			while (cin.get()!='\n') { //��ȡ�ַ�
//				continue;
//			}
//		}
//	}
//	int total = 0;
//	float avg;
//	for (int j=0; j < MAX; j++) {
//		total += score[j];
//	}
//	avg = total / MAX;
//	cout << "the avg score is: " << avg << endl;
//	return 0;
//}