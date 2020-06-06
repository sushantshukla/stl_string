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
#include <iostream>
#include<cstring>
using namespace std;
int main() {
    char s[100]="Today ,is rainy day";
    
    char *ptr=strtok(s,",");
    cout<<ptr<<endl;
    //will run the loop till ptr has soem value
   while (ptr!=NULL){ 
        ptr=strtok(NULL,",");
        cout<<ptr<<endl;
   }

    return 0;
}
//strtokenizer manually implementation
char *mystrtok(char *str, char delim){
    //accept a strig and asingle delimmiter
    static char *input=NULL;
    //input will point to "THis "than next word...
    if(str!=NULL){
        //we are maintaing the first call
        input =str;
    }
    //check here base case-after final token has been accepted
    if(input==NULL){
        return NULL;

    }
    //start extracting tokens and store them in array
    //memory exist even after function call is over
    char *output=new char [strlen(input)+1];
    int i=0;
    for(; input[i]!='\0';i++){
        if (input[i]!=delim){
            output[i]=input[i];

        }
        else{
            output[i]='\0';
            input=input +i+1;
            return output;
        }
    }
    //corner case
    output[i]='\0';
    input=NULL;
    return output;


}

int main() {
     char s[100]="Today ,is rainy day";
    
    char *ptr=mystrtok(s,',');
    cout<<ptr<<endl;
    //will run the loop till ptr has soem value
   while (ptr!=NULL){ 
        ptr=mystrtok(NULL,',');
        cout<<ptr<<endl;
   }
   return 0;
    
}


