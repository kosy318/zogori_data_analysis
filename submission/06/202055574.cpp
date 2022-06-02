#include <iostream>
using namespace std;

string db[1001][1001];

string compare(string a, string b){
    if(a.size() > b.size()){
        return a;
    } else if(a.size() < b.size()){
        return b;
    } else {
        if(a < b){
            return a;
        } else {
            return b;
        }
    }
}

int main(){
    string text; cin >> text;
    int len = text.size();
    int i, j;

    for(i=0; i<len; i++){
        db[i][i] = text[i];
    }

    string result, tmp;
    for(i=1; i<len; i++){
        for(j=0; i+j<len; j++){
            result = compare(db[j][i+j-1], db[j+1][i+j]);
            if(i == 1 && db[j][j] == db[i+j][i+j]){
                tmp = db[j][j] + db[i+j][i+j];
                result = compare(result, tmp);
            } else if(db[j][j] == db[i+j][i+j]){
                tmp = db[j][j] + db[j+1][i+j-1] + db[i+j][i+j];
                result = compare(result, tmp);
            }
            db[j][i+j] = result;
        }
    }

    cout << db[0][len-1];
}
