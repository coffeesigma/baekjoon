#include <iostream>
#include <string>

using namespace std;

int add(int firstNum, int secondNum);

int main(){
    int testCaseNum;
    int firstNum, secondNum;

    cin >> testCaseNum;
    for(int i; i < testCaseNum; i++){
        string abLine;
        cin >> abLine;
        cout << add(abLine.at(0) - '0', abLine.at(2) - '0') << endl;
    }

    return 0;
}

int add(int firstNum, int secondNum){
    return firstNum + secondNum;
}