#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;


//k���� ���� �ҹ��ڷθ� ������ ���ڿ� s
//Ư�����ڸ� backspace�� �ٲٸ� ���ڿ� t�� ��´�(��, ù ���ڸ� backspace�� �ٲٸ� ��ȭ�� ���ٰ� ����)

//backspce = '\'�� �����Ѵ�
//ex) "abcbd" - 1,4��° ==> "\bc\d ==> "bd


//���� : �־��� ���ڿ� s���� backspace�� ���� ���ڿ� t�� ���� �� �ִ��� ���
// Example 
// "abcaa"���� "a", "aa"�� ���� �� �ִ°� - YES
// "abcbd"���� "bb"�� ���� �� �ִ°� - NO

bool check(vector<char> v, string t) {
	
	string temp;
	for (int i = 0; i < v.size(); i++)
		temp.push_back(v[i]);

	if (temp == t)
		return true;
	return false;

}

void backspace(string s, string t) {
	//���� ���̰� Ȧ�� - �Ǿ� ����, ¦���� ������
	int sub = s.length() - t.length();
	if (sub < 0) {
		cout << "NO\n";
		return;
	}

	if (sub > 0 && sub % 2 != 0)
		s[0] = '\b';

	int j = 0;
	//stack�� push�� ���ڿ� ������ Ȯ���� vector
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == '\b') continue;

		if (s[i] == t[j]) 
			j++;
		else 
			s[i + 1] = '\b';
	}
	
	vector<char> v;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '\b') {
			if (!v.empty())
				v.pop_back();
		}
		else
			v.push_back(s[i]);
	}

	if (check(v, t))
		cout << "YES\n";
	else 
		cout << "NO\n";
}



int main(void) 
{

	// stack�� �������� �־ t�� ���� ���ڸ� ������ ������ Ȯ��
	// ���ڰ� ���� ������ stack�� push
	// ù��° Ȯ�ο����� ¦���� Ȧ���� ���x
	// �� ���� Ȯ�ο����� ������ ¦��

	int N;
	cin >> N;
	string s, t;
	
	for (int i = 0; i < N; i++) {

		cin >> s >> t;
		backspace(s, t);
	}


	return 0;
}
