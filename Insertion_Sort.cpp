#include <iostream>
#include <vector>
using namespace std;

void Insertion_Sort(vector <int> &v1){
    int length = v1.size();
    for (int i = 1; i< length; i++){
        int key = v1[i];
        int j = i-1;
        while(j>=0 && v1[j]>key){
            v1[j+1] = v1[j];
            j--;
        }
        v1[j+1] = key;
    } 
}



int main(){
    vector<int> vec1{3,44,5,69,87,1,0,66,5,89,99,151,25,15,13,11,66,88,99};
    Insertion_Sort(vec1);
    for (int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << ' ';
    }
    cout << endl;
    return 0;
}