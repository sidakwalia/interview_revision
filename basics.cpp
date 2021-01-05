#include<iostream> 
#include<vector> 
using namespace std;


int x=1;
int factorial(int n){
if(n==0)
	return 1;

x=n*factorial(n-1);


return x;


}


void printincreasing(int a,int b){

if(a==b+1)
	return;


cout<<a<<" ";

printincreasing(a+1,b);

}


void printdec(int a,int b){

if(a==b+1)
	return;



printdec(a+1,b);

cout<<a<<" ";

}

void evenandodd(int a,int b){

if(a==b+1)
	return;


if(a%2==0) //
cout<<"Even no : "<<a<<endl;

evenandodd(a+1,b);
if(a%2!=0)
cout<<"Odd no is : "<<a<<endl;


}


vector<string>keypad_words={":","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","&%","#"};

							// 0,1,2,3,4,5,6,7,8,9
vector <string> letterCombinations(string str)

{	if(str.length()==0){
	vector<string>base;
	base.push_back("");
	return base;
}
int idx=str[0]-'0';          //in 567 we found the 0th element in string for ex 5
string word=keypad_words[idx];      //word corresponding to the index 5


vector<string>ans=letterCombinations(str.substr(1));
vector<string>myans;


for(string s:ans){

for(int i=0;i<word.length();i++){
	myans.push_back(s+word[i]);
}
}


return myans;
}













int main(){


// cout<<factorial(5);

int a=0,b=5;

// printincreasing(a,b);
// // printdec(a,b);

// evenandodd(0,10);

vector<string>ans=numpad("567");
for(string x:ans)
cout<<x<<" ";

}