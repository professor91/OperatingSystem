//WAP to implement Preemptive priority process scheduling


#include <iostream>
#include <iomanip>
#include <vector>

int *wt, *at, *bt, *p, *ta, *temp_bt, *temp_at, *temp_p, n;
std:: vector<int> v;

int linSearch(int element, int *arr, int size){
    for (int i= 0; i< size; i++){
        if (arr[i] == element){
            return i;
        }
    }
return -1;
}

double average(int *arr, int size){
    double avg = 0.0;

    for (int i = 0; i < size; i++){
        avg += arr[i];
    }
    avg = avg / size;

return avg;
}

int sum(int *arr, int size){
    int sum = 0;

    for (int i = 0; i < n; i++){
        sum += arr[i];
    }

return sum;
}

void input(){
    std:: cout << "Enter the number of processes: ";
    std:: cin >> n;
    
    wt = new int[n];
    at = new int[n];
    bt = new int[n];
    ta = new int[n];
    p = new int[n];
    temp_bt = new int[n];
    temp_at = new int[n];
    temp_p = new int[n];
    
    for (int i= 0; i< n; i++){
        std:: cout << "Enter the Arrival Time of process P" << i + 1 << ": ";
        std:: cin >> at[i];
        std:: cout << "Enter the Burst Time of process P" << i + 1 << ": ";
        std:: cin >> bt[i];
        std:: cout << "Enter the Priority of process P" << i + 1 << ": ";
        std:: cin >> p[i];
    }
    
    for (int i= 0; i< n; i++){
        wt[i] = 0;
        ta[i] = 0;
    }
    for (int i= 0; i< n; i++){
        temp_bt[i] = bt[i];
    }
    for (int i= 0; i< n; i++){
        temp_at[i] = at[i];
    }
    for (int i= 0; i< n; i++){
        temp_p[i] = p[i];
    }
}

void printTable(){
	std:: cout << "\n" << "Process\t\tArrival Time\t\tBurst Time\t\tPriority";
	std:: cout << "\n" << std:: setfill('=') << std:: setw(80);
    for (int i = 0; i < n; i++){
        std:: cout  << "\n  P" << i+1 
                    << "\t\t    " << at[i]
                    << "\t\t\t  " << bt[i]
                    << "\t\t\t  " << p[i];
    }
	std:: cout << std:: setfill('=') << std:: setw(78) << std:: endl;
}

void runProcess(int time){
    int minPriority= v[0], temp= 0;
    
    for (int i= 0; i< v.size(); i++){
        if (v[i] < minPriority){
            minPriority = v[i];
            temp = i;
        }
    }
    
    int pos = linSearch(minPriority, temp_p, n);
    v[temp]--;
    temp_bt[pos]--;
    
    if (temp_bt[pos] == 0){
        ta[pos] = time - at[pos];
        wt[pos] = ta[pos] - bt[pos];
        temp_bt[pos] = -1;
        temp_p[pos] = -1;
    }
}

void pushProcess(int minTime){
    for (int i= 0; i< n; i++){
        if (temp_at[i] < minTime){
            if (temp_bt[i] > 0){
                v.push_back(temp_p[i]);
            }
        }
    }
}

void schedule(){
    int totalTime = sum(bt, n);

    for (int time= 1; time<= totalTime; time++){
        pushProcess(time);
        runProcess(time);
        v.clear();
    }
}

void printOutput(){
	std:: cout << "\n\n" << "Process\t\tWait Time\t\tTurn Around Time";
	std:: cout << "\n" << std:: setfill('=') << std:: setw(60);
    for (int i= 0; i< n; i++){
        std:: cout << "\n  P" << i + 1 
                    << "\t\t    " << wt[i]
                    << "\t\t\t    " << ta[i];
    }
	std:: cout << std:: setfill('=') << std:: setw(75) << std:: endl;
    
    std:: cout << "\n\nAverage Wait Time=" << average(wt, n) << std:: endl;
    std:: cout << "Average Turn Around Time=" << average(ta, n) << std:: endl;
}

int main(){

    input();
    printTable();
    schedule();
    printOutput();

return 1;
}