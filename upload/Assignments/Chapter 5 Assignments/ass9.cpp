#include "functions.h";
//strcmp()��������ַ��رȽ������ַ���������ַ�����ȣ��򷵻� 0��
void ass9() {
	cout << "Enter words (to stop, type the word done): \n";
	string arr;
	int charCount = 0;

	while (true) {
		cin >> arr;
		if (arr == "done") {
			break;
		}
		charCount++;
	}

	cout << "total letter is: " << charCount << endl;
}