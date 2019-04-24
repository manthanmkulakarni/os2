#include<iostream>


using namespace std;

int ar[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1},n=sizeof(ar)/sizeof(int),frame[3];

int ispresent(int p){
	for(int i=0;i<3;i++)
	{
		if(frame[i]==p) return 1;
	}
return 0;
}


//This is to empty the frame after each algorithm use

void refresh(){

frame[0]=frame[1]=frame[2]=-1;
}

void dispFrame(){
	cout<<frame[0]<<" "<<frame[1]<<" "<<frame[2]<<endl;
}


//This is find the frame which is to be replaced in LRU

void replaceLRU(int p,int pos){

	int count=0,found[]={0,0,0};

	
	for(int i=pos-1;i>=0;i--){
		for(int j=0;j<3;j++){
			if(frame[j]==ar[i]){
				found[j]=1;
				count++;
				break;
			}
		}
		if(count==2) break;
	}
	
	for(int i=0;i<3;i++){
		if(found[i]==0){
			frame[i]=p;
			break;
		}
	}
	
}


//This is find the frame which is to be replaced in OPT

void replaceOPT(int p,int pos){

	int count=0,found[]={0,0,0};

	
	for(int i=pos+1;i<n;i++){
		for(int j=0;j<3;j++){
			if(frame[j]==ar[i]){
				found[j]=1;
				count++;
				break;
			}
		}
		if(count==2) break;
	}
	
	for(int i=0;i<3;i++){
		if(found[i]==0){
			frame[i]=p;
			break;
		}
	}
	
}


void fcfs(){
	refresh();
	int k=0,pagefault=0;
	for(int i=0;i<n;i++){
		if(ispresent(ar[i])==0)
		{
			frame[k]=ar[i];
			pagefault++;
			k=(k+1)%3;
		}
		//dispFrame();   use this to see frame after each itteration
	}

	cout<<"FCFS page fault "<<pagefault<<endl;
}

void lru(){
	refresh();
	int pagefault=0;
	for(int i=0;i<n;i++){
		if(ispresent(ar[i])==0){
			replaceLRU(ar[i],i);
			pagefault++;
		}
		//dispFrame();   use this to see frame after each itteration
	}
	cout<<"LRU page faults "<<pagefault<<endl;

}


void optimal(){
	refresh();
	int pagefault=0;
	for(int i=0;i<n;i++){
		if(ispresent(ar[i])==0){
			replaceOPT(ar[i],i);
			pagefault++;
		}
		//dispFrame();   use this to see frame after each itteration
	}
	cout<<"OPT page faults "<<pagefault<<endl;

}
int main(){
	
	fcfs();
	lru();
	optimal();

	return 0;
}

