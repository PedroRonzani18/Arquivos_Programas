#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> v1 {1,2,3,4};
    v1.push_back(7);
    v1.insert(v1.begin(),9);
    v1.insert(v1.end(),9);

    cout << v1.front() << endl;
    cout << v1.at((v1.size())/2) << endl;
    cout << v1.back() << endl;
}