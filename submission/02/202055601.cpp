#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;
stack<int> num_call;

bool check(queue<char>& que_s, queue<char>& que_t, int calls) {
	if (que_s		 == que_t		) return true ;		// 삭제??
	//cout << " size: " << que_s.size() << " & " << que_t.size() << endl;
	if (que_s.size() <  que_t.size()) return false;
	queue<char> tempq_s, tempq_t;
	int size = que_s.size();

	for (int i = 0; i < size; i++) {
		if (que_t.front() == que_s.front())
		{	// 성공 가정하고 원소 삭제한 container 인자로 다시 호출
			tempq_s = que_s;	tempq_t = que_t;
			tempq_s.pop();		tempq_t.pop();

			if (tempq_t.empty()) {
				if (tempq_s.size() % 2 == 0) {
					if (calls == 0 || i % 2 == 0) { return true; }
					else { que_s.pop(); continue; }
				}
				else { que_s.pop(); continue; }	
			}

			
			bool found = check(tempq_s, tempq_t, calls+1);	// false return, 탐색 실패할 경우
			if (found && i%2   == 0) { return true; }
			if (found && calls == 0) { return true; }
		}
		que_s.pop();
	}
	return false;
}

int main() {
	int N;		cin >> N;
	string		str_s, str_t;
	
	//vector<queue<char>> vec_s, vec_t;

	queue<bool> que_result;
	for (int i = 0; i < N; i++) {
		cin >> str_s;	cin >> str_t;
		queue<char>	que_s, que_t;

		for (int j = 0; j < str_s.length(); j++) que_s.push(str_s[j]);
		for (int j = 0; j < str_t.length(); j++) que_t.push(str_t[j]);
		//vec_s.push_back(que_s);	vec_t.push_back(que_t);

		bool result = check(que_s, que_t, 0);
		//cout << "result " << i << " : " << result << endl;
		que_result.push(result);
	}

	while (!que_result.empty()) {
		if (que_result.front()) { cout << "YES" << endl; }
		else					{ cout << "NO"	<< endl; }
		que_result.pop();
	}

	return 0;
}