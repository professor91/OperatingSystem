// SRJF Scheduling
// 2 1 8 4 5

#include <iostream>
#include <iomanip>

class Process{
    public:
            int name;
            float arrival_time;
            float burst_time;
            float temp_burst_time;
            float completion_time;
            float waiting_time;
            float turn_around_time;

            // constructor
            Process(){
                arrival_time = burst_time = temp_burst_time = completion_time = waiting_time = turn_around_time = 0;
                name = 0;
            }
};

int main(){
    
    // taking input from user
    int total_process;
    std:: cout << "SRJF Scheduling";
    std:: cout << "\nEnter total number of processes: ";
    std:: cin >> total_process;
    
    if (total_process <= 0){
        return -1;
    }
    std:: cout << std:: endl;

    // initializing the process queue
    Process *processQueue[total_process];
    for (int i= 0; i< total_process; i++){
        processQueue[i] = new Process();
        processQueue[i]->name = i + 1;
        
        std:: cout << "P[" << i + 1 << "]\n";
        
        std:: cout << "Arrival Time : ";
        std:: cin >> processQueue[i]->arrival_time;
        std:: cout << "Burst Time   : ";
        std:: cin >> processQueue[i]->burst_time;
        processQueue[i]->temp_burst_time = processQueue[i]->burst_time;
        std:: cout << std::endl;
    }

    std::cout << std:: right;

    // arranging the Process according to their arrival time
    for (int i= 0; i< total_process-1; i++){
        for (int j= 0; j< total_process-1; j++){
            if (processQueue[j]->arrival_time > processQueue[j + 1]->arrival_time){
                Process *temp = processQueue[j];
                processQueue[j] = processQueue[j + 1];
                processQueue[j + 1] = temp;
            }
        }
    }

    // algorithm
    Process *temp = processQueue[0];
    int flag = true;
    float current_time = processQueue[0]->arrival_time;
    
    while (flag){
        if (temp->arrival_time <= current_time && temp->temp_burst_time > 0){
            if (temp->temp_burst_time <= 1){
                current_time += temp->temp_burst_time;
                temp->temp_burst_time = 0;
                temp->completion_time = current_time;
            }
            else{
                temp->temp_burst_time -= 1;
                current_time += 1;
            }
        }
        else{
            current_time += 1;
        }

        flag = false;

        for (int i= 0; i< total_process; i++){
            if (processQueue[i]->temp_burst_time > 0){
                flag = true;
                temp = processQueue[i];
                break;
            }
        }
        
        // selecting the next smallest process after every 1 unit time
        for (int i= 0; i< total_process; i++){
            if (processQueue[i] != temp){
                if (processQueue[i]->arrival_time <= current_time
                    && processQueue[i]->temp_burst_time > 0
                    && processQueue[i]->temp_burst_time < temp->temp_burst_time){
                    temp = processQueue[i];
                }
            }
        }
    }

    // finding the Completion Time, Waiting Time and Trunaround Time
    float avg_waitingTime = 0;
    float avg_turnaroundTime = 0;
    for (int i= 0; i< total_process; i++){
        processQueue[i]->turn_around_time = processQueue[i]->completion_time - processQueue[i]->arrival_time;
        processQueue[i]->waiting_time = processQueue[i]->turn_around_time - processQueue[i]->burst_time;
        avg_turnaroundTime += processQueue[i]->turn_around_time;
        avg_waitingTime += processQueue[i]->waiting_time;
    }
    
    // rearranging the Process according to their arrival time
    for (int i= 0; i< total_process-1; i++){
        for (int j= 0; j< total_process-1; j++){
            if (processQueue[j]->arrival_time > processQueue[j + 1]->arrival_time){
                Process *temp = processQueue[j];
                processQueue[j] = processQueue[j + 1];
                processQueue[j + 1] = temp;
            }
        }
    }
    
    // displaying the Process Chart
	std:: cout << "\n" << "Process\t\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tWaiting Time\t\tTurn Around Time";
	std:: cout << "\n" << std:: setfill('=') << std:: setw(140);
    for (int i= 0; i< total_process; i++){    
        std:: cout  << "\n  P" << processQueue[i]->name 
                    << "\t\t    " << processQueue[i]->arrival_time
                    << "\t\t\t   " << processQueue[i]->burst_time
                    << "\t\t\t     " << processQueue[i]->completion_time
                    << "\t\t\t     " << processQueue[i]->waiting_time
                    << "\t\t\t     " << processQueue[i]->turn_around_time;
    }
	std:: cout << std:: setfill('=') << std:: setw(160) << std:: endl;

    std:: cout << "\n\nAverage Waiting Time: " << avg_waitingTime / total_process << std:: endl;
    std:: cout << "Average Turnaround Time: " << avg_turnaroundTime / total_process << std:: endl;

    return 0;
}
