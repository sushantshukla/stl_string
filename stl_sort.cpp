#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
bool compare(string a,string b){
    //check if both have same length check lexographically
    if (a.length()==b.length()){
        return a<b;
    }
    //if they dont have same length check length wise,one having
    //bigger length will come first
    return a.length()>b.length();
}
int main() {
    int n;
    cin>>n;
    cin.get();
    string s[100]; // we csn also create vector of strings
    
    for (int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    sort(s,s+n,compare);
    for (int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
    
}

