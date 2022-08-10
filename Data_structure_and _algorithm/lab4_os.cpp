#include <iostream>
using namespace std;

void algorithm(float time[]){
    float waitingTime[6];
    waitingTime[0] = 0;

    for (int i=0; i<6; i++){
        waitingTime[i] = time[i-1] + waitingTime[i-1];
    }

    float turnAroundTime[6];
    for (int i=0; i<6; i++){
        turnAroundTime[i] = time[i-1] + waitingTime[i-1];
    }

    float totalWaitingTime = 0, totalTurnAroundTime = 0;

    for (int i=0; i<6; i++){
        totalWaitingTime = totalWaitingTime + waitingTime[i];
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
    }

    cout << "Average Waiting Time: " << totalWaitingTime/6 << endl;
    cout << "Average Turn Around Time: " << totalTurnAroundTime/6 << endl;

} 


int main(){

    char process[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    float alpha = 0.5;

    float expectedBrust[6];
    expectedBrust[0] = 10; // metioned in question
    float brustTime[6] = {20, 10 ,10, 5, 5, 10}; // given

    for (int i=0; i<5; i++){
        expectedBrust[i + 1] = (alpha*brustTime[i]) + ((1- alpha)*expectedBrust[i]);
        cout << "The Expected brust time of " << process[i + 1] << " is: " << expectedBrust[i  + 1] << endl;
    }

    cout << "Applying the FCFS:" << endl;
    algorithm(brustTime);

    for (int i=0; i<6 ;i++){
        for (int j=i+1; j<6; j++){
            if (expectedBrust[i] > expectedBrust[j]){
                float temp = expectedBrust[i];
                expectedBrust[i] = expectedBrust[j];
                expectedBrust[j] = temp;
            }
        } 
    }

    cout << "Applying the SJF:" << endl;
    algorithm(expectedBrust);
    return 0;
}