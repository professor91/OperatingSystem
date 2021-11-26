// WAP to implement SJF process scheduling
// 0 0 6 8 10 
// 6 14 12 4 8

#include <iostream>
#include <iomanip>
#include <vector>

int *wt,*at,*bt,*ta,*temp_bt,*temp_at,n;
std:: vector<int> v;

int linSearch(int element, int *arr, int size){
	for(int i= 0; i< size; i++){
		if(arr[i] == element)
			return i;
	}

return -1;
}

double average(int *arr, int size){
	double avg= 0.0;
	for(int i= 0; i< size; i++){
		avg+= arr[i];
    }
	avg= avg/size;

return avg;
}

void input(){
	std:: cout << "SJF scheduling";
	std:: cout<< "\nEnter the number of processes: ";
	std:: cin>> n;
	wt= new int[n];
	at= new int[n];
	bt= new int[n];
	ta= new int[n];
	temp_bt= new int[n];
	temp_at= new int[n];
	
    for(int i= 0; i< n; i++){
		std:: cout<< "Enter the Arrival Time of process P" << i+1 << ": ";
		std:: cin>> at[i];
		std:: cout<< "Enter the Burst Time of process P" << i+1 <<": ";
		std:: cin>> bt[i];
	}
	for(int i= 0; i< n; i++){
		temp_bt[i]= bt[i];
    }
	for(int i= 0; i< n; i++){
		temp_at[i]= at[i];
    }
}

void printTable(){
	std:: cout<< "\n" << "Process\t\tArrival Time\t\tBurst Time";
	std:: cout<< "\n" << "===================================================";
	for(int i= 0; i< n; i++){
		std:: cout<< "\n  P" << i+1 << "\t\t    " << at[i] << "\t\t\t   " << bt[i];
	}
	std:: cout<< "\n" << "===================================================" << std:: endl;
}

int toBeScheduled(){
	int minTime= v[0],temp= 0;

	for(int i= 0; i< v.size(); i++){
		if(v[i] < minTime){
			minTime= v[i];
			temp= i;
        }
	}
	v.erase(temp + v.begin());

	int minPos= linSearch(minTime, temp_bt, n);
	temp_bt[minPos]= -1;

return minPos;
}

int minArrivalTime(){
	int minPos;
	for(int i= 0; i< n; i++){
		if(temp_at[i] != -1){
			minPos= i;
			break;
		}
    }

	for(int i= 0; i< n; i++){
		if(temp_at[i] != -1){
			if(temp_at[i] < temp_at[minPos])
				minPos= i;
			else if(temp_at[i] == temp_at[minPos])
				minPos= (i< minPos) ? i : minPos;
		}
	}
return minPos;
}

void schedule(){
	int count= 0, time= 0, arrivalTime= temp_at[minArrivalTime()];

	while(count< n){
        
		if(v.size()< n){
            
			for(int i= 0; i< n; i++){
				if(temp_at[i] != -1){
					if(temp_at[i] <= arrivalTime){
						v.push_back(bt[i]);
						temp_at[i]= -1;
					}
				}
			}
		}
		int pos= toBeScheduled();
        
		time += bt[pos];
		ta[pos]= time-at[pos];
		arrivalTime= ta[pos];
		wt[pos]= ta[pos] - bt[pos];
		at[pos]= -1;
	
    	count++;
	}
}

void printOutput(){
	std:: cout<< "\n" << "Process\t\tArrival Time\t\tBurst Time";
	std:: cout<< "\n" << "===================================================";
	for(int i= 0; i< n; i++){
		std:: cout<< "\n  P" << i+1 << "\t\t    " << wt[i] << "\t\t\t   " << ta[i];
	}
	std:: cout<< "\n" << "===================================================" << std:: endl;

	std:: cout<< "\nAverage Wait Time: " << average(wt,n) << std:: endl;
	std:: cout<< "Average Turn Around Time: " << average(ta,n) << std:: endl;
}

int main(){

	input();
	printTable();
	schedule();
	printOutput();

return 0;
}