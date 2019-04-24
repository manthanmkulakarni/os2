#include<iostream>
#include<fstream>

using namespace std;

int file[10][3],memory[12][3],nm=12,np=10;

void getdata(){
	fstream f("memory.txt");
	for(int i=0;i<np;i++){
		file[i][0]=i+1;
		f>>file[i][1];
	}

	for(int i=0;i<nm;i++)
	{
		memory[i][0]=i+1;
		f>>memory[i][1];
	}
}

void firstfit(){

	for(int i=0;i<np;i++){
		file[i][2]=-1;
	}
	for(int i=0;i<nm;i++)
		memory[i][2]=0;

	for(int i=0;i<np;i++){
		for(int j=0;j<nm;j++){
			if(file[i][1]<=memory[j][1]&&memory[j][2]!=1){
				file[i][2]=memory[j][0];
				memory[j][2]=1;
				break;
			}
		}
	}
	cout<<"\nFirst fit\nFile allocation details\n";
	for(int i=0;i<np;i++)
		cout<<file[i][0]<<" "<<file[i][1]<<" "<<file[i][2]<<endl;

}

void bestfit(){
	for(int i=0;i<np;i++){
		file[i][2]=-1;
	}

	for(int i=0;i<nm;i++)
		memory[i][2]=0;

	int min=999,mini=-1;
	for(int i=0;i<np;i++){
		min=999;
		mini=-1;
		for(int j=0;j<nm;j++){
			if(memory[j][2]!=1&&memory[j][1]>file[i][1]&&min>(memory[j][1]-file[i][1])){
				min=memory[j][1]-file[i][1];
				mini=j;
			}
		}
		if(mini!=-1){
			file[i][2]=memory[mini][0];
			memory[mini][2]=1;
		}
	}

}

void worstfit(){
		for(int i=0;i<np;i++){
		file[i][2]=-1;
	}

	for(int i=0;i<nm;i++)
		memory[i][2]=0;

	int max=0,maxi=-1;
	for(int i=0;i<np;i++){
		max=0;
		maxi=-1;
		for(int j=0;j<nm;j++){
			if(memory[j][2]!=1&&memory[j][1]>file[i][1]&&max<(memory[j][1]-file[i][1])){
				max=memory[j][1]-file[i][1];
				maxi=j;
			}
		}
		if(maxi!=-1){
			file[i][2]=memory[maxi][0];
			memory[maxi][2]=1;
		}
	}

}

void disp(){
	cout<<"\nFile allocation details\n";
	for(int i=0;i<np;i++)
		cout<<file[i][0]<<" "<<file[i][1]<<" "<<file[i][2]<<endl;

}
void dispMemory(){
	cout<<"Memory location\n";
	for(int i=0;i<nm;i++)
		cout<<memory[i][0]<<" "<<memory[i][1]<<endl;

}
int main(){

	getdata();
	dispMemory();
	firstfit();

	bestfit();cout<<"\nBest fit";
	disp();

	worstfit();cout<<"\nWorst fit";
	disp();

	return 0;
}
