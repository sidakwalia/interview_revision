#include<iostream> 
#include<vector> 
using namespace std;

vector<string>mazepath(int sr,int sc,int er,int ec){


if(sr==er && sc==ec){
	vector<string>base;
	base.push_back("");
	return base;
}


vector<string>path_store;

if(sc+1<=ec){
vector<string>horizontal=mazepath(sr,sc+1,er,ec);

for(string s:horizontal)
	path_store.push_back("H"+s);

}

if(sr+1<=er){
vector<string>vertical=mazepath(sr+1,sc,er,ec);

for(string s:vertical)
	path_store.push_back("V"+s);

}





return path_store;


}
int cnt=0;
vector<string>mazepathdiag(int sr,int sc,int er,int ec){


if(sr==er && sc==ec){
	vector<string>base;
	base.push_back("");
	cnt++;
	return base;
}


vector<string>path_store;

if(sc+1<=ec){
vector<string>horizontal=mazepathdiag(sr,sc+1,er,ec);

for(string s:horizontal)
	path_store.push_back("H"+s);

}

if(sr+1<=er){
vector<string>vertical=mazepathdiag(sr+1,sc,er,ec);

for(string s:vertical)
	path_store.push_back("V"+s);

}

if(sr+1<=er && sc+1<=ec){
	vector<string>diag=mazepathdiag(sr+1,sc+1,er,ec);
	for(string s:diag)
		path_store.push_back("D"+s);
}





return path_store;


}

vector<string>mazepathdiag_jump(int sr,int sc,int er,int ec){


if(sr==er && sc==ec){
	vector<string>base;
	base.push_back("");
	cnt++;
	return base;
}


vector<string>path_store;

for(int jmp=1;jmp+sc<=ec;jmp++){
vector<string>horizontal=mazepathdiag_jump(sr,sc+jmp,er,ec);

for(string s:horizontal)
	path_store.push_back("H"+to_string(jmp)+s);

}

for(int jmp=1;jmp+sr<=er;jmp++){
vector<string>vertical=mazepathdiag_jump(sr+jmp,sc,er,ec);

for(string s:vertical)
	path_store.push_back("V"+to_string(jmp)+s);

}

for(int jmp=1;(jmp+sc<=ec) && (jmp+sr<=er);jmp++){
	vector<string>diag=mazepathdiag_jump(sr+jmp,sc+jmp,er,ec);
	for(string s:diag)
		path_store.push_back("D"+to_string(jmp)+s);
}





return path_store;


}

int mazepath_without(int sr,int sc,int er,int ec,string ans){


if(sr==er && sc==ec){
	cout<<ans<<" ";
	return 1;
}


int cnt=0;
if(sc+1<=ec){
cnt+=mazepath_without(sr,sc+1,er,ec,ans+"H");

}

if(sr+1<=er){
cnt+=mazepath_without(sr+1,sc,er,ec,ans+"V");
}

return cnt;
}

int main(){

int sr=0,sc=0,er=3,ec=3;
// vector<string>ans=mazepath(sr,sc,er,ec);
// vector<string>ans=mazepathdiag(sr,sc,er,ec);
// vector<string>ans=mazepathdiag_jump(sr,sc,er,ec);
mazepath_without(sr,sc,er,ec,"");
// for(auto x:ans)
// cout<<x<<" ";
// cout<<endl;
// cout<<cnt;

}