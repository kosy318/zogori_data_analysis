#include <iostream>
#include <string>
using namespace std;

#define PALINDROME 1;
#define QUASI_PALINDROME 2;
#define OTHERS 3;

int classify (string & sentence){
  string::iterator frontToBack = sentence.begin();
  string::iterator backToFront = sentence.end() - 1;

  for (int i=0; i<sentence.length()/2; i++){
    if( *frontToBack != *backToFront ){

      string::iterator savedFrontToBack = frontToBack;
      string::iterator savedBackToFront = backToFront;

      backToFront--;
      for (int j=i ; j<sentence.length()/2; j++){
        if( *frontToBack != *backToFront ){

          frontToBack = savedFrontToBack;
          backToFront = savedBackToFront;
          frontToBack++;
          for (int k=i ; k<sentence.length()/2; k++){
            if ( *frontToBack != *backToFront ){
              return OTHERS;
            }
            frontToBack++;
            backToFront--;
          }
          return QUASI_PALINDROME;
        }
        frontToBack++;
        backToFront--;
      }
      return QUASI_PALINDROME;
    }
    frontToBack++;
    backToFront--;
  }
  return PALINDROME;
}

int main(){
  int number;
  cin >> number;

  string sentence;
  while (number>0){
    cin >> sentence;
    cout << classify(sentence) << endl;
    number--;
  }

  return 0;
}