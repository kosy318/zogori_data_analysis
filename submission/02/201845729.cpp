#include <iostream>

using namespace std;

string testing(string& testTarget, string& answer){
  string::iterator testTargetChar = testTarget.end() - 1;
  string::iterator answerTargetChar = answer.end() - 1;

  while(true){
    if( *testTargetChar == *answerTargetChar ){
      if( answerTargetChar == answer.begin() ) return "YES";
      if( testTargetChar == testTarget.begin() ) return "NO";
      answerTargetChar--;
      testTargetChar--;
    } else {
      if(testTargetChar == testTarget.begin() || 
         testTargetChar == testTarget.begin() + 1 ) return "NO"; 
      testTargetChar--;
      testTargetChar--;
    }
  }
}

int main(){
  int number;
  cin >> number;

  string testTarget;
  string answer;
  string result;

  while(number > 0){
    cin >> testTarget;
    cin >> answer;

    cout << testing(testTarget, answer) << endl;

    number--;
  }

  return 0;
}