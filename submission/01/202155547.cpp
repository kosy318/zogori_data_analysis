#include <iostream>
#include <string>

using namespace std;


int palin_except(string test, int x, int y)
{
    while(x < y)
    {
        if(test[x] != test[y]) return 0; // case that is not palindrome 
        x++;
        y--;
    }
    return 1;

}
int is_palin(string str_test)
{
    int str_len;
    str_len = str_test.length();

    int start = 0;
    int finish = str_len-1;

    while(start < finish)
    {
        if(str_test[start] != str_test[finish])
        {
        	// case1: ��,�� ��� ���� �Űܵ� �� ���, �� �� �ϳ��� ȸ���̸� ����ȸ�� 
        	if(str_test[start] == str_test[finish-1] && str_test[start+1] == str_test[finish]) 
            {
                if(palin_except(str_test, start, finish-1) || palin_except(str_test, start+1, finish))  return 2;
                else return 3;
            }
            // case2: �ڸ� �ű�� ��� 
            else if(str_test[start] == str_test[finish-1]) 
            {
                if(palin_except(str_test, start, finish-1)) return 2;
                else return 3;
            }
            // case3: ���� �ű�� ��� 
            else if(str_test[start+1] == str_test[finish]) 
            {
                if(palin_except(str_test, start+1, finish)) return 2;
                else return 3;
            }
            // case4: ���̳� �ڸ� �Űܵ� ���ڰ� ���� ���� ��� 
            else
            {
                return 3;
            }
        } 
        start++;
        finish--;
    }
    return 1; // ȸ���� ��� 
}

int main()
{
    int N;
    string lines;
	
	cin >> N;
	
	for (int i=0; i<N; i++)
	{
		cin >> lines;
		cout << is_palin(lines)<<endl;
	}
    
    return 0;
}
