#include <iostream>
using namespace std;

int main()
{
    int no_of_process;
    cout << "Enter the no. of process : ";
    cin >> no_of_process;

    int process[no_of_process];

    int instances, value;
    int no_of_resourses;

    cout << "Enter the no. of resources: ";
    cin >> no_of_resourses;

    int resources[no_of_resourses][2];
    for (int i = 0; i < no_of_resourses; i++)
    {
        cout << "Enter the no. of instances : ";
        cin >> instances;
        resources[i][0] = instances;
        cout << "Enter the value : ";
        cin >> value;
        resources[i][1] = value;
    }

    int temp;
    cout << "Enter the initial resorces needed by process:" << endl;
    for (int i = 0; i < no_of_process; i++)
    {
        cout << i << " -> ";
        cin >> temp;
        if (resources[temp][0] <= 0){
            cout << "no more instances available" << endl;
            i--;
        }
        else{
            process[i] = resources[temp][1];
            resources[temp][0]--;
            cout << "resourse allocated" << endl;
        }
    }

    int request_by_process;
    int request_to_resource;
    char option;
    while (option != 'n'){
        cout << "Enter the process to request: ";  // proccess requesting
        cin >> request_by_process;
        cout << "Enter the resorce to be requested: "; // resource requested
        cin >> request_to_resource;
        if (process[request_by_process] > resources[request_by_process][1]){
            // process[request_by_process] = 0; // seting the process value to zero 
            // resources[request_to_resource][0]++;  // freeing the resources 
            cout << "request denied" << endl;
        } 
        else {
            if (resources[request_to_resource][0] < 0){
                cout << "no more instance left for resource";
            }
            else{
                // alocating the new resource for asked process
                process[request_by_process] = resources[request_to_resource][1];  

                // decrementing the available instance of requsted resource 
                resources[request_to_resource][0]--;
                cout << "new resource allocated" << endl;
            }
        }
        cout << "Enter the [y/n]: ";
        cin >> option;
    }

    return 0;
}