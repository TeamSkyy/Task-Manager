#include "functions.h";
//strcmp()��������ַ��رȽ������ַ���������ַ�����ȣ��򷵻� 0��
void ass8() {
	cout << "Enter words (to stop, type the word done): \n";
	char arr[100];
	int charCount = 0;
	
	while (true) {
		cin >> arr;  //cin >> �������ո���з�ʱ��ֹͣ��ȡ��
		//�� cin.getline() ���Զ�ȡ�����ո����ڵ���������
		if (strcmp(arr, "done") == 0) {
			break;
		}
		charCount++;
	}

	cout << "total letter is: " << charCount << endl;
}