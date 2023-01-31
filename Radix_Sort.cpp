#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void Radix_Sort(vector<int> &a){
    int length = a.size();
    if(length < 2){
        return;
    }
    int max_value = 0;
    for (int i = 0; i < length; i++){
        max_value = max(max_value,a[i]);
    }
    int max_digits = log10(max_value) + 1;
    int dividedNum = 1;
    int mod = 10;
    vector <int> Bucket[10];
    for (int i = 0; i < max_digits; i++, dividedNum *= 10, mod *= 10){
        for (int j = 0; j < length; j++){
            int num = (a[j]%mod) / dividedNum;
            Bucket[num].push_back(a[j]);
        }
        int index = 0;
        for (int j = 0; j < 10; j++){
            int size_1 = Bucket[j].size();
            for(int k = 0; k < size_1; k++){
                a[index++] = Bucket[j][k];
            }
            Bucket[j].clear();
        }
    }

}


int main(){
    vector<int> vec1{3,44,5,69,87,1,0,66,5,89,99,151,25,15,13,11,66,88,99};
    Radix_Sort(vec1);
    for (int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << ' ';
    }
    cout << endl;
    return 0;
}