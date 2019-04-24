#include<iostream>
#include<fstream>

using namespace std;

int process[6][3],np=6,orderpriority[6][2],clk=0,temp[100][2],alloted[6],ptrpriority=0,orderfifo[6][2],ordersjf[6][2],ptrsjf=0,orderrr[6][2];

void getdata(){
	fstream f("process.txt");
	for(int i=0;i<np;i++)
		f>>process[i][0]>>process[i][1]>>process[i][2];

	for(int i=0;i<np;i++)
		alloted[i]=0;
}
void disp(){
	for(int i=0;i<np;i++)
		cout<<process[i][0]<<" "<<process[i][1]<<" "<<process[i][2]<<endl;

}

void sort(){
	int min,temp;
	for(int i=0;i<np;i++){

		min=i;
		for(int j=i+1;j<np;j++){
			if(process[j][0]<process[min][0]){
				min=j;
			}
		}
		temp=process[min][0];
		process[min][0]=process[i][0];
		process[i][0]=temp;

		temp=process[min][1];
		process[min][1]=process[i][1];
		process[i][1]=temp;

		temp=process[min][2];
		process[min][2]=process[i][2];
		process[i][2]=temp;
	}

}
void sjfsort(){
	
	int min,temp;
	for(int i=0;i<np;i++){
		alloted[i]=0;
		min=i;
		for(int j=i+1;j<np;j++){
			if(process[j][1]<process[min][1]){
				min=j;
			}
		}
		temp=process[min][0];
		process[min][0]=process[i][0];
		process[i][0]=temp;

		temp=process[min][1];
		process[min][1]=process[i][1];
		process[i][1]=temp;

		temp=process[min][2];
		process[min][2]=process[i][2];
		process[i][2]=temp;
	}
	

}

void sjf(){
	int i;
	for( i=0;i<np;i++){
		if(process[i][2]<=clk&&alloted[i]!=1){
			break;
		}
	}
	if(i!=np){
		alloted[i]=1;
		ordersjf[ptrsjf][0]=process[i][0];
		ordersjf[ptrsjf++][1]=clk-process[i][2];
		clk+=process[i][1];
		sjf();
	}

}
void fifo(){
	clk=0;
	int min,temp;
	for(int i=0;i<np;i++){

		min=i;
		for(int j=i+1;j<np;j++){
			if(process[j][2]<process[min][2]){
				min=j;
			}
		}
		temp=process[min][0];
		process[min][0]=process[i][0];
		process[i][0]=temp;

		temp=process[min][1];
		process[min][1]=process[i][1];
		process[i][1]=temp;

		temp=process[min][2];
		process[min][2]=process[i][2];
		process[i][2]=temp;
	}
	for(int i=0;i<np;i++){
		orderfifo[i][0]=process[i][0];
		orderfifo[i][1]=clk-process[i][2];
		clk+=process[i][1];
	}

}
void priority(){
	
	int i;
	for(i=0;i<np;i++){
		if(process[i][2]<=clk&&alloted[i]!=1){
			break;
		}
	}
	if(i!=np){
	alloted[i]=1;
	orderpriority[ptrpriority][1]=clk-process[i][2];
	orderpriority[ptrpriority++][0]=process[i][0];
	clk+=process[i][1];
	 priority();

	}
}


void roundrobin(){

	clk=0;
	int totaltime=0,previous[np];
	for(int i=0;i<np;i++){
		alloted[i]=previous[i]=0;
		orderrr[i][0]=process[i][0];
		orderrr[i][1]=0;
		totaltime+=process[i][1];
	}


	for(int i=0;clk<totaltime;i=(i+1)%np){
		if(process[i][2]<=clk&&alloted[i]!=process[i][1]){
			alloted[i]++;
			orderrr[i][1]+=clk-previous[i];
			previous[i]=clk;
			clk++;
		}	
		
	}

}

int main(){

	getdata();
	
	sort();
	disp();

	clk=0;
	priority();
	cout<<"prority\n";
	for(int i=0;i<ptrpriority;i++)
		cout<<orderpriority[i][0]<<" "<<orderpriority[i][1]<<endl;

	fifo();
	cout<<"Fifo\n";
	for(int i=0;i<6;i++)
		cout<<orderfifo[i][0]<<" "<<orderfifo[i][1]<<endl;

	clk=0;
	sjfsort();
	disp();
	sjf();
	cout<<"Sjf\n";
	for(int i=0;i<6;i++)
		cout<<ordersjf[i][0]<<" "<<ordersjf[i][1]<<endl;

	roundrobin();
	cout<<"RR\n";
	for(int i=0;i<6;i++)
		cout<<orderrr[i][0]<<" "<<orderrr[i][1]<<endl;

	return 0;
}
