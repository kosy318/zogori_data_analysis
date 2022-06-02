#include<iostream>
#include<string>
using namespace std;

//ȸ��(Palindrome) - �յ�, � �������� �о ���� ���� ������ ���ڿ�
//����ȸ�� - ���� �־��� ���ڿ� �� ��ü�δ� ȸ���� �ƴ�����, �� �ȿ� Ư�� �Ѱ��� ���ڸ��� �����Ͽ� ȸ���� �Ǵ� ���ڿ�
//ex) ȸ�� - abba, madam ����ȸ�� - summu'u's, colaloc'c'


//���õ� ���ڿ��� ȸ��(0)���� ����ȸ��(1)���� �ƹ��͵� �ƴ���(2) �Ǵ� - count��
int Palindrome(string s, int left, int right, int count)
{
	
	while (left <= right) {
		if (s[left] == s[right]) {
			left++; right--;
		}
		//ȸ���� �ȵǴµ� count == 0 �϶� 
		else if (count == 0) {
			if (Palindrome(s, left, right - 1, 1) == 1 || Palindrome(s, left + 1, right, 1) == 1) count = 1;
			else count = 2;

			break;
		}
		else {
			count = 2;
			break;
		}
	}
	return count;
}

int main(void)
{

	int N;
	cin >> N;

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		cout << Palindrome(s, 0, s.length() - 1, 0) + 1 << endl;
		s.clear();
	}

	return 0;
}