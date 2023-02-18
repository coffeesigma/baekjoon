#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int point[1000001][2] = {};
    int pointNum;

    cin >> pointNum;
    for(int i = 0; i < pointNum; i++){
        cin >> point[i][0];
        cin >> point[i][1];
    }
    sort(point, point + pointNum);
    for(int i = 0; i < pointNum; i++){
        cout << point[i][0] << " " << point[i][1];
    }

    return 0;

}