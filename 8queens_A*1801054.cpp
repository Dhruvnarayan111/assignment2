//State Space : 8*8 matrix precence of queen is represented by q1
//State transition operator: addition of new queen on each throw
//initial state: all entries on matrix is 0(i.e no queen has been placed)
//Goal state: All rows are filled such that no queens are at attacking positions
//cost: Heuristic is used for A*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool solved=false;
int cost=0;
struct chessboard{
	int array[8][8],queens,h,p,t;
};
vector<chessboard> q1;

bool compare(chessboard b1,chessboard b2){
	return (b1.h+b1.p<b2.h+b2.p);
}

void print(chessboard &tt){
	cout<<"tt"<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<tt.array[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Heuristic:"<<tt.h<<endl;
	cout<<"Cost:"<<tt.p<<endl;
	cout<<"No.of queens"<<tt.queens<<endl;
}
bool validity(chessboard &tt){
	int q=tt.queens,p=0,i,i2;
	for(i=0;i<8;i++){
		if(tt.array[q-1][i]==1) break;
	}
	for(int j=q-2;j>=0;j--){
		if(tt.array[j][i]==1){
			return false;
		}
	}
	i2=i-1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2<0) break;
		if(tt.array[j][i2]==1) return false;
		i2--;
	}
	i2=i+1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2>7) break;
		if(tt.array[j][i2]==1) return false;
		i2++;
	}
	return true;
}
void states(vector<chessboard> &q1){
	chessboard tt;
	bool oc=true;
	int size=q1.size();
	sort(q1.begin(),q1.end(),compare);
	tt=q1.front();
    vector<chessboard>::iterator it; 
    it = q1.begin(); 
    q1.erase(it); 
	int q=tt.queens;
    if(tt.queens==8) {
    	print(tt);
    	cout<<"Solution found\n"<<endl;
    	cout<<"cost is "<<cost<<endl;
    	solved=true;
    	return;
	}
	for(int i=0;i<8;i++){
		tt.array[q][i]=1;
		int pre=tt.p;
		tt.queens++;
		tt.h--;
		tt.p=pre+1;
		if(q==0||validity(tt)){
			print(tt);
			q1.push_back(tt);
			cost++;
		}
		tt.queens--;
		tt.h++;
		tt.p=pre;
		tt.array[q][i]=0;
	}
}
int main(){
	chessboard b1;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			b1.array[i][j]=0;
		}
	}
	b1.queens=0;
	b1.p=0;
	b1.h=(8-b1.queens);
        b1.t=0;
	q1.push_back(b1);
        while(!q1.empty()&&solved==false){
    	states(q1);	
	}
	return 0;
}
