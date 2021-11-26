//WAP to implement Round Robin

#include <iostream>
#include <iomanip>

void printTable(int processes[], int at[], int bt[], int n){
	std:: cout << "\n" << "Process\t\tArrival Time\t\tBurst Time";
	std:: cout << "\n" << std:: setfill('=') << std:: setw(60);
    
    for (int i= 0; i< n; i++){
        std:: cout  << "\n  P" << i+1 
                    << "\t\t    " << at[i]
                    << "\t\t\t    " << bt[i];
    }
	std:: cout << std:: setfill('=') << std:: setw(58) << std:: endl;
}

double average(int *arr, int size){
    double avg = 0.0;
    
    for (int i = 0; i < size; i++){
        avg += arr[i];
    }
    avg = avg / size;
return avg;
}

void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[], int quantum){
    int rem_bt[n];

    for (int i = 0; i < n; i++){
        rem_bt[i] = bt[i];
    }

    int t = 0;

    while (1){
        bool finish = true;
        for (int i= 0; i< n; i++){
            if (rem_bt[i] > 0){
                finish = false;

                if (rem_bt[i] > quantum){
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else{
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (finish == true){
            break;
        }
    }

    for (int i= 0; i< n; i++){
        wt[i] -= at[i];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
    for (int i= 0; i< n; i++){
        tat[i] = bt[i] + wt[i];
    }
}

void printOutput(int wt[], int ta[], int n){
	std:: cout << "\n\n" << "Process\t\tWait Time\t\tTurn Around Time";
	std:: cout << "\n" << std:: setfill('=') << std:: setw(60);
    
    for (int i= 0; i< n; i++){
        std:: cout  << "\n  P" << i+1 
                    << "\t\t    " << wt[i]
                    << "\t\t\t    " << ta[i];
    }
	std:: cout << std:: setfill('=') << std:: setw(60) << std:: endl;

    std:: cout << "\n\nAverage Wait Time=" << average(wt, n) << std:: endl;
    std:: cout << "Average Turn Around Time=" << average(ta, n) << std:: endl;
}

int main(){
    int *processes, n, *bt, *at, *wt, *tat, quan;
    std:: cout << "Enter the number of processes: ";
    std:: cin >> n;

    processes = new int[n];
    bt = new int[n];
    at = new int[n];
    tat = new int[n];
    wt = new int[n];
    
    for (int i= 0; i< n; i++){
        std:: cout << "Enter the Arrival Time of process P" << i + 1 << ": ";
        std:: cin >> at[i];
        std:: cout << "Enter the Burst Time of process P" << i + 1 << ": ";
        std:: cin >> bt[i];
    }

    std:: cout << "\nEnter the quantum: ";
    std:: cin >> quan;

    printTable(processes, at, bt, n);
    findWaitingTime(processes, n, bt, wt, at, quan);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printOutput(wt, tat, n);
    
return 0;
}