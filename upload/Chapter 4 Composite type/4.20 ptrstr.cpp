//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//int main()
//{
//    char animal[20] = "bitch";
//    const char* bird = "wren"; //ָ��ָ��������ǳ���������ָ��ָ��ĵ�ַ�ǿ��Ըı��
//    char* p;
//    
//    cout << "animal: " << animal << endl;
//    cout << "bird: " << bird << endl;
//    cout << "enter a kind of animal: ";
//    cin >> animal;
//    cout << "now the animal is : " << animal << "" << endl;
//    p = animal;
//    cout << "animal: " << animal << " at " << (void*)animal << endl;
//    cout << "p: " << p<<" at " << (void*)animal << endl;
//
//    //��P�����ڴ�ռ�洢animal�����ֵ
//    p = new char[strlen(animal) + 1]; //animal�ĳ��ȼ������Ŀ��ַ�
//    strcpy_s(p, strlen(animal) + 1, animal);
//    cout << "Now the value of p: " << p << " at " << (void*)p << endl;
//    delete [] p; //�ͷ�psָ����ڴ棬������ɾ��ָ��ps����(����ɾ������ָ��ķ�ʽ)
//    return 0;
//}
//
//
