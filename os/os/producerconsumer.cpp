#include<iostream>

using namespace std;

int mutex=1,full=0,empty=3,numOfBuffers=3;

void wait(int &temp){
	temp--;
}
void signal(int &temp){
	temp++;
}

void producer(){
	wait(mutex);
	signal(full);
	wait(empty);
	signal(mutex);
}
void consumer(){
	wait(mutex);
	signal(empty);
	wait(full);
	signal(mutex);
}
int main(){
	int choice;
	cout<<"1 Consumer 2 Producer 3 Exit\n";

	while(1){
	cout<<"Enter your choice\n";
	cin>>choice;
	
	switch(choice){
		case 1:
			if(empty==numOfBuffers)
				cout<<"Consumer error Buffer is empty\n";
			else{
				cout<<"Consumer called\n";
				consumer();
			}
			break;
		case 2:
			if(full==numOfBuffers)
				cout<<"Producer error Buffer is full\n";
			else{
				cout<<"Producer called\n";
				producer();
			}
			break;
		case 3:
			goto stop;

		}
	}
stop:
return 0;
}
