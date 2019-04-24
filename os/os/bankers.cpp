#include<iostream>
#include<fstream>

using namespace std;

int maximum[5][3],need[5][3],allocated[5][3],available[3],np=5,nr=3,sequence[5],ptr=0,done[5];

void getdata(){
	fstream f("bankersdata.txt");

	for(int i=0;i<np;i++)
		f>>maximum[i][0]>>maximum[i][1]>>maximum[i][2];

	for(int i=0;i<np;i++){
		done[i]=0;
		f>>allocated[i][0]>>allocated[i][1]>>allocated[i][2];
		need[i][0]=maximum[i][0]-allocated[i][0];
		need[i][1]=maximum[i][1]-allocated[i][1];
		need[i][2]=maximum[i][2]-allocated[i][2];
	}
	for(int i=0;i<nr;i++)
		f>>available[i];
}
void disp(){
	for(int i=0;i<np;i++){
		cout<<need[i][0]<<need[i][1]<<need[i][2]<<endl;
	}
	cout<<"Allocated\n";
	for(int i=0;i<np;i++)
		cout<<allocated[i][0]<<allocated[i][1]<<allocated[i][2]<<endl;
	cout<<"Max\n";
	for(int i=0;i<np;i++)
		cout<<maximum[i][0]<<maximum[i][1]<<maximum[i][2]<<endl;

}
void dispAvailable(){
	for(int i=0;i<nr;i++)
		cout<<available[i]<<" ";
cout<<endl;

}
void bankers(){
	int j,i;
	for(i=0;i<np;i++){
		if(done[i]==0){
			for(j=0;j<nr;j++)
			{
				//cout<<need[i][j]<<" "<<available[j];
				if(need[i][j]>available[j])break;
			}//cout<<endl;
			if(j==nr){
				for(int k=0;k<nr;k++)
					available[k]+=allocated[i][k];
				done[i]=1;
				sequence[ptr++]=i;
				dispAvailable();
				break;
			}
		}
	}
	if(i!=np)
		bankers();

}

int main(){

	getdata();
	disp();
	bankers();
	for(int i=0;i<np;i++){
		cout<<sequence[i]<<" ";
	}
	cout<<endl;

	return 0;
}
