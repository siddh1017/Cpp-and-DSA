#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// function to check whether the requested page is already present or not
bool check_page(int filled, int page, int main_memory[]){
    for (int i=0; i<= filled; i++){
        if (main_memory[i] == page){
            return true;
        }
    }
    return false;
}


// fifo algorithm 
void fifo_algo(vector<int> page, int mainSize){
    int main_memory[mainSize];
    int pointer = 0, back = -1;

    int hit = 0, fault = 0;

    for (int i=0 ; i<page.size(); i++){
        if (check_page(i%mainSize, page[i], main_memory)){  // checking if hit occurrs
            hit ++;     
        }
        else {
            if (back < mainSize - 1){  // if the main_memory is not full 
                back += 1;
                main_memory[back] = page[i];  // just enter the process in empty space
            }
            else if (back >= mainSize - 1){  // if the main_memory is full 
                main_memory[pointer] = page[i];  // replace it with first enterd page
                pointer = (pointer + 1)%mainSize;
            }
            fault++; 
        }
    } 
    cout << "Elemnts in Main Memory(After last page request): ";
    for (int i = 0; i < mainSize; i++){
        cout << main_memory[i] << " ";
    }
    cout << endl << "hit: " << hit << " " << "fault: " << fault;
}


int find_replace_index (vector<int> vec, int memory[], int index, int mainSize){
    
    vector <int> indexs;
    for (int i = 0; i < mainSize; i++){
        for (int j = index; j >= 0; j++){
            if (memory[i] == vec[j]){   // finding the when the last the page[i] used 
                indexs.push_back(j);
                break;   // once found most recent one break
            }
        }
    }
    sort(indexs.begin(), indexs.end());  // sorting it in asceinding order to get least recently used page
    return indexs.at(0);   // returning the index with of least recently used pade
}

void LRU_algo (vector<int> page, int mainSize){
    int main_memory[mainSize];
    int hit = 0, fault = 0;

    for (int i = 0; i < page.size(); i++){
        if (check_page(i%mainSize, page[i], main_memory)){  // hit is occurred 
            cout << "hit occured for page: " << page[i] << endl;
            hit ++;     
        }
        else{
            if (fault < mainSize){  // checking if the main_memory is full or not 
                main_memory[fault] = page[i];
            }
            else{
                int index = find_replace_index(page, main_memory, i, mainSize);
                main_memory[index] = page[i];
            }
            cout << "fault occured for page: " << page[i] << endl;
            fault++;
        }
    }
    cout << "Elemnts in Main Memory(After last page request): ";
    for (int i = 0; i < mainSize; i++){
        cout << main_memory[i] << " ";
    }
    cout << endl << "hit: " << hit << " " << "fault: " << fault;
}

int main()
{
    int no_of_pages;
    cout << "Enter the no. of process: ";
    cin >> no_of_pages;

    vector<int> page; int ele;
    cout << "Enter the elements: " << endl;
    for (int i=0; i<no_of_pages; i++){
        cin >> ele;
        page.push_back(ele);
    }

    int mainSize;
    cout << "Enter the main memory size: ";
    cin >> mainSize;

    int even = 0;
    for (auto x : page){
        if (x%2 == 0)
        {
            even ++;
        }
    }

    if (even > no_of_pages/2 && mainSize%2 == 0){
        fifo_algo(page, mainSize);
    }
    else{
        LRU_algo(page, mainSize);        
    }
    return 0;
}