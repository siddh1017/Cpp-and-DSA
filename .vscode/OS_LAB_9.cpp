#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void first_fit(vector<int> partitions, vector<int> process){
    int filled = 0;  // to check whether the process os allocated or not
   
    for (int i=0; i<process.size(); i++)  // iteratiog through all process 
    {
        for (int j=0; j<partitions.size(); j++)
        {
            if (process.at(i) < partitions.at(j))   // checking fo rthe first free available slot
            {
                cout << process.at(i) << " is alloted in slot: " << j << endl;
                partitions.at(j) -= process.at(i);  // decrementing the partition size
                filled ++;
                break;
            }
            else if (j == partitions.size() -1 && filled != i)  // if we reach last partition and still process os not filled 
            {
                cout << "process cannot be alloted" << endl;
                break;
            }
        }
    }
    
    // displaying the updated partition size
    cout << "left size in blocks:-" << endl;
    for (auto x : partitions){
        cout << x << endl;
    }
}

void best_fit(vector<int> partitions, vector<int> process){
   
    int filled = 0;  // to check whether the process os allocated or not
    for (int i=0; i<process.size(); i++)  // iteratiog through all process 
    {
        int slot;   // the min space slot  
        int min = INT_MAX;  // initialing the min availbale space INT_MIX
        for (int j=0; j<partitions.size(); j++)  // Checking for all the partion size
        {
            if (partitions.at(j) > process.at(i))  // Checking for all the partition size is greater than prcess size
            {
                int temp = abs(process.at(i) - partitions.at(j));  // finding absolute differnce, to find smallest size internal fragmnetation
                if (temp < min)
                {
                    min = temp;
                    slot = j;  // allocating largest partition size to slot
                }    
            }
            else if (j == partitions.size() -1 && filled != i)  // if we reach the end of partitions and process didn't get allocated
            {
                cout << "process cannot be alloted" << endl;
                break;
            }
        }
        cout << process.at(i) << "is alloted in slot: " << slot << endl; 
        partitions.at(slot) -= process.at(i);   // decrementing the slot size as it get filled
        filled ++;
    }
}    

void worst_fit(vector<int> partitions, vector<int> process){
    int filled = 0;  // to check whether the process os allocated or not
    for (int i=0; i<process.size(); i++)   // iteratiog through all process 
    {
        int slot; // the max space slot 
        int max = INT_MIN;   // initialing the max availbale space INT_MIN
        for (int j=0; j<partitions.size(); j++)  // Checking for all the partion size
        {
            if (partitions.at(j) > process.at(i))  // if particular partition size is greater than prcess size
            {
                int temp = abs(process.at(i) - partitions.at(j));  // finding absolute differnce, to find largest size internal fragmnetation
                if (temp > max)
                {
                    max = temp;
                    slot = j;  // allocating largest partition size to slot
                }    
            }
            else if (j == partitions.size() -1 && filled != i)  // if we reach the end of partitions and process didn't get allocated
            {
                cout << "process cannot be alloted" << endl;
                break;
            }
        }
        cout << process.at(i) << " is alloted in slot: " << slot << endl;
        partitions.at(slot) -= process.at(i);  // decrementing the slot size as it get filled
        filled ++;
    }
}


int main()
{
    int partitions; int process;
    vector<int> part; vector<int> pro;
    int temp;
    
    cout << "Enter the no. of partions: ";
    cin >> partitions;
    cout << "Enter the block sizes" << endl;
    for (int i=0; i<partitions; i++){  // creating the partitions 
        cin >> temp;
        part.push_back(temp);
    }
   
    cout << "Enter the no. of process: ";
    cin >> process;
    cout << "Enter the process sizes" << endl;
    for (int i=0; i<process; i++){  // creating the process
        cin >> temp;
        pro.push_back(temp);
    }
    
    cout << "First-Fit" << endl;
    first_fit(part, pro);
    cout << "Best-Fit" << endl;
    best_fit(part,pro);
    cout << "Worst-Fit" << endl;
    worst_fit (part, pro);
    return 0;
}