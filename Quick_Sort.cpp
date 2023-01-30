#include <iostream>
#include <vector>
using namespace std;

int Partition (vector <int> &v2, int low, int high){
    int pivot = v2[low];
    while (low < high){
        while (low < high && v2[high] >= pivot){
            high--;
        }
        v2[low] = v2[high];
        while (low < high && v2[low] <= pivot){
            low++;
        }
        v2[high] = v2[low];
    }
    v2[low] = pivot;
    return low;
}


void Quick_Sort(vector <int> &v1, int left, int right){
    if(left < right){
        int pivot = Partition(v1,left,right);
        Quick_Sort(v1,left,pivot-1);
        Quick_Sort(v1,pivot+1,right);
    }
}


int main(){
    vector<int> vec1{3,44,5,69,87,1,0,66,5,89,99,151,25,15,13,11,66,88,99};
    Quick_Sort(vec1,0,vec1.size()-1);
    for (int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << ' ';
    }
    cout << endl;
    return 0;
}