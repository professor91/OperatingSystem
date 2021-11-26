// First, Best, Worst Fit

#include <iostream>

void firstFit(int blockSize[], int m, int processSize[], int n){
    std:: cout << "\n---------------  FirstFit  --------------\n"
                << std:: endl;
    
    int allocation[n];

    for (int i= 0; i< n; i++){
        allocation[i] = -1;
    }

    for (int i= 0; i< n; i++){
        for (int j= 0; j< m; j++){
            if (blockSize[j] >= processSize[i]){
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    std:: cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i= 0; i< n; i++){
        std:: cout << " " << i + 1 << "\t\t"
                    << processSize[i] << "\t\t";
        if (allocation[i] != -1){
            std:: cout << allocation[i] + 1;
        }
        else{
            std:: cout << "Not Allocated";
        }
        std:: cout << std:: endl;
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n){
    std:: cout << "\n---------------  BestFit  --------------\n"
                << std:: endl;
    
    int allocation[n];

    for (int i= 0; i< n; i++){
        allocation[i] = -1;
    }

    for (int i= 0; i< n; i++){
        int bestIdx = -1;
        for (int j= 0; j< m; j++){
            if (blockSize[j] >= processSize[i]){

                if (bestIdx == -1){
                    bestIdx = j;
                }
                else if (blockSize[bestIdx] > blockSize[j]){
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1){
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    std:: cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i= 0; i< n; i++){
        std:: cout << " " << i + 1 << "\t\t"
                    << processSize[i] << "\t\t";
        
        if (allocation[i] != -1){
            std:: cout << allocation[i] + 1;
        }
        else{
            std:: cout << "Not Allocated";
        }
        std:: cout << std:: endl;
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n){
    std:: cout << "\n---------------  WorstFit  --------------\n"
                << std:: endl;
    
    int allocation[n];

    for (int i= 0; i< n; i++){
        allocation[i] = -1;
    }

    for (int i= 0; i< n; i++){
        int wstIdx = -1;
        for (int j= 0; j< m; j++){

            if (blockSize[j] >= processSize[i]){

                if (wstIdx == -1){
                    wstIdx = j;
                }
                else if (blockSize[wstIdx] < blockSize[j]){
                    wstIdx = j;
                }
            }
        }

        if (wstIdx != -1){
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
    }

    std:: cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i= 0; i< n; i++){
        std:: cout << " " << i + 1 << "\t\t"
                    << processSize[i] << "\t\t";
        
        if (allocation[i] != -1){
            std:: cout << allocation[i] + 1;
        }
        else{
            std:: cout << "Not Allocated";
        }
        std:: cout << std:: endl;
    }
}

int main(){
    int *blockSize, *processSize, blocks, n;
    
    std:: cout << "Enter the number of blocks in the memory: ";
    std:: cin >> blocks;

    blockSize = new int[blocks];
    
    for (int i= 0; i< blocks; i++){
        std:: cout << "Enter size of block " << i + 1 << ": ";
        std:: cin >> blockSize[i];
    }

    std:: cout << "\nEnter the number of Processes: ";
    std:: cin >> n;

    processSize = new int[n];
    
    for (int i= 0; i< n; i++){
        std:: cout << "Enter size of P[" << i + 1 << "]: ";
        std:: cin >> processSize[i];
    }

    int temp_blockSize[blocks];
    int temp_processSize[n];
    int temp1_blockSize[blocks];
    int temp1_processSize[n];
    
    for (int i = 0; i < blocks; i++){
        temp_blockSize[i] = blockSize[i];
    }
    for (int i = 0; i < n; i++){
        temp_processSize[i] = processSize[i];
    }
    for (int i = 0; i < blocks; i++){
        temp1_blockSize[i] = blockSize[i];
    }
    for (int i = 0; i < n; i++){
        temp1_processSize[i] = processSize[i];
    }

    firstFit(temp_blockSize, blocks, temp_processSize, n);
    
    std:: cout << std:: endl << std:: endl;
    
    bestFit(temp1_blockSize, blocks, temp1_processSize, n);
    
    std:: cout << std:: endl << std:: endl;

    worstFit(blockSize, blocks, processSize, n);

return 0;
}