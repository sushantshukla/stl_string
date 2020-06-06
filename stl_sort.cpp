#include <iostream>
#include<algorithm>
#include<string>
#include<csting>
#include<algorithm>
using namespace std;
/*bool compare(string a,string b){
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
*/
// sort the strings
string extractstringAtKey(string str, int key){
    //strtok
    char *s= strtok((char *)str.c_str()," ");
    while(key>1){
        s=strtok(NULL," ");
        key--;
    }
    return (string)s; //convert string to sobject


}
int convertToInt(string s){
    int ans=0;
    int p=1;
    for(int i=s.length()-1 ; i>=0; i--){
        ans+= ((s[i]-'0') *p);
        p=p*10;
    }
    return ans;

}
bool numericCompare(pair<string,string> s1, pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return convertToInt(key1)< convertToInt(key2); 


}
bool lexioCompare(pair<string,string> s1, pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return key1 <  key2; 


}

int main(){
    int n;
    cin>>n;
    cin.get();//to consume the \n after the given no
    string a[100];
    for (int i=0;i<n;i++){
        getline(cin,a[i]);
    }
    int key;
    string reversal, ordering;
    cin>>key>>reversal>>ordering;

    pair <string,string> strpair[100];
    //strpair contains the string and the array
    for (int i=0 ;i<n;i++){
        strpair[i].first =a[i];
        strpair[i].second =extractstringAtKey(a[i],key);

    }
    //we will do sorting//numeric-lexographically
    if(ordering=="numeric"){
        sort(strpair,strpair+n,numericCompare);
    }
    else{
        sort(strpair,strpair+n,lexioCompare);
    }
    //reversal
    if(reversal=="true"){
        for(int i=0;i<n/2;i++){
            swap(strpair[i],strpair[n-i-1]);

        }
    }
    //print the output

    for (int i=0;i<n ;i++){
        cout<<strpair[i].first<<" "<<endl;
    }
    return 0;

}

