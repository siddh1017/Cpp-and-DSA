#include <iostream>
#include <vector>
using namespace std;

void input (vector<int> &vec, int size){
    int ele;
    cout << "Enter the elements: ";
    for (int i=0; i< size; i++){
        cin >> ele;
        vec.push_back(ele);
    }
}

void print (vector<int> vec){
    for (auto x : vec)
        cout << x << " ";
    cout << endl;
}

int maximum(int x, int y){
    if (x>y) 
        return x;
    else
        return y;
}

// BRUTE FORE METHOD 1 ------------->
int algorithm1 (vector<int > vec){
    int sum = 0;
    int max INT_MIN;
    for (int size = 1; size < vec.size(); size++){
        for (int index = 0 ; index < vec.size(); index++){
            int sum = 0;
            for (int ele = index ; ele <= size ; ele++){
                sum += vec.at(ele);
            }
            max = maximum (max, sum);
        }
    }
    return max;
}


// BRUTE FORCE METHOD 2 ------------->
int algorithm2 (vector<int > vec){
    int sum = 0;
    int max = INT_MIN;
    for (int i=0 ; i< vec.size(); i++){
        sum = 0;
        for (int j=i ; j<vec.size(); j++){
            sum = sum  + vec[j];
            max = maximum(sum, max);
        }
    }
    return max;
}

int all_negative(vector<int> vec){
    int flag = 0;
    for (int i=0; i<vec.size(); i++){
        if (vec[i] >= 0){
            flag = 1;
        }
    }
    return flag;
}

// KADEN's ALGORITHM
int algorithm3(vector<int> vec){
    int sum = 0; int max = INT_MIN;
    if (all_negative(vec)){
        for (int i=0; i<vec.size(); i++){
            sum = sum + vec[i];
            if (sum < 0){
                sum = 0;
            }
            if (sum > max){
                max = sum;
            }
        }
        return max;
    }
    else{
        for (int i=0; i<vec.size(); i++){
            if (vec[i] > max){
                max = vec[i];
            }
        }
        return max;
    }
}

int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    
    vector <int> vec;
    input(vec, n);

    cout << "Using the BRUTE FORCE algorithm 1" << endl;
    cout << algorithm1(vec) << endl;

    cout << "Using the BRUTE FORCE algorithm 2" << endl;
    cout << algorithm2(vec) << endl;

    cout << "Using the KADEN's algorithm" << endl; 
    cout << algorithm3(vec) << endl;

    return 0;
}