// First come first serve
// 6 14 12 4 8

#include<iostream>

int main(){
    int total_process;

    std:: cout << "Enter total number of processes: ";
    std:: cin >> total_process;
    
    int burst_time[total_process],wait_time[total_process],
    turn_around_time[total_process],average_wait=0,
    average_turn_around=0;
    
    std:: cout << "Enter Burst Time for each  process" << std:: endl;
    for(int i= 0; i< total_process; i++){
        std:: cout << "P[" << i+1 << "]: ";
        std:: cin >> burst_time[i];
    }

    // wait time for first process will be zero
    wait_time[0]= 0;
    for(int i= 1; i<total_process; i++){
        wait_time[i]= 0;
        for(int j= 0; j< i; j++){
            wait_time[i] += burst_time[j];
        }
    }
    
    std:: cout << "Process\t\tBurst Time\t\tWaiting Time\t\tTurn Around Time" << std:: endl;
    std:: cout << "============================================================================" << std:: endl;

    // calculating Turn Around Time
    for(int i= 0; i<total_process; i++){
        turn_around_time[i] = burst_time[i] + wait_time[i];
        average_wait += wait_time[i];
        average_turn_around += turn_around_time[i];

        std:: cout  << "\t\b\b\b\b\b" << i+1 << "\t\t" << burst_time[i] << "\t\t\t"
                    << wait_time[i] << "\t\t\t" << turn_around_time[i] << "\n";
    }
    std:: cout << "============================================================================" << std:: endl;

    std:: cout << "\nAverage Wait Time: " << ((float)average_wait/total_process) << std:: endl;
    std:: cout << "Average Turn Around Time: " << ((float)average_turn_around/total_process) << std:: endl;

return 0;
}
