#include "functions.h";
//���뺯��
int input_scores(float scores[],int max) {
	int count = 0;
	for (int i = 0; i < max; i++)
	{
		cout << "input the #" << i + 1 << " score: \n";
		cin >> scores[i];
		if ((scores[i] < 0) || scores[i] > (float)100) {
			break;
		}
		else {
			count++;
			cin.get();
		}
	}
	return count;
}

//��ʾ����
void showScores(float scores[],int count) {
	for (int i = 0; i < count; i++)
	{
		cout << "score #" << i + 1 << " : " << scores[i] << endl;
	}
}

//����ƽ���ɼ�
float calculate_averageScore(float score[], int count) {
	float total=0;
	for (int i = 0; i < count; i++)
	{
		total += score[i];
	}
	float avg = total / count;
	return avg;
}


//int main()
//{
//	//��������
//	float temp_scores[maxNumber_scores];
//	int score_count = 0;
//	score_count = input_scores(temp_scores, maxNumber_scores);
//	float* scores = new float[score_count];
//	int i = 0;
//	while (i < score_count) {
//		scores[i] = temp_scores[i];
//		i++;
//	}
//	/*for (int i = 0; i < score_count; i++)
//	{
//		scores[i] = temp_scores[i];
//	}*/
//	//��ʾ�ɼ�
//	showScores(scores, score_count);
//
//	//����ƽ���ɼ�
//	float avg;
//	avg = calculate_averageScore(scores, score_count);
//	cout << "The average score is: " << avg << endl;
//	delete[]scores;
//}